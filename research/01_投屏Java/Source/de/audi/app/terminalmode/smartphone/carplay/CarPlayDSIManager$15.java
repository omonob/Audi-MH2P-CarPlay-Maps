// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.app.terminalmode.statemachine.IRequestor;
import de.audi.app.terminalmode.statemachine.ITMState;
import de.audi.app.terminalmode.statemachine.IStateChangeAction.StateChangeActionHook;
import de.audi.atip.utils.commandlist2.CommandList;

class CarPlayDSIManager$15 extends StateChangeActionHook {
   CarPlayDSIManager$15(CarPlayDSIManager var1) {
      this.this$0 = var1;
   }

   public void execute(CommandList var1, ITMState var2, IRequestor var3, long var4) {
      CarPlayDSIManager.access$5900(this.this$0).log(1000000, "[%1.changeState] speech: mainunit -> device", "CarPlayDSIManager");
      CarPlayDSIManager.access$6100(this.this$0).getNativeSpeechActive().subscribe(new CarPlayDSIManager$15$1(this));
   }
}
