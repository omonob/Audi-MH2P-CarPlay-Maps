// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import java.util.TimerTask;

class CarPlayClusterIntegration$5 extends TimerTask {
   CarPlayClusterIntegration$5(CarPlayClusterIntegration var1, long var2, long var4, String var6) {
      this.this$0 = var1;
      this.val$healthDeadline = var2;
      this.val$generation = var4;
      this.val$request = var6;
   }

   public void run() {
      synchronized (this.this$0) {
         if (System.currentTimeMillis() >= this.val$healthDeadline
            || this.val$generation != CarPlayClusterIntegration.access$600(this.this$0)
            || !CarPlayClusterIntegration.access$700(this.this$0)
            || CarPlayClusterIntegration.access$800(this.this$0)
            || CarPlayClusterIntegration.access$900(this.this$0) != 2
            || !CarPlayClusterIntegration.access$1000(this.this$0)
            || !CarPlayClusterIntegration.access$1200(this.this$0)) {
            return;
         }
      }

      if (CarPlayClusterIntegration.access$1100(this.this$0)) {
         CarPlayClusterIntegration.access$1600(this.this$0, this.val$generation, this.val$request, this.val$healthDeadline);
      } else {
         synchronized (this.this$0) {
            if (this.val$generation != CarPlayClusterIntegration.access$600(this.this$0)
               || !CarPlayClusterIntegration.access$700(this.this$0)
               || CarPlayClusterIntegration.access$800(this.this$0)
               || CarPlayClusterIntegration.access$900(this.this$0) != 2
               || !CarPlayClusterIntegration.access$1000(this.this$0)
               || !CarPlayClusterIntegration.access$1200(this.this$0)) {
               return;
            }

            CarPlayClusterIntegration.access$1202(this.this$0, false);
            CarPlayClusterIntegration.access$902(this.this$0, 1);
         }

         CarPlayClusterIntegration.access$1700(this.this$0);
         CarPlayClusterIntegration.access$1800(this.this$0, this.val$generation, this.val$request, 0);
      }
   }
}
