// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.atip.utils.generics.Consumer;
import de.audi.atip.utils.reactive.bindings.SPIBoolean;

class CarPlayDSIManager$15$1 implements Consumer {
   CarPlayDSIManager$15$1(CarPlayDSIManager$15 var1) {
      this.this$1 = var1;
   }

   public void accept(Boolean var1) {
      if (!var1) {
         CarPlayDSIManager.access$1300(CarPlayDSIManager$15.access$6000(this.this$1)).getPropertySDSActive().set("CarPlayDSIManager", SPIBoolean.FALSE);
      }
   }

   public void accept(Object var1) {
      this.accept((Boolean)var1);
   }
}
