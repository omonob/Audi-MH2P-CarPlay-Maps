// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.tghu.navi.app.cluster;

class MapClusterServiceProxy$10 implements Runnable {
   MapClusterServiceProxy$10(MapClusterServiceProxy var1) {
      this.this$0 = var1;
   }

   public void run() {
      MapClusterServiceProxy.access$000(this.this$0).log(10000000, "NaviClusterServiceProxy#suspendSetup()");
      if (MapClusterServiceProxy.access$100(this.this$0) == null) {
         MapClusterServiceProxy.access$000(this.this$0).log(10000, "NaviClusterServiceProxy#suspendSetup() - mapClusterService is null!!");
      } else {
         MapClusterServiceProxy.access$100(this.this$0).suspendSetup();
      }
   }
}
