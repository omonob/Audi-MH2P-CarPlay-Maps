// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import java.util.TimerTask;

class CarPlayClusterIntegration$9 extends TimerTask {
   CarPlayClusterIntegration$9(CarPlayClusterIntegration var1, long var2, String var4, String var5) {
      this.this$0 = var1;
      this.val$generation = var2;
      this.val$request = var4;
      this.val$reason = var5;
   }

   public void run() {
      CarPlayClusterIntegration.access$2400(this.this$0, this.val$generation, this.val$request, this.val$reason);
   }
}
