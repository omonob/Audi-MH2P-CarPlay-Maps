// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.kbd.hmi;

import de.audi.atip.hmi.event.RunnableEvent;
import java.util.TimerTask;

class KeyInputListener$1 extends TimerTask {
   KeyInputListener$1(KeyInputListener var1, long var2) {
      this.this$0 = var1;
      this.val$sequence = var2;
   }

   public void run() {
      KeyInputListener.access$300(this.this$0).getHMIService().getEventDispatcher().postEvent(new RunnableEvent(false, new KeyInputListener$1$1(this)));
   }
}
