// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.tghu.navi.app.cluster;

class MapClusterServiceProxy$11 implements Runnable {
   MapClusterServiceProxy$11(MapClusterServiceProxy var1) {
      this.this$0 = var1;
   }

   public void run() {
      MapClusterServiceProxy.access$000(this.this$0).log(10000000, "NaviClusterServiceProxy#activateAndStoreSetup() ");
      if (MapClusterServiceProxy.access$100(this.this$0) == null) {
         MapClusterServiceProxy.access$000(this.this$0).log(10000, "NaviClusterServiceProxy#activateAndStoreSetup() ");
      } else {
         MapClusterServiceProxy.access$100(this.this$0).resumeSetupAndStore();
      }
   }
}
