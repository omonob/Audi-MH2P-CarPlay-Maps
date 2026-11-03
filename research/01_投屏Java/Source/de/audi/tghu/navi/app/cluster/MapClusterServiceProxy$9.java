// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.tghu.navi.app.cluster;

class MapClusterServiceProxy$9 implements Runnable {
   MapClusterServiceProxy$9(MapClusterServiceProxy var1, boolean var2) {
      this.this$0 = var1;
      this.val$bl = var2;
   }

   public void run() {
      MapClusterServiceProxy.access$000(this.this$0).log(10000000, "NaviClusterServiceProxy#notifyViewSizeChanged() - isBigStage: %1", this.val$bl);
      if (MapClusterServiceProxy.access$100(this.this$0) == null) {
         MapClusterServiceProxy.access$000(this.this$0).log(10000, "NaviClusterServiceProxy#notifyViewSizeChanged() - mapClusterService is null!!");
      } else {
         MapClusterServiceProxy.access$100(this.this$0).notifyViewSizeChanged(this.val$bl);
      }
   }
}
