// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.app.terminalmode.statemachine.IRequestor;
import de.audi.app.terminalmode.statemachine.ITMState;
import de.audi.app.terminalmode.statemachine.IStateChangeAction.StateChangeActionHook;
import de.audi.atip.utils.commandlist2.CommandList;
import de.audi.atip.utils.reactive.bindings.SPIBoolean;

class CarPlayDSIManager$14 extends StateChangeActionHook {
   CarPlayDSIManager$14(CarPlayDSIManager var1) {
      this.this$0 = var1;
   }

   public void execute(CommandList var1, ITMState var2, IRequestor var3, long var4) {
      CarPlayDSIManager.access$5800(this.this$0).log(1000000, "[%1.changeState] speech: mainunit -> nobody", "CarPlayDSIManager");
      if (var3.is(IRequestor.MAINUNIT)) {
         CarPlayDSIManager.access$1300(this.this$0).getPropertySDSActive().set("CarPlayDSIManager", SPIBoolean.FALSE);
      }
   }
}
