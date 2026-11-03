// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.app.terminalmode.statemachine.IRequestor;
import de.audi.app.terminalmode.statemachine.ITMState;
import de.audi.app.terminalmode.statemachine.IStateChangeAction.StateChangeActionOverride;
import de.audi.atip.utils.commandlist2.CommandList;

class CarPlayDSIManager$7 extends StateChangeActionOverride {
   CarPlayDSIManager$7(CarPlayDSIManager var1) {
      this.this$0 = var1;
   }

   public void execute(CommandList var1, ITMState var2, IRequestor var3, long var4) {
      CarPlayDSIManager.access$3200(this.this$0).log(1000000, "[%1.changeState] Audio_Media: Paused_by_mute -> Normal", "CarPlayDSIManager");
      if (IRequestor.MAINUNIT == var3) {
         var1.add(
            new CarPlayDSIManager$7$1(
               this,
               CarPlayDSIManager.access$3300(this.this$0),
               CarPlayDSIManager.access$3400(this.this$0),
               this.this$0,
               var2,
               CarPlayDSIManager.access$1700(this.this$0),
               var2
            )
         );
      }
   }
}
