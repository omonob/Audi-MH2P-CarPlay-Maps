// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.atip.interapp.combi.bap.navi.data.CombiBAPNaviManeuverDescriptor;

class CarPlayClusterIntegration$14 implements Runnable {
   CarPlayClusterIntegration$14(CarPlayClusterIntegration var1) {
      this.this$0 = var1;
   }

   public void run() {
      while (CarPlayClusterIntegration.access$3400(this.this$0) && CarPlayClusterIntegration.access$3500(this.this$0)) {
         try {
            Thread.sleep(CarPlayClusterIntegration.access$3600(this.this$0));
         } catch (Exception var3) {
            break;
         }

         if (!CarPlayClusterIntegration.access$3400(this.this$0)
            || !CarPlayClusterIntegration.access$3500(this.this$0)
            || CarPlayClusterIntegration.access$3700(this.this$0) == null) {
            break;
         }

         try {
            CarPlayClusterIntegration.access$3800(this.this$0);
            CarPlayClusterIntegration.access$3900(this.this$0);
            CarPlayClusterIntegration.access$3700(this.this$0).updateActiveRGType(CarPlayClusterIntegration.access$4000(this.this$0));
            if (CarPlayClusterIntegration.access$4100(this.this$0) >= 0) {
               CombiBAPNaviManeuverDescriptor var1 = new CombiBAPNaviManeuverDescriptor(
                  CarPlayClusterIntegration.access$4100(this.this$0),
                  CarPlayClusterIntegration.access$4200(this.this$0),
                  0,
                  CarPlayClusterIntegration.access$4300(this.this$0) != null ? CarPlayClusterIntegration.access$4300(this.this$0) : new byte[0]
               );
               CarPlayClusterIntegration.access$3700(this.this$0).updateManeuverDescriptor(new CombiBAPNaviManeuverDescriptor[]{var1});
            }

            if (CarPlayClusterIntegration.access$4400(this.this$0) >= 0) {
               CarPlayClusterIntegration.access$3700(this.this$0)
                  .updateDistanceToNextManeuver(
                     CarPlayClusterIntegration.access$4500(this.this$0),
                     CarPlayClusterIntegration.access$4600(this.this$0),
                     CarPlayClusterIntegration.access$4700(this.this$0),
                     CarPlayClusterIntegration.access$4800(this.this$0)
                  );
            }

            if (CarPlayClusterIntegration.access$4900(this.this$0) > 0) {
               CarPlayClusterIntegration.access$3700(this.this$0).updateManeuverState(CarPlayClusterIntegration.access$4900(this.this$0));
            }

            if (CarPlayClusterIntegration.access$5000(this.this$0) != null && CarPlayClusterIntegration.access$5000(this.this$0).length() > 0) {
               CarPlayClusterIntegration.access$3700(this.this$0)
                  .updateTurnToInfo(
                     CarPlayClusterIntegration.access$5000(this.this$0),
                     CarPlayClusterIntegration.access$5100(this.this$0) != null ? CarPlayClusterIntegration.access$5100(this.this$0) : ""
                  );
            }

            if (CarPlayClusterIntegration.access$5200(this.this$0) > 0 && CarPlayClusterIntegration.access$5300(this.this$0) != null) {
               CarPlayClusterIntegration.access$3700(this.this$0).updateLaneGuidance(true, CarPlayClusterIntegration.access$5300(this.this$0));
            }
         } catch (Exception var2) {
         }
      }
   }
}
