// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.tghu.navi.app.cluster;

import de.audi.tghu.navi.app.map.mapcontent.MapContentList;

class MapClusterServiceProxy$4 implements Runnable {
   MapClusterServiceProxy$4(MapClusterServiceProxy var1, MapContentList var2) {
      this.this$0 = var1;
      this.val$mapContentList = var2;
   }

   public void run() {
      MapClusterServiceProxy.access$000(this.this$0).log(10000000, "NaviClusterServiceProxy#onSelectedListItem() - listType: %1", this.val$mapContentList.ID);
      MapClusterServiceProxy.access$100(this.this$0).changeMapContentListItemSelection(this.val$mapContentList);
   }
}
