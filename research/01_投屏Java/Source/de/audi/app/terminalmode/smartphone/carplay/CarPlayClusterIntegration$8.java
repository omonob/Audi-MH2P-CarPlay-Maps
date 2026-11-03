// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import java.util.TimerTask;

class CarPlayClusterIntegration$8 extends TimerTask {
   CarPlayClusterIntegration$8(CarPlayClusterIntegration var1, long var2, String var4, String var5, int var6) {
      this.this$0 = var1;
      this.val$generation = var2;
      this.val$request = var4;
      this.val$reason = var5;
      this.val$attempt = var6;
   }

   public void run() {
      if (CarPlayClusterIntegration.access$100(this.this$0, this.val$generation)) {
         if (CarPlayClusterIntegration.access$200(this.this$0, this.val$request, "released")) {
            CarPlayClusterIntegration.access$2300(this.this$0, this.val$generation, this.val$request, this.val$reason, true);
         } else if (this.val$attempt < 75) {
            CarPlayClusterIntegration.access$2100(this.this$0, this.val$generation, this.val$request, this.val$attempt + 1, this.val$reason);
         } else {
            CarPlayClusterIntegration.access$2300(this.this$0, this.val$generation, this.val$request, this.val$reason, false);
         }
      }
   }
}
