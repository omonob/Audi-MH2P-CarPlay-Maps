// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import java.util.TimerTask;

class CarPlayClusterIntegration$1 extends TimerTask {
   CarPlayClusterIntegration$1(CarPlayClusterIntegration var1, long var2) {
      this.this$0 = var1;
      this.val$generation = var2;
   }

   public void run() {
      CarPlayClusterIntegration.access$000(this.this$0, this.val$generation);
   }
}
