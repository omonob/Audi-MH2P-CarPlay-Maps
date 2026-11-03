// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import java.util.TimerTask;

class CarPlayClusterIntegration$3 extends TimerTask {
   CarPlayClusterIntegration$3(CarPlayClusterIntegration var1, long var2, String var4) {
      this.this$0 = var1;
      this.val$generation = var2;
      this.val$request = var4;
   }

   public void run() {
      CarPlayClusterIntegration.access$500(this.this$0, this.val$generation, this.val$request);
   }
}
