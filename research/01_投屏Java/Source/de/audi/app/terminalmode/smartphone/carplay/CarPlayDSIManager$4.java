// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.app.terminalmode.statemachine.IRequestor;
import de.audi.app.terminalmode.statemachine.ITMState;
import de.audi.app.terminalmode.statemachine.Resource;
import de.audi.app.terminalmode.statemachine.ResourceOwner;
import de.audi.app.terminalmode.statemachine.IStateChangeAction.StateChangeActionOverride;
import de.audi.atip.utils.commandlist2.CommandList;
import de.audi.atip.utils.reactive.bindings.SPIBoolean;

class CarPlayDSIManager$4 extends StateChangeActionOverride {
   CarPlayDSIManager$4(CarPlayDSIManager var1) {
      this.this$0 = var1;
   }

   public void execute(CommandList var1, ITMState var2, IRequestor var3, long var4) {
      CarPlayDSIManager.access$1100(this.this$0).log(1000000, "[%1.changeState] Audio_Media: Normal -> Paused", "CarPlayDSIManager");
      if (!ResourceOwner.DEVICE.is(var2.getOwnerForResource(Resource.AUDIO_PHONE))
         && !ResourceOwner.DEVICE.is(var2.getOwnerForResource(Resource.AUDIO_SPEECH))
         && !ResourceOwner.DEVICE.is(var2.getOwnerForResource(Resource.AUDIO_RINGTONE))) {
         CarPlayDSIManager.access$1202(this.this$0, (SPIBoolean)CarPlayDSIManager.access$1300(this.this$0).getPropertySDSActive().get());
         CarPlayDSIManager.access$1400(this.this$0).log(1000000, "[%1.execute] statusSDS=%2", "CarPlayDSIManager", CarPlayDSIManager.access$1200(this.this$0));
         if (CarPlayDSIManager.access$1200(this.this$0).isValid() && CarPlayDSIManager.access$1200(this.this$0).getBoolean()) {
            String var6 = "UpdateTMStateOnly";
            var1.add(
               new CarPlayDSIManager$4$1(
                  this,
                  CarPlayDSIManager.access$1500(this.this$0),
                  "UpdateTMStateOnly",
                  CarPlayDSIManager.access$1600(this.this$0),
                  CarPlayDSIManager.access$1700(this.this$0)
               )
            );
         } else {
            var1.add(
               new CarPlayDSIManager$4$2(
                  this,
                  CarPlayDSIManager.access$2000(this.this$0),
                  CarPlayDSIManager.access$2100(this.this$0),
                  this.this$0,
                  var2,
                  CarPlayDSIManager.access$1700(this.this$0)
               )
            );
         }
      }
   }
}
