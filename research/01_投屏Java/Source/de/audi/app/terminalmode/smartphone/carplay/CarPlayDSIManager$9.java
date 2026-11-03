// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.app.terminalmode.statemachine.IRequestor;
import de.audi.app.terminalmode.statemachine.ITMState;
import de.audi.app.terminalmode.statemachine.IStateChangeAction.StateChangeActionHook;
import de.audi.atip.utils.commandlist2.CommandList;
import de.esolutions.fw.util.commons.Buffer;

class CarPlayDSIManager$9 extends StateChangeActionHook {
   CarPlayDSIManager$9(CarPlayDSIManager var1) {
      this.this$0 = var1;
   }

   public void execute(CommandList var1, ITMState var2, IRequestor var3, long var4) {
      CarPlayDSIManager.access$4000(this.this$0).log(1000000, "[%1.changeState] Screen: MU -> Device", "CarPlayDSIManager");
      Buffer var6 = new Buffer(100);
      var6.append(", popup=");
      var6.append(CarPlayDSIManager.access$600(this.this$0));
      var6.append(", requestor=");
      var6.append(var3.toString());
      var6.append(", spiConnected=");
      var6.append(CarPlayDSIManager.access$4100(this.this$0).isAnySPIConnected());
      var6.append(", sLastmodeStartS=");
      var6.append(CarPlayDSIManager.access$4200(this.this$0));
      var6.append(", configLastmode=");
      var6.append(CarPlayDSIManager.access$4300(this.this$0).getConfiguration().useLastmodehandling());
      if (!CarPlayDSIManager.access$600(this.this$0)
         && (
            !IRequestor.DEVICE.isNot(var3)
               || CarPlayDSIManager.access$4100(this.this$0).isAnySPIConnected()
                  && CarPlayDSIManager.access$4200(this.this$0)
                  && CarPlayDSIManager.access$4400(this.this$0).getConfiguration().useLastmodehandling()
         )) {
         CarPlayDSIManager.access$4700(this.this$0).log(1000000, "[%1.changeState] no update for carplay%2", "CarPlayDSIManager", var6.toString());
         if (IRequestor.DEVICE.isNot(var3) && CarPlayDSIManager.access$4200(this.this$0)) {
            CarPlayDSIManager.access$4202(this.this$0, false);
            CarPlayDSIManager.access$4800(this.this$0).log(1000000, "[%1.changeState] Reseting last mode flag%2", "CarPlayDSIManager", var6.toString());
         }
      } else {
         CarPlayDSIManager.access$4500(this.this$0).log(1000000, "[%1.changeState] update for carplay%2", "CarPlayDSIManager", var6.toString());
         var1.add(this.this$0.new RequestModeChangeCarPlay(CarPlayDSIManager.access$4600(this.this$0), var2, CarPlayDSIManager.access$1700(this.this$0)));
      }
   }
}
