// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.app.terminalmode.TerminalModeUtils;
import de.audi.app.terminalmode.dsi.IDSIAppState;
import de.audi.app.terminalmode.dsi.IDSIResource;
import de.audi.atip.utils.reactive.observables.Observables.Consumer2;

class CarPlayDSIManager$2 implements Consumer2 {
   CarPlayDSIManager$2(CarPlayDSIManager var1) {
      this.this$0 = var1;
   }

   public void accept(Boolean var1, Boolean var2) {
      CarPlayDSIManager.access$100(this.this$0).log(1000000, "[%1.accept] rvc=%2 displayOff=%3", "CarPlayDSIManager", var1, var2);
      if (CarPlayDSIManager.access$200(this.this$0) != null) {
         CarPlayDSIManager.access$200(this.this$0).onDisplayOffChanged(var2);
      }

      if (!var1 && !var2) {
         CarPlayDSIManager.access$372(this.this$0, -2);
      } else {
         CarPlayDSIManager.access$376(this.this$0, 1);
         if (var1 && CarPlayDSIManager.access$400(this.this$0)) {
            CarPlayDSIManager.access$500(this.this$0)
               .log(1000000, "[%1.accept] RVC on special popoup usecase additonal unborrow must be send", "CarPlayDSIManager");
            CarPlayDSIManager.access$000(this.this$0)
               .requestModeChange(new IDSIAppState[0], new IDSIResource[]{TerminalModeUtils.getUnborrowScreen()}, "Screen Setup");
            CarPlayDSIManager.access$602(this.this$0, false);
            CarPlayDSIManager.access$402(this.this$0, false);
         }
      }
   }

   public void accept(Object var1, Object var2) {
      this.accept((Boolean)var1, (Boolean)var2);
   }
}
