// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.app.terminalmode.dsi.carplay.CarplayButton;
import de.audi.app.terminalmode.dsi.carplay.CarplayButtonState;
import de.audi.app.terminalmode.smartphone.IPhoneCallController;

class CarPlayDSIManager$1 implements IPhoneCallController {
   CarPlayDSIManager$1(CarPlayDSIManager var1) {
      this.this$0 = var1;
   }

   public void hook(boolean var1) {
      CarPlayDSIManager.access$000(this.this$0).postButtonEvent(CarplayButton.ACCEPT_CALL, var1 ? CarplayButtonState.RELEASED : CarplayButtonState.PRESSED);
   }

   public void hangup(boolean var1) {
      CarPlayDSIManager.access$000(this.this$0).postButtonEvent(CarplayButton.END_CALL, var1 ? CarplayButtonState.RELEASED : CarplayButtonState.PRESSED);
   }

   public void flash(boolean var1) {
      CarPlayDSIManager.access$000(this.this$0).postButtonEvent(CarplayButton.FLASH_CALL, var1 ? CarplayButtonState.RELEASED : CarplayButtonState.PRESSED);
   }
}
