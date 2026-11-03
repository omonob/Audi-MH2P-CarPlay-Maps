// Package-Date: 2026-10-24. Offline bytecode transformation; no vehicle I/O.
import java.nio.file.*;
import java.io.*;
import java.util.*;
import java.util.jar.*;
import org.objectweb.asm.*;
import org.objectweb.asm.tree.*;
import org.objectweb.asm.tree.analysis.*;

public class NoCardPatch implements Opcodes {
  static String CP="de/audi/app/terminalmode/smartphone/carplay/CarPlayClusterIntegration";
  static String DM="de/eso/hmiservice/display/DisplayManager";
  static Set<String> visual=new HashSet<>(Arrays.asList(
    "enterBapRgiPresentation","exitBapRgiPresentation","activateNativeKdkAfterFirstFrame",
    "startKdkFirstFrameHandshake","activateKdkContextForFirstFrame","clearKdkFirstFrameReady",
    "captureKdkStateBeforeCarPlay","restoreKdkStateAfterCarPlay","getClusterKdkHandler",
    "getKdkViewModeKey","getKdkViewMode","applyNativeKdkViewState","restoreNativeKdkViewState",
    "holdNativeKdkViewState","republishKdkHintsOnHmiThread","postKdkModelUpdate",
    "isKomoViewVisible","requestKomoViewVisible","forceKomoViewVisible","driveNativeKdkRgActive",
    "holdNativeKdkRgActive","setClusterRgiVisible"));
  static int changed=0,verified=0,metadataGuard=0;
  static void clear(MethodNode m) {
    m.instructions.clear();m.tryCatchBlocks.clear();
    if(m.localVariables!=null)m.localVariables.clear();
    m.visibleLocalVariableAnnotations=null;m.invisibleLocalVariableAnnotations=null;
  }
  static void stub(MethodNode m) {
    clear(m);Type r=Type.getReturnType(m.desc);
    if(r.getSort()==Type.VOID)m.instructions.add(new InsnNode(RETURN));
    else if(r.getSort()==Type.OBJECT||r.getSort()==Type.ARRAY){m.instructions.add(new InsnNode(ACONST_NULL));m.instructions.add(new InsnNode(ARETURN));}
    else {m.instructions.add(new InsnNode(ICONST_0));m.instructions.add(new InsnNode(IRETURN));}
    changed++;
  }
  static byte[] patch(byte[] bytes) throws Exception {
    ClassNode c=new ClassNode();new ClassReader(bytes).accept(c,0);
    c.innerClasses.removeIf(x->x.name.equals(CP+"$10")||x.name.equals(CP+"$11"));
    if(c.name.equals(CP)) {
      c.fields.removeIf(f->Set.of("KDK_FIRST_FRAME_READY_FILE","DISPLAY_MANAGER_REFRESH_KDK_CONTEXT","DISPLAY_MANAGER_SET_RGI_VISIBLE").contains(f.name));
      for(MethodNode m:c.methods) {
        if(visual.contains(m.name)) {stub(m);continue;}
        // Only remove the presentation gate surrounding the metadata-only Komo publisher.
        // Retain route-active gating and all values/units passed to the existing interface.
        AbstractInsnNode[] a=m.instructions.toArray();
        for(int i=0;i<a.length;i++) {
          if(!(a[i] instanceof FieldInsnNode f)||f.getOpcode()!=GETFIELD||!f.owner.equals(CP)||!f.name.equals("bapRgiPresentationEntered"))continue;
          AbstractInsnNode n=f.getNext();while(n!=null&&n.getOpcode()<0)n=n.getNext();
          if(!(n instanceof JumpInsnNode j)||j.getOpcode()!=IFEQ)continue;
          boolean hasPublisher=false;
          for(AbstractInsnNode k=n.getNext();k!=null&&k!=j.label;k=k.getNext())
            if(k instanceof MethodInsnNode v&&v.owner.equals(CP)&&v.name.equals("pushKomoNavInfo"))hasPublisher=true;
          if(hasPublisher){InsnList l=new InsnList();l.add(new InsnNode(POP));l.add(new InsnNode(ICONST_1));m.instructions.insertBefore(f,l);m.instructions.remove(f);metadataGuard++;changed++;}
        }
      }
    }
    if(c.name.equals(DM)) {
      c.fields.removeIf(f->f.name.startsWith("RGI_")||f.name.equals("CONTEXT_CLUSTER_RGI"));
      for(MethodNode m:c.methods) {
        if(Set.of("applyClusterRgiVisibility","setPlatformKDKVisible","refreshCarPlayKdkContext24","clusterRgiRelocEnabled").contains(m.name)){stub(m);continue;}
        if(m.name.equals("setClusterRgiVisible")) {
          clear(m);m.instructions.add(new VarInsnNode(ILOAD,1));m.instructions.add(new InsnNode(ICONST_1));m.instructions.add(new InsnNode(IXOR));m.instructions.add(new InsnNode(IRETURN));changed++;
        }
        if(m.name.equals("clusterRgiPosition")) {
          clear(m);m.instructions.add(new InsnNode(ICONST_2));m.instructions.add(new IntInsnNode(NEWARRAY,T_INT));m.instructions.add(new InsnNode(ARETURN));changed++;
        }
        if(m.name.equals("clusterMirrorDisplayables")) {
          for(AbstractInsnNode n:m.instructions.toArray())if(n.getOpcode()==ARETURN)m.instructions.insertBefore(n,new MethodInsnNode(INVOKESTATIC,DM,"withoutPhoneCard","([I)[I",false));changed++;
        }
      }
      // Compile a small array filter independently and splice the method into this class.
      byte[] helper=Files.readAllBytes(Paths.get(System.getProperty("helper.class")));
      ClassNode hc=new ClassNode();new ClassReader(helper).accept(hc,0);
      MethodNode filter=hc.methods.stream().filter(m->m.name.equals("withoutPhoneCard")).findFirst().orElseThrow();
      for(AbstractInsnNode n:filter.instructions.toArray())if(n instanceof FrameNode)filter.instructions.remove(n);
      filter.access=ACC_PRIVATE|ACC_STATIC;c.methods.add(filter);
    }
    ClassWriter w=new ClassWriter(ClassWriter.COMPUTE_MAXS);c.accept(w);byte[] out=w.toByteArray();
    ClassNode check=new ClassNode();new ClassReader(out).accept(check,0);
    for(MethodNode m:check.methods)if((m.access&(ACC_ABSTRACT|ACC_NATIVE))==0){new Analyzer<BasicValue>(new BasicVerifier()).analyze(check.name,m);verified++;}
    return out;
  }
  public static void main(String[] args)throws Exception {
    try(JarFile in=new JarFile(args[0]);JarOutputStream out=new JarOutputStream(Files.newOutputStream(Paths.get(args[1])))) {
      Enumeration<JarEntry> es=in.entries();
      while(es.hasMoreElements()){
        JarEntry e=es.nextElement();String n=e.getName();
        if(n.equals(CP+"$10.class")||n.equals(CP+"$11.class"))continue;
        JarEntry ne=new JarEntry(n);ne.setTimeLocal(java.time.LocalDateTime.of(2026,10,24,0,0));out.putNextEntry(ne);
        if(!e.isDirectory()){byte[] b=in.getInputStream(e).readAllBytes();if(n.endsWith(".class"))b=patch(b);out.write(b);}out.closeEntry();
      }
    }
    if(metadataGuard!=1)throw new IllegalStateException("Expected exactly one Komo metadata gate, got "+metadataGuard);
    System.out.println("PATCH changed="+changed+" verified_methods="+verified+" metadata_gate="+metadataGuard);
  }
}
