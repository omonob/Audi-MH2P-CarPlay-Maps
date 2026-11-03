// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import java.util.TimerTask;

class CarPlayClusterIntegration$2 extends TimerTask {
   CarPlayClusterIntegration$2(CarPlayClusterIntegration var1, long var2, String var4, int var5) {
      this.this$0 = var1;
      this.val$generation = var2;
      this.val$request = var4;
      this.val$attempt = var5;
   }

   public void run() {
      if (CarPlayClusterIntegration.access$100(this.this$0, this.val$generation)) {
         if (!CarPlayClusterIntegration.access$200(this.this$0, this.val$request, "registered")) {
            if (this.val$attempt < 35) {
               CarPlayClusterIntegration.access$300(this.this$0, this.val$generation, this.val$request, this.val$attempt + 1);
            } else {
               CarPlayClusterIntegration.access$400(this.this$0, this.val$generation, false, "registration-timeout");
            }
         } else {
            CarPlayClusterIntegration.access$500(this.this$0, this.val$generation, this.val$request);
         }
      }
   }
}
