// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.tghu.navi.app.cluster;

import de.audi.tghu.navi.app.map.enums.ESetupOption;

class MapClusterServiceProxy$7 implements Runnable {
   MapClusterServiceProxy$7(MapClusterServiceProxy var1, ESetupOption var2) {
      this.this$0 = var1;
      this.val$eSetupOption = var2;
   }

   public void run() {
      MapClusterServiceProxy.access$000(this.this$0).log(10000000, "NaviClusterServiceProxy#onSelectedStaticItem() - item: %1", this.val$eSetupOption);
      MapClusterServiceProxy.access$100(this.this$0).changeMapContentStaticItemSelection(this.val$eSetupOption);
   }
}
