// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.tghu.navi.app.cluster;

class MapClusterServiceProxy$8 implements Runnable {
   MapClusterServiceProxy$8(MapClusterServiceProxy var1, int var2) {
      this.this$0 = var1;
      this.val$n = var2;
   }

   public void run() {
      MapClusterServiceProxy.access$000(this.this$0).log(10000000, "NaviClusterServiceProxy#onZoomLevelChanged() - steps: %1", this.val$n);
      MapClusterServiceProxy.access$100(this.this$0).changeZoomLevel(this.val$n);
   }
}
