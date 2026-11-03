// Artifact label: 2026-10-24. Universal test adaptation prepared 2026-11-04.
// Offline ASM transformation only; no OEM/vehicle class is executed.
import java.io.*;
import java.nio.file.*;
import java.util.*;
import java.util.jar.*;
import java.util.zip.*;
import org.objectweb.asm.*;
import org.objectweb.asm.tree.*;
import org.objectweb.asm.tree.analysis.*;

public final class UniversalVariant {
    static final String BIND="de/audi/app/terminalmode/smartphone/carplay/DeviceBinding";
    static final String CP="de/audi/app/terminalmode/smartphone/carplay/CarPlayClusterIntegration";
    public static void main(String[] args)throws Exception {
        if(args.length!=2)throw new IllegalArgumentException("input-no-card.jar output.jar");
        Map<String,byte[]> before=new TreeMap<>(),after=new TreeMap<>();
        try(JarFile j=new JarFile(args[0])) {
            for(JarEntry e:Collections.list(j.entries()))if(!e.isDirectory())
                before.put(e.getName(),j.getInputStream(e).readAllBytes());
        }
        for(var entry:before.entrySet()) {
            String n=entry.getKey();byte[] b=entry.getValue();
            if(n.matches(java.util.regex.Pattern.quote(BIND)+"[ABCD]\\.class"))continue;
            if(n.equals(BIND+".class")) {
                ClassNode c=new ClassNode();new ClassReader(b).accept(c,0);
                c.fields.clear();c.methods.removeIf(m->!m.name.equals("<init>")&&!m.name.equals("isAuthorized"));
                MethodNode m=c.methods.stream().filter(x->x.name.equals("isAuthorized")&&x.desc.equals("()Z")).findFirst().orElseThrow();
                m.instructions.clear();m.tryCatchBlocks.clear();m.localVariables=null;
                m.visibleLocalVariableAnnotations=null;m.invisibleLocalVariableAnnotations=null;
                m.instructions.add(new InsnNode(Opcodes.ICONST_1));m.instructions.add(new InsnNode(Opcodes.IRETURN));
                m.maxStack=1;m.maxLocals=0;
                ClassWriter w=new ClassWriter(0);c.accept(w);b=w.toByteArray();
            }
            after.put(n,b);
        }
        if(before.size()-after.size()!=4)throw new AssertionError("Exactly four binding fragments must be removed");
        int classes=0,methods=0,same=0;
        for(var entry:after.entrySet())if(entry.getKey().endsWith(".class")) {
            String n=entry.getKey();byte[] b=entry.getValue();classes++;
            ClassNode c=new ClassNode();new ClassReader(b).accept(c,0);
            if(n.equals(CP+"$10.class")||n.equals(CP+"$11.class"))throw new AssertionError("Card class present");
            for(MethodNode m:c.methods)if((m.access&(Opcodes.ACC_ABSTRACT|Opcodes.ACC_NATIVE))==0) {
                new Analyzer<BasicValue>(new BasicVerifier()).analyze(c.name,m);methods++;
            }
            if(!n.equals(BIND+".class")) {
                if(!Arrays.equals(before.get(n),b))throw new AssertionError("Non-binding class changed: "+n);
                same++;
            } else {
                String bytes=new String(b,java.nio.charset.StandardCharsets.ISO_8859_1);
                for(String s:List.of("FAZIT","/dev/nvsku","MessageDigest","DeviceBindingA","DeviceBindingB","DeviceBindingC","DeviceBindingD"))
                    if(bytes.contains(s))throw new AssertionError("Binding input remains: "+s);
            }
        }
        // Every navigation/mapping/display/filter method resides in byte-identical
        // non-binding classes. The existing no-card composition filter is retained.
        try(ZipOutputStream z=new ZipOutputStream(Files.newOutputStream(Path.of(args[1])))) {
            for(var entry:after.entrySet()) {
                ZipEntry e=new ZipEntry(entry.getKey());e.setTimeLocal(java.time.LocalDateTime.of(2026,10,24,0,0));
                z.putNextEntry(e);z.write(entry.getValue());z.closeEntry();
            }
        }
        byte[] stub=after.get(BIND+".class");
        Class<?> binding=new ClassLoader(null){Class<?> go(){return defineClass(BIND.replace('/','.'),stub,0,stub.length);}}.go();
        var authorized=binding.getDeclaredMethod("isAuthorized");authorized.setAccessible(true);
        for(int i=0;i<100;i++)if(!Boolean.TRUE.equals(authorized.invoke(null)))throw new AssertionError("Universal gate");
        System.out.println("{\"classes\":"+classes+",\"verified_methods\":"+methods+",\"byte_identical_non_binding_classes\":"+same+",\"removed_binding_fragment_classes\":4,\"device_gate_host_calls\":100,\"navigation_and_no_card_classes\":\"UNCHANGED\"}");
    }
}
