// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.app.terminalmode.IContext;
import de.audi.app.terminalmode.dsi.IDSIAppState;
import de.audi.app.terminalmode.dsi.IDSIResource;
import de.audi.app.terminalmode.dsi.DSIResource.Builder;
import de.audi.app.terminalmode.smartphone.IDSISmartphoneManager;
import de.audi.app.terminalmode.statemachine.IStateHandler;
import de.audi.app.terminalmode.statemachine.ITMState;
import de.audi.app.terminalmode.statemachine.ResourceState;
import de.audi.atip.log.LogChannel;

class CarPlayDSIManager$4$2 extends RequestModeChangeAudio {
   CarPlayDSIManager$4$2(CarPlayDSIManager$4 var1, LogChannel var2, IContext var3, IDSISmartphoneManager var4, ITMState var5, IStateHandler var6) {
      super(var2, var3, var4, var5, var6);
      this.this$1 = var1;
   }

   public void execute() {
      this.logger.log(1000000, "### DSI ### [%1.execute]", "CarPlayDSIManager");
      CarPlayDSIManager.access$000(CarPlayDSIManager$4.access$1800(this.this$1))
         .requestModeChange(
            new IDSIAppState[0],
            new IDSIResource[]{
               new Builder()
                  .setpOwner(1)
                  .setpResourceId(2)
                  .setDsiResourceId(1)
                  .setDsiResourceOwner(1)
                  .setDsiTakeType(3)
                  .setDsiTransferPriority(1)
                  .setDsiTakeConstraint(0)
                  .setDsiBorrowConstraint(0)
                  .setDsiUnborrowConstraint(2)
                  .build()
            },
            "audio paused"
         );
      CarPlayDSIManager.access$1900(CarPlayDSIManager$4.access$1800(this.this$1), ResourceState.PAUSED);
      this.finish();
   }
}
