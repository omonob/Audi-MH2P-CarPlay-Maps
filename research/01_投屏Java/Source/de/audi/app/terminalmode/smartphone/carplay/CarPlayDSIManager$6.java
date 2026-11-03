// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.app.terminalmode.statemachine.IRequestor;
import de.audi.app.terminalmode.statemachine.ITMState;
import de.audi.app.terminalmode.statemachine.IStateChangeAction.StateChangeActionOverride;
import de.audi.atip.utils.commandlist2.CommandList;

class CarPlayDSIManager$6 extends StateChangeActionOverride {
   CarPlayDSIManager$6(CarPlayDSIManager var1) {
      this.this$0 = var1;
   }

   public void execute(CommandList var1, ITMState var2, IRequestor var3, long var4) {
      CarPlayDSIManager.access$2600(this.this$0).log(1000000, "[%1.changeState] Audio_Media: Paused -> Normal", "CarPlayDSIManager");
      if (CarPlayDSIManager.access$1200(this.this$0).isValid() && CarPlayDSIManager.access$1200(this.this$0).getBoolean()) {
         String var6 = "UpdateTMStateOnly";
         var1.add(
            new CarPlayDSIManager$6$1(
               this,
               CarPlayDSIManager.access$2700(this.this$0),
               "UpdateTMStateOnly",
               CarPlayDSIManager.access$2800(this.this$0),
               CarPlayDSIManager.access$1700(this.this$0)
            )
         );
      } else {
         var1.add(
            new CarPlayDSIManager$6$2(
               this,
               CarPlayDSIManager.access$3000(this.this$0),
               CarPlayDSIManager.access$3100(this.this$0),
               this.this$0,
               var2,
               CarPlayDSIManager.access$1700(this.this$0),
               var2
            )
         );
      }
   }
}
