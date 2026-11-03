// Package-Date: 2026-10-24. Offline validation; QNX/vehicle classes are never loaded.
import java.nio.file.*;
import java.util.*;
import java.util.jar.*;
import java.lang.reflect.*;
import org.objectweb.asm.*;
import org.objectweb.asm.tree.*;
import org.objectweb.asm.tree.analysis.*;
public class VerifyNoCard {
  static String CP="de/audi/app/terminalmode/smartphone/carplay/CarPlayClusterIntegration";
  static String DM="de/eso/hmiservice/display/DisplayManager";
  static Map<String,ClassNode> read(String path)throws Exception {
    Map<String,ClassNode> out=new TreeMap<>();try(JarFile j=new JarFile(path)) {
      for(JarEntry e:Collections.list(j.entries()))if(e.getName().endsWith(".class")) {
        byte[] b=j.getInputStream(e).readAllBytes();ClassNode c=new ClassNode();new ClassReader(b).accept(c,0);out.put(c.name,c);
        for(String s:List.of("rgi_pos.ctl","rgi_plate.ctl","/tmp/carplay_kdk.ready"))if(path.contains("final")&&new String(b,java.nio.charset.StandardCharsets.ISO_8859_1).contains(s))throw new AssertionError("Rendering resource still present: "+s);
      }
    }return out;
  }
  static String logic(MethodNode m) {
    Map<LabelNode,Integer> labels=new IdentityHashMap<>();int pos=0;
    for(AbstractInsnNode n:m.instructions){if(n instanceof LabelNode l)labels.put(l,pos);if(n.getOpcode()>=0)pos++;}
    StringBuilder s=new StringBuilder();
    for(AbstractInsnNode n:m.instructions) {
      if(n.getOpcode()<0)continue;s.append(n.getOpcode()).append(':');
      if(n instanceof MethodInsnNode x)s.append(x.owner).append('.').append(x.name).append(x.desc).append(x.itf);
      else if(n instanceof FieldInsnNode x)s.append(x.owner).append('.').append(x.name).append(x.desc);
      else if(n instanceof VarInsnNode x)s.append(x.var);
      else if(n instanceof IntInsnNode x)s.append(x.operand);
      else if(n instanceof IincInsnNode x)s.append(x.var).append(',').append(x.incr);
      else if(n instanceof TypeInsnNode x)s.append(x.desc);
      else if(n instanceof LdcInsnNode x)s.append(x.cst);
      else if(n instanceof JumpInsnNode x)s.append(labels.get(x.label));
      else if(n instanceof TableSwitchInsnNode x){s.append(x.min).append(',').append(x.max).append(',').append(labels.get(x.dflt));for(LabelNode l:x.labels)s.append(',').append(labels.get(l));}
      else if(n instanceof LookupSwitchInsnNode x){s.append(x.keys).append(',').append(labels.get(x.dflt));for(LabelNode l:x.labels)s.append(',').append(labels.get(l));}
      else if(n instanceof MultiANewArrayInsnNode x)s.append(x.desc).append(',').append(x.dims);
      s.append(';');
    }return s.toString();
  }
  static MethodNode method(ClassNode c,String name){return c.methods.stream().filter(x->x.name.equals(name)).findFirst().orElseThrow();}
  public static void main(String[] args)throws Exception {
    Map<String,ClassNode> old=read(args[0]),now=read(args[1]);int verified=0,same=0,changed=0;
    for(ClassNode c:now.values()) {
      if(c.version!=old.get(c.name).version)throw new AssertionError("Class version changed");
      for(MethodNode m:c.methods) {
        if((m.access&(Opcodes.ACC_ABSTRACT|Opcodes.ACC_NATIVE))==0){new Analyzer<BasicValue>(new BasicVerifier()).analyze(c.name,m);verified++;}
        MethodNode previous=old.get(c.name).methods.stream().filter(x->x.name.equals(m.name)&&x.desc.equals(m.desc)).findFirst().orElse(null);
        if(previous!=null){if(logic(previous).equals(logic(m)))same++;else changed++;}
      }
    }
    if(now.containsKey(CP+"$10")||now.containsKey(CP+"$11"))throw new AssertionError("Card classes still present");
    for(String name:List.of("publishPhoneEta","pushKomoNavInfo","startRouteGuidance","stopRouteGuidance","releaseNavOnPhoneClaim","handleScreenOwnerChange","pollNativeSessionGeneration"))
      if(!logic(method(old.get(CP),name)).equals(logic(method(now.get(CP),name))))throw new AssertionError("Navigation interface modified: "+name);
    MethodNode helper=method(now.get(DM),"withoutPhoneCard");ClassNode hc=new ClassNode();new ClassReader(Files.readAllBytes(Paths.get(args[2]))).accept(hc,0);
    if(!logic(helper).equals(logic(method(hc,"withoutPhoneCard"))))throw new AssertionError("Injected filter mismatch");
    Method f=Class.forName("CardFilter").getDeclaredMethod("withoutPhoneCard",int[].class);f.setAccessible(true);
    int[][] inputs={new int[]{41,33,62,20},new int[]{20,41,33,20,62},new int[]{},new int[]{62},null};
    int[][] expected={new int[]{41,33,62},new int[]{41,33,62},new int[]{},new int[]{62},null};
    for(int i=0;i<inputs.length;i++)if(!Arrays.equals((int[])f.invoke(null,(Object)inputs[i]),expected[i]))throw new AssertionError("Composition test "+i);
    System.out.println("{\"package_date\":\"2026-10-24\",\"classes\":"+now.size()+",\"verified_methods\":"+verified+",\"unchanged_method_bodies\":"+same+",\"changed_existing_methods\":"+changed+",\"navigation_interface_methods\":\"PASS\",\"class_versions\":\"PRESERVED\",\"composition_cases\":5}");
  }
}
