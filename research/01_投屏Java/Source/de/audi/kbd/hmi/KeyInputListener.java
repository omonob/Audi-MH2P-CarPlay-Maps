// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.kbd.hmi;

import de.audi.atip.base.IFrameworkAccess;
import de.audi.atip.hmi.event.ATIPEvent;
import de.audi.atip.hmi.event.ATIPEventListener;
import de.audi.atip.hmi.event.FingerCurveEvent;
import de.audi.atip.hmi.event.GestureEvent;
import de.audi.atip.hmi.event.JoystickEvent;
import de.audi.atip.hmi.event.KeyEvent;
import de.audi.atip.hmi.event.ProximityEvent;
import de.audi.atip.hmi.event.RawTouchEvent;
import de.audi.atip.hmi.event.TouchEvent;
import de.audi.atip.hmi.event.WheelButtonEvent;
import de.audi.atip.hmi.view.IDisplayManager;
import de.audi.atip.interapp.SDSService;
import de.audi.atip.keyhandling.IKeyEventDistributor;
import de.audi.atip.keyhandling.IVirtualGUIManager;
import de.audi.atip.log.LogChannel;
import de.eso.hmiservice.display.DisplayManager;
import java.util.Timer;
import java.util.TimerTask;

public class KeyInputListener implements ATIPEventListener {
   private final IKeyEventDistributor keyEventDistributor;
   private final LogChannel log;
   private final IFrameworkAccess framework;
   private final int terminalId;
   private static final long CLUSTER_BACK_LONG_PRESS_MS = 2000L;
   private Timer clusterBackTimer;
   private TimerTask clusterBackTask;
   private KeyEvent pendingClusterBack;
   private DisplayManager clusterBackDisplayManager;
   private long clusterBackGeneration;
   private long clusterBackStarted;
   private long clusterBackSequence;
   private boolean clusterBackHandled;

   public KeyInputListener(int var1, IFrameworkAccess var2, IVirtualGUIManager var3) {
      this.framework = var2;
      this.terminalId = var1;
      this.keyEventDistributor = var2.getHMITerminalRegistry().getKeyEventDistributor(var1);
      if (this.keyEventDistributor == null) {
         throw new IllegalArgumentException("terminalId " + var1 + " out of Range!");
      }

      this.keyEventDistributor.setHardkeyListeners(var3);
      this.log = var2.getLogChannel("Fw.Kbd.KeyInputListener");
   }

   public void processEvent(ATIPEvent var1) {
      this.log.log(1000000, "KeyInputListener.processEvent(%1)", var1);
      if (var1 instanceof KeyEvent) {
         if (this.handleClusterBack((KeyEvent)var1)) {
            return;
         }

         switch (((KeyEvent)var1).getID()) {
            case 10401:
               this.keyEventDistributor.keyPressed((KeyEvent)var1);
               break;
            case 10402:
               this.keyEventDistributor.keyReleased((KeyEvent)var1);
               break;
            case 10403:
               this.keyEventDistributor.keyTurned((WheelButtonEvent)var1);
               break;
            case 10404:
               this.keyEventDistributor.keyMoved((JoystickEvent)var1);
         }
      } else if (var1 instanceof TouchEvent) {
         switch (((TouchEvent)var1).getID()) {
            case 10904:
            case 10906:
            case 10907:
               this.keyEventDistributor.touchPadPressed((TouchEvent)var1);
               break;
            case 10905:
               this.keyEventDistributor.touchPadReleased((TouchEvent)var1);
               break;
            case 10908:
               this.keyEventDistributor.touchPadCharactersRecognized((TouchEvent)var1);
               break;
            case 10909:
               this.keyEventDistributor.touchPadApproached((TouchEvent)var1);
               break;
            case 10910:
               this.keyEventDistributor.touchPadAbandoned((TouchEvent)var1);
               break;
            case 10911:
               this.keyEventDistributor.touchPadPositionMoved((TouchEvent)var1);
               break;
            case 10912:
               this.keyEventDistributor.touchPadPositionMoved((TouchEvent)var1);
               break;
            case 10913:
               this.keyEventDistributor.touchPadPositionMoved((TouchEvent)var1);
               break;
            case 10914:
               this.keyEventDistributor.touchPadPalmRecognized((TouchEvent)var1);
         }
      } else if (var1 instanceof GestureEvent) {
         this.keyEventDistributor.triggerGestureEvent((GestureEvent)var1);
      } else if (var1 instanceof FingerCurveEvent) {
         this.keyEventDistributor.triggerFingerCurveEvent((FingerCurveEvent)var1);
      } else if (var1 instanceof ProximityEvent) {
         this.keyEventDistributor.triggerProximityEvent((ProximityEvent)var1);
      } else if (var1 instanceof RawTouchEvent) {
         this.keyEventDistributor.triggerRawTouchEvent((RawTouchEvent)var1);
      }
   }

