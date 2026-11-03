// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.app.terminalmode.IContext;
import de.audi.app.terminalmode.statemachine.IStateHandler;
import de.audi.app.terminalmode.statemachine.ResourceState;
import de.audi.app.terminalmode.statemachine.commands.AbstractStateHandlerCommand;
import de.audi.atip.log.LogChannel;

class CarPlayDSIManager$4$1 extends AbstractStateHandlerCommand {
   private static final String LOGINFO = "(Audio_Media: Normal -> Paused)";

   CarPlayDSIManager$4$1(CarPlayDSIManager$4 var1, LogChannel var2, String var3, IContext var4, IStateHandler var5) {
      super(var2, var3, var4, var5);
      this.this$1 = var1;
   }

   public void execute() {
      this.logger.log(1000000, "### CMD ### [%1][%2] ANONYMOUS: %3", "CarPlayDSIManager", "UpdateTMStateOnly", "(Audio_Media: Normal -> Paused)");
      CarPlayDSIManager.access$1900(CarPlayDSIManager$4.access$1800(this.this$1), ResourceState.PAUSED);
      this.finish();
   }
}
