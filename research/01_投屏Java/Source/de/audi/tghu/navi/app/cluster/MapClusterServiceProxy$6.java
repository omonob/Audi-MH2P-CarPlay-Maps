// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.tghu.navi.app.cluster;

import de.audi.tghu.navi.app.map.mapcontent.MapContentList;

class MapClusterServiceProxy$6 implements Runnable {
   MapClusterServiceProxy$6(MapClusterServiceProxy var1, MapContentList var2, boolean var3) {
      this.this$0 = var1;
      this.val$mapContentList = var2;
      this.val$bl = var3;
   }

   public void run() {
      MapClusterServiceProxy.access$000(this.this$0).log(10000000, "NaviClusterServiceProxy#onSelectedAll()");
      MapClusterServiceProxy.access$100(this.this$0).selectAllMapContents(this.val$mapContentList, this.val$bl);
   }
}
