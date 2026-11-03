// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.app.terminalmode.IContext;
import de.audi.app.terminalmode.dsi.IDSIAppState;
import de.audi.app.terminalmode.dsi.IDSIResource;
import de.audi.app.terminalmode.dsi.DSIResource.Builder;
import de.audi.app.terminalmode.smartphone.IDSISmartphoneManager;
import de.audi.app.terminalmode.statemachine.IStateHandler;
import de.audi.app.terminalmode.statemachine.ITMState;
import de.audi.app.terminalmode.statemachine.Resource;
import de.audi.app.terminalmode.statemachine.ResourceState;
import de.audi.atip.log.LogChannel;

class CarPlayDSIManager$6$2 extends RequestModeChangeAudio {
   CarPlayDSIManager$6$2(CarPlayDSIManager$6 var1, LogChannel var2, IContext var3, IDSISmartphoneManager var4, ITMState var5, IStateHandler var6, ITMState var7) {
      super(var2, var3, var4, var5, var6);
      this.this$1 = var1;
      this.val$iTMState = var7;
   }

   public void execute() {
      this.logger.log(1000000, "### DSI ### [%1.execute]", "CarPlayDSIManager");
      if (!this.val$iTMState.isResourceOwnerMainUnit(Resource.AUDIO_MEDIA)) {
         CarPlayDSIManager.access$000(CarPlayDSIManager$6.access$2900(this.this$1))
            .requestModeChange(
               new IDSIAppState[0],
               new IDSIResource[]{
                  new Builder()
                     .setpOwner(2)
                     .setpResourceId(2)
                     .setDsiResourceId(1)
                     .setDsiResourceOwner(2)
                     .setDsiTakeType(4)
                     .setDsiTransferPriority(0)
                     .setDsiTakeConstraint(0)
                     .setDsiBorrowConstraint(0)
                     .setDsiUnborrowConstraint(0)
                     .build()
               },
               "audio play"
            );
      }

      CarPlayDSIManager.access$1900(CarPlayDSIManager$6.access$2900(this.this$1), ResourceState.NORMAL);
      this.finish();
   }
}
