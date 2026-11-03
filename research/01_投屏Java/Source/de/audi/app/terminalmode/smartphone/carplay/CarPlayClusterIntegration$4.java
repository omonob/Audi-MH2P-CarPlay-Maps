// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import java.util.TimerTask;

class CarPlayClusterIntegration$4 extends TimerTask {
   CarPlayClusterIntegration$4(CarPlayClusterIntegration var1, long var2, String var4, int var5) {
      this.this$0 = var1;
      this.val$generation = var2;
      this.val$request = var4;
      this.val$attempt = var5;
   }

   public void run() {
      synchronized (this.this$0) {
         if (this.val$generation != CarPlayClusterIntegration.access$600(this.this$0)
            || !CarPlayClusterIntegration.access$700(this.this$0)
            || CarPlayClusterIntegration.access$800(this.this$0)
            || CarPlayClusterIntegration.access$900(this.this$0) != 1
            || !CarPlayClusterIntegration.access$1000(this.this$0)) {
            return;
         }
      }

      if (CarPlayClusterIntegration.access$1100(this.this$0)) {
         long var8;
         synchronized (this.this$0) {
            if (this.val$generation != CarPlayClusterIntegration.access$600(this.this$0)
               || !CarPlayClusterIntegration.access$700(this.this$0)
               || CarPlayClusterIntegration.access$800(this.this$0)) {
               return;
            }

            CarPlayClusterIntegration.access$1202(this.this$0, true);
            if (CarPlayClusterIntegration.access$1300(this.this$0) == 0L) {
               CarPlayClusterIntegration.access$1302(this.this$0, System.currentTimeMillis() + 15000L);
            }

            var8 = CarPlayClusterIntegration.access$1300(this.this$0);
            CarPlayClusterIntegration.access$1402(this.this$0, true);
            CarPlayClusterIntegration.access$1502(this.this$0, false);
            CarPlayClusterIntegration.access$902(this.this$0, 2);
         }

         CarPlayClusterIntegration.access$1600(this.this$0, this.val$generation, this.val$request, var8);
      } else {
         boolean var7 = CarPlayClusterIntegration.access$1700(this.this$0);
         if (this.val$attempt >= 4 && this.val$attempt % 10 == 9) {
         }

         CarPlayClusterIntegration.access$1800(this.this$0, this.val$generation, this.val$request, this.val$attempt + 1);
      }
   }
}
