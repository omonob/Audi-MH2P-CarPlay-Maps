// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.app.terminalmode.statemachine.IRequestor;
import de.audi.app.terminalmode.statemachine.ITMState;
import de.audi.app.terminalmode.statemachine.Resource;
import de.audi.app.terminalmode.statemachine.ResourceOwner;
import de.audi.app.terminalmode.statemachine.IStateChangeAction.StateChangeActionHook;
import de.audi.atip.utils.commandlist2.CommandList;

class CarPlayDSIManager$11 extends StateChangeActionHook {
   CarPlayDSIManager$11(CarPlayDSIManager var1) {
      this.this$0 = var1;
   }

   public void execute(CommandList var1, ITMState var2, IRequestor var3, long var4) {
      CarPlayDSIManager.access$5200(this.this$0).log(1000000, "[%1.changeState] audio media: device -> MU", "CarPlayDSIManager");
      if (var3.is(IRequestor.MAINUNIT)) {
         boolean var6 = CarPlayDSIManager.access$5000(this.this$0).getOwnerForResource(Resource.SCREEN).is(ResourceOwner.DEVICE)
            && var2.getOwnerForResource(Resource.SCREEN).is(ResourceOwner.MAINUNIT);
         if (var6) {
            CarPlayDSIManager.access$5300(this.this$0)
               .log(1000000, "[%1.changeState] audio media: DO NOT CHANGE AUDIO BECAUSE IT WAS CHANGED ALREADY", "CarPlayDSIManager");
         } else {
            var1.add(this.this$0.new RequestAudio(CarPlayDSIManager.access$5400(this.this$0), CarPlayDSIManager.access$1700(this.this$0)));
         }
      }
   }
}
