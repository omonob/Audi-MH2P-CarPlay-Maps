// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.atip.interapp.combi.bap.navi.CombiBAPServiceNavi;
import de.audi.atip.interapp.combi.bap.navi.data.CurrentPositionInfo;
import java.util.TimerTask;

class CarPlayClusterIntegration$13 extends TimerTask {
   CarPlayClusterIntegration$13(CarPlayClusterIntegration var1, CombiBAPServiceNavi var2) {
      this.this$0 = var1;
      this.val$svc = var2;
   }

   public void run() {
      try {
         this.val$svc.updateCurrentPositionInfo(new CurrentPositionInfo(""));
      } catch (Exception var2) {
      }
   }
}
