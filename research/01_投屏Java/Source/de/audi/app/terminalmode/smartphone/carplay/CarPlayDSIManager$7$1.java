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

class CarPlayDSIManager$7$1 extends RequestModeChangeAudio {
   CarPlayDSIManager$7$1(CarPlayDSIManager$7 var1, LogChannel var2, IContext var3, IDSISmartphoneManager var4, ITMState var5, IStateHandler var6, ITMState var7) {
      super(var2, var3, var4, var5, var6);
      this.this$1 = var1;
      this.val$iTMState = var7;
   }

   public void execute() {
      this.logger.log(1000000, "### DSI ### [%1.execute]", "CarPlayDSIManager");
      if (!this.val$iTMState.isResourceOwnerMainUnit(Resource.AUDIO_MEDIA)) {
         CarPlayDSIManager.access$000(CarPlayDSIManager$7.access$3500(this.this$1))
            .requestModeChange(
               new IDSIAppState[0],
               new IDSIResource[]{
                  new Builder()
                     .setpOwner(2)
                     .setpResourceId(2)
                     .setDsiResourceId(1)
                     .setDsiResourceOwner(2)
                     .setDsiTakeType(4)
                     .setDsiBorrowConstraint(0)
                     .setDsiTakeConstraint(0)
                     .setDsiUnborrowConstraint(0)
                     .setDsiTransferPriority(0)
                     .build()
               },
               "audio play after mute"
            );
      }

      ITMState var1 = this.getStateHandler().getCurrentState();
      var1.setStateForResource(Resource.AUDIO_MEDIA, ResourceState.NORMAL);
      this.getStateHandler().updateState(var1);
      this.finish();
   }
}
