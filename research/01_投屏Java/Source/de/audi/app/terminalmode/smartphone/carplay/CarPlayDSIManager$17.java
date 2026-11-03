// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.app.terminalmode.statemachine.IRequestor;
import de.audi.app.terminalmode.statemachine.ITMState;
import de.audi.app.terminalmode.statemachine.IStateChangeAction.StateChangeActionHook;
import de.audi.atip.utils.commandlist2.CommandList;

class CarPlayDSIManager$17 extends StateChangeActionHook {
   CarPlayDSIManager$17(CarPlayDSIManager var1) {
      this.this$0 = var1;
   }

   public void execute(CommandList var1, ITMState var2, IRequestor var3, long var4) {
      CarPlayDSIManager.access$6400(this.this$0).log(1000000, "[%1.changeState] Navi: Nobody -> MU", "CarPlayDSIManager");
      if (var3.is(IRequestor.MAINUNIT)) {
         var1.add(this.this$0.new RequestModeChangeCarPlay(CarPlayDSIManager.access$6500(this.this$0), var2, CarPlayDSIManager.access$1700(this.this$0)));
      }
   }
}
