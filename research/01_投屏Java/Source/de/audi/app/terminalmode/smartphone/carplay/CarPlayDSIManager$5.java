// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.app.terminalmode.statemachine.IRequestor;
import de.audi.app.terminalmode.statemachine.ITMState;
import de.audi.app.terminalmode.statemachine.Resource;
import de.audi.app.terminalmode.statemachine.ResourceOwner;
import de.audi.app.terminalmode.statemachine.IStateChangeAction.StateChangeActionOverride;
import de.audi.atip.utils.commandlist2.CommandList;

class CarPlayDSIManager$5 extends StateChangeActionOverride {
   CarPlayDSIManager$5(CarPlayDSIManager var1) {
      this.this$0 = var1;
   }

   public void execute(CommandList var1, ITMState var2, IRequestor var3, long var4) {
      CarPlayDSIManager.access$2200(this.this$0).log(1000000, "[%1.changeState] Audio_Media: Normal -> Paused by mute", "CarPlayDSIManager");
      if (!ResourceOwner.DEVICE.is(var2.getOwnerForResource(Resource.AUDIO_PHONE))
         && !ResourceOwner.DEVICE.is(var2.getOwnerForResource(Resource.AUDIO_SPEECH))
         && !ResourceOwner.DEVICE.is(var2.getOwnerForResource(Resource.AUDIO_RINGTONE))) {
         var1.add(
            new CarPlayDSIManager$5$1(
               this,
               CarPlayDSIManager.access$2300(this.this$0),
               CarPlayDSIManager.access$2400(this.this$0),
               this.this$0,
               var2,
               CarPlayDSIManager.access$1700(this.this$0)
            )
         );
      }
   }
}
