// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.tghu.navi.app.cluster;

import de.audi.tghu.navi.app.map.enums.ESetupOption;

class MapClusterServiceProxy$1 implements Runnable {
   MapClusterServiceProxy$1(MapClusterServiceProxy var1, ESetupOption var2, int var3) {
      this.this$0 = var1;
      this.val$eSetupOption = var2;
      this.val$n = var3;
   }

   public void run() {
      MapClusterServiceProxy.access$000(this.this$0)
         .log(10000000, "NaviClusterServiceProxy#setKombiMapSetupOption() - option: %1, optionValue : %2", this.val$eSetupOption, this.val$n);
      MapClusterServiceProxy.access$100(this.this$0).setKombiMapSetupOption(this.val$eSetupOption, this.val$n);
   }
}
