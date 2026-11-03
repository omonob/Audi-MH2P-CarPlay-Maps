// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.app.terminalmode.device.TMDevice;
import de.audi.app.terminalmode.smartphone.SPIServiceState;
import de.audi.atip.utils.reactive.observables.Observables.Consumer2;

class CarPlayDSIManager$3 implements Consumer2 {
   private boolean previousState;
   private boolean rvcOffWhileStarting;

   CarPlayDSIManager$3(CarPlayDSIManager var1) {
      this.this$0 = var1;
      this.previousState = false;
      this.rvcOffWhileStarting = false;
   }

   public void accept(Boolean var1, SPIServiceState var2) {
      if (SPIServiceState.STARTED.is(var2)) {
         if (this.previousState && !var1 || this.rvcOffWhileStarting) {
            if (this.rvcOffWhileStarting) {
               this.rvcOffWhileStarting = false;
            }

            if (((TMDevice)CarPlayDSIManager.access$700(this.this$0).getDeviceManager().getProperties().activeDevice().get()).isScreenLastMode()) {
               CarPlayDSIManager.access$800(this.this$0).log(1000000, "[%1.accept#rvcSubscription2] LASTMODE TERMINAL MODE", "CarPlayDSIManager");
               CarPlayDSIManager.access$902(this.this$0, 1);
            } else {
               CarPlayDSIManager.access$1000(this.this$0).log(1000000, "[%1.accept#rvcSubscription2] LASTMODE NON SPI", "CarPlayDSIManager");
               CarPlayDSIManager.access$902(this.this$0, 2);
            }

            this.previousState = false;
         }
      } else {
         if (SPIServiceState.STARTING.is(var2) && this.previousState && !var1) {
            this.rvcOffWhileStarting = true;
         } else if (SPIServiceState.NOT_STARTED.is(var2)) {
            CarPlayDSIManager.access$902(this.this$0, 0);
         }

         this.previousState = var1;
      }
   }

   public void accept(Object var1, Object var2) {
      this.accept((Boolean)var1, (SPIServiceState)var2);
   }
}