   private DisplayManager getClusterDisplayManager() {
      try {
         IDisplayManager var1 = this.framework.getHMIService().getDisplayManager();
         return var1 instanceof DisplayManager ? (DisplayManager)var1 : null;
      } catch (RuntimeException var2) {
         this.log.log(10000, "BACK33_62: display manager unavailable: %1", var2.toString());
         return null;
      }
   }

   private long keyTime(KeyEvent var1) {
      return var1.getWhen() > 0L ? var1.getWhen() : this.framework.getMonotonicTime();
   }

   private boolean handleClusterBack(KeyEvent var1) {
      if (this.terminalId != 1 || var1.getTerminalID() != 1 || var1.getKeyCode() != 15) {
         return false;
      }

      if (var1.getID() == 10401) {
         if (this.pendingClusterBack != null) {
            var1.consume();
            return true;
         }

         DisplayManager var9 = this.getClusterDisplayManager();
         long var10 = var9 == null ? -1L : var9.getClusterOpacityToggleGeneration();
         if (var10 < 0L) {
            return false;
         }

         this.pendingClusterBack = new KeyEvent(var1.getReceiver(), 10401, var1.getWhen(), 15, 1);
         this.pendingClusterBack.setIgnorePopupRemoval(var1.ignorePopupRemoval());
         this.pendingClusterBack.setSdsAction(var1.getSdsAction());
         this.clusterBackDisplayManager = var9;
         this.clusterBackGeneration = var10;
         this.clusterBackStarted = this.keyTime(var1);
         this.clusterBackHandled = false;
         long var11 = ++this.clusterBackSequence;

         try {
            if (this.clusterBackTimer == null) {
               this.clusterBackTimer = new Timer(true);
            }

            this.clusterBackTask = new KeyInputListener$1(this, var11);
            this.clusterBackTimer.schedule(this.clusterBackTask, 2000L);
         } catch (RuntimeException var8) {
            this.clearClusterBack();
            this.log.log(10000, "BACK33_62: timer unavailable; keeping stock BACK: %1", var8.toString());
            return false;
         }

         var1.consume();
         return true;
      } else if (var1.getID() == 10402 && this.pendingClusterBack != null) {
         boolean var2 = this.clusterBackDisplayManager.getClusterOpacityToggleGeneration() == this.clusterBackGeneration;
         long var3 = this.keyTime(var1) - this.clusterBackStarted;
         if (!this.clusterBackHandled && var2 && var3 >= 2000L) {
            this.clusterBackHandled = this.clusterBackDisplayManager.toggleClusterMapOpacity(this.clusterBackGeneration);
         }

         KeyEvent var5 = this.pendingClusterBack;
         boolean var6 = !this.clusterBackHandled && var2;
         this.clearClusterBack();
         if (var6) {
            this.keyEventDistributor.keyPressed(var5);
            this.keyEventDistributor.keyReleased(var1);
         } else {
            var1.consume();
         }

         return true;
      } else {
         return false;
      }
   }

   private void finishClusterBackLongPress(long var1) {
      if (this.pendingClusterBack != null
         && var1 == this.clusterBackSequence
         && !this.clusterBackHandled
         && this.framework.getMonotonicTime() - this.clusterBackStarted >= 2000L) {
         this.clusterBackHandled = this.clusterBackDisplayManager.toggleClusterMapOpacity(this.clusterBackGeneration);
         if (this.clusterBackHandled) {
            this.log.log(1000000, "BACK33_62: 2s long press consumed; wait for release");
         }
      }
   }

   private void clearClusterBack() {
      this.clusterBackSequence++;
      if (this.clusterBackTask != null) {
         this.clusterBackTask.cancel();
         this.clusterBackTask = null;
      }

      this.pendingClusterBack = null;
      this.clusterBackDisplayManager = null;
      this.clusterBackHandled = false;
   }

   public void setSDSService(SDSService var1) {
      this.keyEventDistributor.setSDSService(var1);
   }

   public IKeyEventDistributor getKeyEventDistributor() {
      return this.keyEventDistributor;
   }
}
