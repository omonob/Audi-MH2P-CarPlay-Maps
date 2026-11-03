// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.eso.hmiservice.display;

import de.audi.atip.base.IFrameworkAccess;
import de.audi.atip.hmi.event.ATIPEvent;
import de.audi.atip.hmi.event.ATIPEventListener;
import de.audi.atip.hmi.event.ActiveContextEvent;
import de.audi.atip.hmi.view.IDisplayListener;
import de.audi.atip.hmi.view.IDisplayManager;
import de.audi.atip.hmi.view.IDisplayManager.Context;
import de.audi.atip.log.LogChannel;
import java.io.FileWriter;
import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.Map;
import org.dsi.ifc.base.DSIListener;
import org.dsi.ifc.displaymanagement.DSIDisplayManagement;
import org.dsi.ifc.displaymanagement.DSIDisplayManagementListener;
import org.dsi.ifc.displaymanagement.DisplayContext;
import org.dsi.ifc.global.ResourceLocator;
import org.osgi.framework.BundleActivator;
import org.osgi.framework.BundleContext;
import org.osgi.framework.ServiceReference;
import org.osgi.framework.ServiceRegistration;
import org.osgi.util.tracker.ServiceTracker;
import org.osgi.util.tracker.ServiceTrackerCustomizer;

public abstract class DisplayManager implements ServiceTrackerCustomizer, BundleActivator, IDisplayManager, ATIPEventListener {
   public static final int UNKNOWN_CONTEXT_ID = -1;
   private static final int MAX_DISPLAYABLES = 110;
   private static final int WAIT_FOR_LOCK_RESULT = 100;
   private static final boolean MIB3 = Boolean.getBoolean("mib3");
   private static DisplayContext[] requestedContexts = new DisplayContext[10];
   private static DisplayContext[] confirmedActiveContext = new DisplayContext[10];
   private static int[][] displayableOpacities = new int[10][110];
   private static int[][][] displayablePositions = new int[10][110][2];
   private static int sessionID = 0;
   protected final IFrameworkAccess framework;
   private BundleContext bc;
   protected LogChannel log;
   private volatile boolean initialized;
   private ServiceTracker displayManagerTracker;
   private ServiceReference srDisplayManagement;
   private DSIDisplayManagement dsiDispMgmt;
   private static final int BUFFER_INDEX_DISPLAY_CONTEXT = 0;
   private static final int BUFFER_INDEX_DISPLAY_TYPE = 1;
   private static final int BUFFER_INDEX_UPDATE_RATE = 2;
   private static final int MAX_BUFFER_INDICES = 3;
   private final int[][] buffer = new int[10][3];
   protected DisplayContext[] dc;
   private DSIDisplayManagementListener dsiDisplayManagementListener;
   private ServiceRegistration srDSIDisplayManagementListener;
   private Object syncDisplayManagement = new Object();
   private IDisplayListener[] displayListeners = new IDisplayListener[10];
   protected Map displayableExtents;
   private int[] sessionIDs = new int[10];
   private boolean waitForLock = false;
   private boolean waitForUnLock = false;
   private boolean lastCallWasLock = false;
   private boolean waitForDeferUpdates = false;
   private boolean[] lastRequestAnswered = new boolean[10];
   private volatile boolean isRearViewCameraActive = false;
   private boolean lastContextSwitchWasToRvc;
   private static final int DISPLAY_CLUSTER = 4;
   private static final int CLUSTER_TERMINAL = 1;
   private static final int DISPLAYABLE_FPK = 41;
   private static final int DISPLAYABLE_KOMBI_MAP = 33;
   private static final int KDK_TERMINAL = 7;
   private static final int DISPLAYABLE_MAP_ROUTE_GUIDANCE = 20;
   private static final int CONTEXT_HMI_KDK_KOMBI_DISPLAY = 24;
   private static final int DISPLAYABLE_CLUSTER_MIRROR = 62;
   private static final long CLUSTER_SWITCH_TIMEOUT_MS = 3000L;
   private boolean mirror62Requested = false;
   private static volatile boolean clusterMap33Selected = false;
   private long clusterOpacityGeneration = 0L;
   private boolean clusterRgiVisible = false;
   private boolean clusterRgiWanted = false;
   private boolean mirror62Active = false;
   private volatile boolean mirror62MapHidden = false;
   private int mirrorReturnContext = -1;
   private static final int SPORT_SMALL_STAGE_X = -596;
   private static final String ALTSCREEN_LAYOUT_CONTROL_FILE = "/tmp/carplay_cluster_layout.ctl";
   private int altScreenSportSmallStage = -1;

   private static void initializeDisplayableMapping() {
      displayableMapping[0] = 16;
      displayableMapping[1] = 17;
      displayableMapping[2] = 18;
      displayableMapping[3] = 19;
      displayableMapping[4] = 20;
      displayableMapping[5] = 21;
      displayableMapping[7] = 23;
      displayableMapping[8] = 25;
      displayableMapping[14] = 34;
      displayableMapping[9] = 26;
      displayableMapping[10] = 27;
      displayableMapping[11] = 28;
      displayableMapping[12] = 22;
      displayableMapping[13] = 24;
      displayableMapping[15] = 36;
      displayableMapping[16] = 41;
      displayableMapping[17] = 50;
      displayableMapping[18] = 39;
   }

   public DisplayManager(IFrameworkAccess var1) {
      this.framework = var1;
      this.log = var1.getLogChannel("Widgets.Display");

      for (int var2 = 0; var2 < this.buffer.length; var2++) {
         this.buffer[var2][0] = -1;
         this.buffer[var2][1] = -1;
         this.buffer[var2][2] = -1;
      }

      this.initialized = false;
      this.displayableExtents = new HashMap();
   }

   LogChannel getLogChannel() {
      return this.log;
   }

   private void displayManagementIsAvailable() {
      synchronized (this.syncDisplayManagement) {
         this.syncDisplayManagement.notifyAll();
      }
   }

   private void waitForDSIDisplayManagement() {
      synchronized (this.syncDisplayManagement) {
         this.log.log(1000000, "waitForDSIDisplayManagement: wait up to 5 sec");
         if (!this.initialized) {
            try {
               this.syncDisplayManagement.wait(5000L);
            } catch (InterruptedException var5) {
               Thread.interrupted();
            }
         }
      }

      if (this.initialized) {
         this.log.log(1000000, "waitForDSIDisplayManagement: succeeded!");
      } else {
         this.log.log(10000, "waitForDSIDisplayManagement: failed!");
         this.framework.writeErrorDump(null, "waitForDSIDisplayManagement: failed!", true, false);
      }
   }

   private final void initDSI() {
      if (!this.initialized) {
         if (this.dsiDispMgmt != null) {
            if (this.dc == null) {
               this.defineContexts();
            }

            this.initialized = true;
         } else {
            this.log.log(10000, "DSI service is NULL");
         }
      }
   }

   private DisplayContext getContext(int var1) {
      return this.dc != null && this.dc.length > var1 && var1 >= 0 ? this.dc[var1] : null;
   }

   public int[] getDisplayables(int var1) {
      DisplayContext var2 = this.getContext(var1);
      if (var2 != null) {
         return var2.getDisplayableList();
      }

      this.log.log(10000, "no context for ID: %1", var1);
      return null;
   }

   private int clusterContextId() {
      if (this.lastRequestAnswered[1] && confirmedActiveContext[1] != null && confirmedActiveContext[1].getId() != -1) {
         return confirmedActiveContext[1].getId();
      } else {
         return requestedContexts[1] != null ? requestedContexts[1].getId() : -1;
      }
   }

   private int[] clusterContextDisplayables(int var1) {
      DisplayContext var2 = this.getContext(var1);
      if (var2 != null) {
         int[] var3 = var2.getDisplayableList();
         if (var3 != null && var3.length > 0) {
            return var3;
         }
      }

      return new int[]{41, 33};
   }

   private boolean sameDisplayableList(DisplayContext var1, int[] var2) {
      if (var1 != null && var2 != null) {
         int[] var3 = var1.getDisplayableList();
         if (var3 != null && var3.length == var2.length) {
            for (int var4 = 0; var4 < var2.length; var4++) {
               if (var3[var4] != var2[var4]) {
                  return false;
               }
            }

            return true;
         } else {
            return false;
         }
      } else {
         return false;
      }
   }

   private int[] clusterMirrorDisplayables() {
      int[] var1 = this.clusterContextDisplayables(this.mirrorReturnContext);
      boolean var2 = false;
      int var3 = 0;

      for (int var4 = 0; var4 < var1.length; var4++) {
         if (var1[var4] == 20) {
            var2 = true;
         } else if (var1[var4] != 62) {
            var3++;
         }
      }

      int[] var7 = new int[var3 + 1 + (var2 ? 1 : 0)];
      int var5 = 0;

      for (int var6 = 0; var6 < var1.length; var6++) {
         if (var1[var6] != 20 && var1[var6] != 62) {
            var7[var5++] = var1[var6];
         }
      }

      var7[var5++] = 62;
      if (var2) {
         var7[var5++] = 20;
      }

      return withoutPhoneCard(var7);
   }

   public static boolean isClusterMap33Selected() {
      return clusterMap33Selected;
   }

   public synchronized long getClusterOpacityToggleGeneration() {
      return this.dsiDispMgmt != null
            && this.initialized
            && this.mirror62Requested
            && this.lastRequestAnswered[1]
            && !this.isRearViewCameraActive
            && this.isClusterMirror62Active()
         ? this.clusterOpacityGeneration
         : -1L;
   }

   public synchronized boolean toggleClusterMapOpacity(long var1) {
      if (var1 >= 0L && var1 == this.getClusterOpacityToggleGeneration()) {
         boolean var3 = clusterMap33Selected;

         try {
            this.applyClusterOpacitySelection(!var3);
            this.log.log(1000000, "DisplayManager#OPACITY33_62 selected=%1 (AltScreen stays running)", clusterMap33Selected ? 33 : 62);
            return true;
         } catch (RuntimeException var7) {
            this.log.log(10000, "DisplayManager#OPACITY33_62 request failed: %1", var7.toString());

            try {
               this.applyClusterOpacitySelection(var3);
            } catch (RuntimeException var6) {
               this.log.log(10000, "DisplayManager#OPACITY33_62 rollback failed: %1", var6.toString());
            }

            return false;
         }
      } else {
         return false;
      }
   }

   private void applyClusterOpacitySelection(boolean var1) {
      this.setClusterDisplayableOpacity(var1 ? 33 : 62, 100);
      this.setClusterDisplayableOpacity(var1 ? 62 : 33, 0);
      clusterMap33Selected = var1;
      this.mirror62MapHidden = !var1;
   }

   private boolean conflictsWithClusterOpacitySelection(int var1, int var2, int var3) {
      if (this.mirror62Requested
         && (this.mirror62Active || this.mirror62MapHidden || clusterMap33Selected)
         && (var2 == 1 || var2 == 4)
         && (var1 == 33 || var1 == 62)) {
         int var4 = clusterMap33Selected ? 33 : 62;
         return var3 != (var1 == var4 ? 100 : 0);
      } else {
         return false;
      }
   }

   private static int[] withoutDisplayable(int[] var0, int var1) {
      int var2 = 0;
      if (var0 == null) {
         return null;
      }

      for (int var3 = 0; var3 < var0.length; var3++) {
         if (var0[var3] != var1) {
            var2++;
         }
      }

      int[] var4 = new int[var2];
      var2 = 0;

      for (int var6 = 0; var6 < var0.length; var6++) {
         if (var0[var6] != var1) {
            var4[var2++] = var0[var6];
         }
      }

      return var4;
   }

   private static boolean containsDisplayable(int[] var0, int var1) {
      if (var0 == null) {
         return false;
      }

      for (int var2 = 0; var2 < var0.length; var2++) {
         if (var0[var2] == var1) {
            return true;
         }
      }

      return false;
   }

   private synchronized void updateAltScreenSportLayout(int var1) {
      int var2 = var1 == -596 ? 1 : 0;
      if (var2 != this.altScreenSportSmallStage) {
         FileWriter var3 = null;

         try {
            long var4 = System.currentTimeMillis();
            var3 = new FileWriter("/tmp/carplay_cluster_layout.ctl", false);
            var3.write("v=1 seq=" + var4 + " sportSmall=" + var2 + " mapX=" + var1 + "\n");
            var3.flush();
            this.altScreenSportSmallStage = var2;
            this.log.log(1000000, "DisplayManager#AltScreen sport-small state=%1 mapX=%2", var2, var1);
         } catch (Exception var14) {
            this.log.log(10000, "DisplayManager#AltScreen layout control write failed: %1", var14.toString());
         } finally {
            if (var3 != null) {
               try {
                  var3.close();
               } catch (Exception var13) {
               }
            }
         }
      }
   }

   private static boolean clusterRgiRelocEnabled() {
      return false;
   }

   private int[] clusterRgiPosition() {
      return new int[2];
   }

   private static String displayableList(int[] var0) {
      if (var0 == null) {
         return "NULL";
      }

      StringBuffer var1 = new StringBuffer("[");

      for (int var2 = 0; var2 < var0.length; var2++) {
         if (var2 > 0) {
            var1.append(",");
         }

         var1.append(var0[var2]);
      }

      return var1.append("]").toString();
   }

   private boolean isClusterMirrorDisplayableList(int[] var1) {
      if (var1 == null) {
         return false;
      }

      for (int var2 = 0; var2 < var1.length; var2++) {
         if (var1[var2] == 62) {
            return true;
         }
      }

      return false;
   }

   private void setClusterDisplayableOpacity(int var1, int var2) {
      this.dsiDispMgmt.setOpacity(var1, 4, var2);
      displayableOpacities[1][var1] = var2;
   }

   private synchronized boolean switchClusterDisplayablesAndWait(int[] var1, boolean var2, int var3) {
      if (this.dsiDispMgmt != null && this.initialized) {
         this.sessionIDs[1] = ++sessionID;
         this.lastRequestAnswered[1] = false;
         requestedContexts[1] = new DisplayContext(var3, var1);
         this.dsiDispMgmt.showDisplayables(4, var1, this.sessionIDs[1]);
         long var4 = System.currentTimeMillis() + 3000L;

         while (!this.lastRequestAnswered[1]) {
            long var6 = var4 - System.currentTimeMillis();
            if (var6 <= 0L) {
               break;
            }

            try {
               this.wait(var6);
            } catch (InterruptedException var9) {
               Thread.interrupted();
               break;
            }
         }

         boolean var10 = this.lastRequestAnswered[1] && this.sameDisplayableList(confirmedActiveContext[1], var1);
         if (var10) {
            this.mirror62Active = var2;
            this.mirrorReturnContext = var3;
            this.log.log(1000000, "DisplayManager#cluster composition confirmed, mirror62 active: %1", var2 ? 1 : 0);
         } else {
            this.log.log(1000000, "DisplayManager#cluster composition NOT confirmed for sessionID %1", this.sessionIDs[1]);
         }

         return var10;
      } else {
         this.log.log(1000000, "DisplayManager#switchClusterDisplayablesAndWait not initialized");
         return false;
      }
   }

   public synchronized boolean activateClusterMirror62() {
      if (this.dsiDispMgmt != null && this.initialized) {
         this.mirrorReturnContext = this.clusterContextId();
         if (!this.mirror62Requested) {
            this.clusterOpacityGeneration++;
            clusterMap33Selected = false;
         }

         this.mirror62Requested = true;
         this.setClusterDisplayableOpacity(62, clusterMap33Selected ? 0 : 100);
         this.log.log(1000000, "DisplayManager#activateClusterMirror62 armed for OEM map context");
         this.applyClusterRgiVisibility("mirror-armed");
         return true;
      } else {
         this.log.log(1000000, "DisplayManager#activateClusterMirror62 not initialized");
         return false;
      }
   }

   public synchronized boolean setClusterRgiVisible(boolean var1) {
      return var1 ^ true;
   }

   private void applyClusterRgiVisibility(String var1) {
   }

   private void setPlatformKDKVisible(int var1) {
   }

   private int currentContextId(int var1) {
      try {
         Method var2 = this.getClass().getMethod("getCurrentContextID", int.class);
         Object var3 = var2.invoke(this, new Integer(var1));
         return (Integer)var3;
      } catch (Throwable var4) {
         return -1;
      }
   }

   private int currentVisibleKDK(int var1) {
      try {
         Method var2 = this.getClass().getMethod("getVisibleKDK", int.class);
         Object var3 = var2.invoke(this, new Integer(var1));
         return (Integer)var3;
      } catch (Throwable var4) {
         return -1;
      }
   }

   public synchronized boolean isClusterMirror62Active() {
      return this.mirror62Active && confirmedActiveContext[1] != null && this.isClusterMirrorDisplayableList(confirmedActiveContext[1].getDisplayableList());
   }

   public synchronized boolean refreshClusterMirror62ThroughCurrentContext() {
      if (this.dsiDispMgmt != null && this.initialized && this.mirror62Requested) {
         if (!this.lastRequestAnswered[1] && this.sameDisplayableList(requestedContexts[1], this.clusterMirrorDisplayables())) {
            return true;
         }

         int var1 = this.clusterContextId();
         if (var1 < 0 || this.dc == null || var1 >= this.dc.length) {
            var1 = this.mirrorReturnContext;
         }

         if (var1 >= 0 && this.dc != null && var1 < this.dc.length) {
            this.switchContext(var1, 1, this.displayListeners[1]);
            return true;
         } else {
            this.log.log(1000000, "DisplayManager#refreshClusterMirror62 no current OEM map context");
            return false;
         }
      } else {
         return false;
      }
   }

   public synchronized boolean restoreClusterMapFromMirror62() {
      this.clusterRgiWanted = false;
      if (this.clusterRgiVisible) {
         this.clusterRgiVisible = false;
         this.setPlatformKDKVisible(-1);
      }

      if (this.dsiDispMgmt != null && this.initialized) {
         int var1 = this.mirrorReturnContext;
         this.clusterOpacityGeneration++;
         clusterMap33Selected = false;
         this.mirror62Requested = false;
         this.setPlatformKDKVisible(-1);
         this.setClusterDisplayableOpacity(33, 100);
         this.mirror62MapHidden = false;
         boolean var2 = this.switchClusterDisplayablesAndWait(this.clusterContextDisplayables(var1), false, var1);
         if (!var2 && this.mirror62Active) {
            this.mirror62Requested = true;
            this.mirror62MapHidden = true;
            this.setClusterDisplayableOpacity(33, 0);
         }

         return var2;
      } else {
         this.log.log(1000000, "DisplayManager#restoreClusterMapFromMirror62 not initialized");
         return false;
      }
   }

   public synchronized void switchContext(int var1, int var2, IDisplayListener var3) {
      this.log.log(10000000, "DisplayManager#switchContext terminalId=%1, displayContext=%2", var2, var1);
      if (MIB3) {
         this.log.log(10000, "DisplayManager#switchContext for MIB3 ignored terminalId=%1", var2);
      } else if (var2 >= 0 && var2 < 10) {
         if (this.dc == null || this.dc.length <= var1) {
            this.log.log(1000000, "DisplayManager#switchContext no context for id %1 defined", var1);
         } else if (this.isMainDisplayTerminal(var2) && this.isRearViewCameraActive && !this.isRvcContext(var1) && !this.lastContextSwitchWasToRvc) {
            this.log
               .log(1000000, "DisplayManager#switchContext RVC is active and context switch to %1 (non RVC context) for Main Display. Skip this switch!", var1);
         } else {
            boolean var4 = false;
            boolean var5 = false;
            this.lastContextSwitchWasToRvc = this.isRvcContext(var1);
            this.displayListeners[var2] = var3;
            if (this.dsiDispMgmt != null && this.initialized) {
               boolean var6 = var2 == 1 && this.mirror62Requested && !this.mirror62Active;
               if (var6
                  || this.lastRequestAnswered[var2] && (confirmedActiveContext[var2] == null || confirmedActiveContext[var2].getId() != var1)
                  || !this.lastRequestAnswered[var2] && (requestedContexts[var2] == null || requestedContexts[var2].getId() != var1)) {
                  int var7 = this.getInternalDisplayID(var2);
                  this.lastRequestAnswered[var2] = false;
                  this.sessionIDs[var2] = ++sessionID;
                  this.log.log(1000000, "DisplayManager#switchContext switch to context %1 on external terminal %2 ", var1, var2);
                  this.log.log(10000000, "Displaymanager#switchContext using internal terminal %1 for switch, sessionID %2", var7, this.sessionIDs[var2]);
                  int[] var8 = this.dc[var1].getDisplayableList();
                  DisplayContext var9 = this.dc[var1];
                  if (var2 == 1 && this.mirror62Requested) {
                     this.applyClusterOpacitySelection(clusterMap33Selected);
                     if (var1 == 24 && this.dc.length > 26 && this.dc[26] != null) {
                        var1 = 26;
                     }

                     this.mirrorReturnContext = var1;
                     this.mirror62MapHidden = true;
                     this.setClusterDisplayableOpacity(33, 0);
                     this.setClusterDisplayableOpacity(62, 100);
                     var8 = this.clusterMirrorDisplayables();
                     var9 = new DisplayContext(var1, var8);
                     this.log.log(1000000, "DisplayManager#switchContext cluster context %1 extended with mirror 62", var1);
                     var5 = true;
                  }

                  if (var2 == 7 && this.mirror62Requested && containsDisplayable(var8, 20)) {
                     var8 = withoutDisplayable(var8, 20);
                     var9 = new DisplayContext(var1, var8);
                  }

                  this.log.log(10000000, "Displaymanager#switchContext calling showDisplayables instead");
                  this.dsiDispMgmt.showDisplayables(var7, var8, this.sessionIDs[var2]);
                  if (var5 && containsDisplayable(var8, 20)) {
                     int[] var10 = this.clusterRgiPosition();
                     this.dsiDispMgmt.setPosition(20, var7, var10[0], var10[1]);
                     this.dsiDispMgmt.setOpacity(20, var7, 100);
                     displayablePositions[var2][20][0] = var10[0];
                     displayablePositions[var2][20][1] = var10[1];
                     displayableOpacities[var2][20] = 100;
                  }

                  if (var4) {
                     this.dsiDispMgmt.setPosition(62, var7, 0, 0);
                     this.dsiDispMgmt.setOpacity(62, var7, 100);
                     displayablePositions[var2][62][0] = 0;
                     displayablePositions[var2][62][1] = 0;
                     displayableOpacities[var2][62] = 100;
                     this.log.log(1000000, "DisplayManager#switchContext mirror 62 positioned and opaque on internal display %1", var7);
                  }

                  this.buffer[var2][0] = -1;
                  requestedContexts[var2] = var9;
               } else {
                  requestedContexts[var2] = this.dc[var1];
               }
            } else if (this.framework.isSimulator()) {
               requestedContexts[var2] = this.dc[var1];
               this.lastRequestAnswered[var2] = true;
               confirmedActiveContext[var2] = this.dc[var1];
            } else {
               this.log.log(10000, "Displaymanager not initialized");
               this.buffer[var2][0] = var1;
            }
         }
      } else {
         this.log.log(1000000, "DisplayManager#switchContext terminal with ID: %1 is not a valid terminalId", var2);
      }
   }

   public void setIsRearViewCameraActive(boolean var1) {
      this.isRearViewCameraActive = var1;
   }

   public boolean isRearViewCameraActive() {
      return this.isRearViewCameraActive;
   }

   private boolean isRvcContext(int var1) {
      return var1 == 1;
   }

   private boolean isMainDisplayTerminal(int var1) {
      return 0 == this.getInternalDisplayID(var1);
   }

   protected int getInternalDisplayID(int var1) {
      if (var1 == 0) {
         return 0;
      } else if (var1 == 8) {
         return 6;
      } else if (var1 == 1) {
         return 4;
      } else if (var1 == 9) {
         return 5;
      } else {
         return var1 == 7 ? 7 : 0;
      }
   }

   private int getHmiTerminalID(int var1) {
      if (var1 == 0) {
         return 0;
      } else if (var1 == 6) {
         return 8;
      } else if (var1 == 5) {
         return 9;
      } else {
         return var1 == 7 ? 7 : 1;
      }
   }

   public void lockDisplay(int var1) {
      if (!this.framework.isSimulator()) {
         this.log.log(1000000, "DisplayManager: Displaymanager: lockDisplay %1", var1);
         if (this.dsiDispMgmt != null && this.initialized) {
            this.dsiDispMgmt.lockDisplay(var1);
            this.lastCallWasLock = true;
         } else {
            this.log.log(10000, "Displaymanager not initialized");
         }
      }
   }

   public synchronized void lockDisplayAndWait(int var1) {
      if (!this.framework.isSimulator()) {
         this.log.log(1000000, "DisplayManager: Displaymanager: lockDisplayAndWait %1", var1);
         if (this.dsiDispMgmt != null && this.initialized) {
            this.dsiDispMgmt.lockDisplay(var1);
            this.lastCallWasLock = true;

            try {
               this.waitForLock = true;
               this.wait(100L);
               this.log.log(10000000, "DisplayManager#lockDisplay now continue");
               this.waitForLock = false;
            } catch (InterruptedException var3) {
               this.log.log(10000, "interrupted while waiting for lock callback on terminal %1", var1);
               this.waitForLock = false;
            }
         } else {
            this.log.log(10000, "Displaymanager not initialized");
         }
      }
   }

   public void unlockDisplay(int var1) {
      if (!this.framework.isSimulator()) {
         this.log.log(1000000, "DisplayManager: Displaymanager: unlockDisplay %1", var1);
         if (!this.lastCallWasLock) {
            this.log.log(1000000, "DisplayManager: unlockDisplay not calling unlock because lock was not called before");
         } else {
            if (this.dsiDispMgmt != null && this.initialized) {
               this.dsiDispMgmt.unlockDisplay(var1);
               this.lastCallWasLock = false;
            } else {
               this.log.log(10000, "Displaymanager not initialized");
            }
         }
      }
   }

   public synchronized void unlockDisplayAndWait(int var1) {
      if (!this.framework.isSimulator()) {
         this.log.log(1000000, "DisplayManager: Displaymanager: unlockDisplayAndWait %1", var1);
         if (!this.lastCallWasLock) {
            this.log.log(1000000, "DisplayManager: unlockDisplayAndWait not calling unlock because lock was not called before");
         } else {
            if (this.dsiDispMgmt != null && this.initialized) {
               this.dsiDispMgmt.unlockDisplay(var1);
               this.lastCallWasLock = false;

               try {
                  this.waitForUnLock = true;
                  this.wait(100L);
                  this.log.log(10000000, "DisplayManager#unlockDisplay now continue");
                  this.waitForUnLock = false;
               } catch (InterruptedException var3) {
                  this.log.log(10000, "interrupted while waiting for unlock callback on terminal %1", var1);
                  this.waitForUnLock = false;
               }
            } else {
               this.log.log(10000, "Displaymanager not initialized");
            }
         }
      }
   }

   public synchronized int getCurrentContextID(int var1) {
      if (var1 < 0 || var1 >= 10) {
         this.log.log(1000000, "DisplayManager:getCurrentContextID terminal with ID: %1 is not a valid terminalID", var1);
         return -1;
      } else if (this.lastRequestAnswered[var1] && confirmedActiveContext[var1] != null) {
         return confirmedActiveContext[var1].getId();
      } else {
         return requestedContexts[var1] != null ? requestedContexts[var1].getId() : -1;
      }
   }

   public synchronized boolean refreshCarPlayKdkContext24() {
      return false;
   }

   public void setOpacity(int var1, int var2, int var3) {
      if (this.conflictsWithClusterOpacitySelection(var1, var2, var3)) {
         this.log.log(1000000, "DisplayManager#setOpacity preserving selected 33/62 opacity");
      } else if (!this.framework.isSimulator()) {
         if (this.mirror62MapHidden && var1 == 33 && (var2 == 1 || var2 == 4) && var3 != 0) {
            this.log.log(1000000, "DisplayManager#setOpacity suppressing visible map 33 while mirror 62 is active");
         } else {
            this.log.log(1000000, "DisplayManager#setOpacity displayable: %1, opacity: %2", var1, var3);
            int var4 = this.getInternalDisplayID(var2);
            this.log.log(10000000, "DisplayManager#setOpacity using internal terminal %1 for setOpacity", var4);
            if (displayableOpacities[var2][var1] != var3) {
               this.dsiDispMgmt.setOpacity(var1, var4, var3);
               displayableOpacities[var2][var1] = var3;
            } else {
               this.log.log(10000000, "DisplayManager#setOpacity displayable %1 on terminal %2 already has opacity %3", var1, var4, var3);
            }
         }
      }
   }

   public void fadeToOpacity(int var1, int var2, int var3, int var4) {
      if (this.conflictsWithClusterOpacitySelection(var1, var2, var3)) {
         this.log.log(1000000, "DisplayManager#fadeToOpacity preserving selected 33/62 opacity");
      } else if (this.mirror62MapHidden && var1 == 33 && (var2 == 1 || var2 == 4) && var3 != 0) {
         this.log.log(1000000, "DisplayManager#fadeToOpacity suppressing visible map 33 while mirror 62 is active");
      } else {
         if (this.dsiDispMgmt != null && this.initialized) {
            this.log.log(10000000, "DisplayManager#fadeToOpacity displayable: %1, opacity: %2, time: %3", var1, var3, var4);
            this.dsiDispMgmt.fadeToOpacity(var1, var2, var3, var4);
         } else {
            this.log.log(10000, "Displaymanager not initialized");
         }
      }
   }

   public void takeScreenshot(int var1, String var2) {
      this.log.log(1000000, "DisplayManager: Displaymanager: take s screenshot!");
      if (this.dsiDispMgmt != null && this.initialized) {
         int var3 = this.getInternalDisplayID(var1);
         this.log.log(10000000, "DisplayManager#takeScreenshot using internal terminal %1 for takeScreenShot", var3);
         this.dsiDispMgmt.takeScreenshot(var3, var2);
      } else {
         this.log.log(10000, "Displaymanager not initialized");
      }
   }

   public void dumpDisplayable(int var1, String var2) {
      this.log.log(1000000, "DisplayManager: Displaymanager: dumpDisplayable!");
      if (this.dsiDispMgmt != null && this.initialized) {
         this.dsiDispMgmt.dumpDisplayable(0, var1, var2);
      } else {
         this.log.log(10000, "Displaymanager not initialized");
      }
   }

   public void setDisplayBrightness(int var1, int var2) {
      if (this.dsiDispMgmt != null && this.initialized) {
         this.log.log(10000000, "DisplayManager.setDisplayBrightness displayID = %1, percentage = %2", var1, var2);
         int var3 = this.getInternalDisplayID(var1);
         this.log.log(10000000, "DisplayManager#setDisplayBrightness using internal terminal %1 for setDisplayBrightness", var3);
         this.dsiDispMgmt.setDisplayBrightness(var3, var2);
      } else {
         this.log.log(10000, "Displaymanager not initialized");
      }
   }

   public synchronized Object addingService(ServiceReference var1) {
      this.srDisplayManagement = var1;
      this.dsiDispMgmt = (DSIDisplayManagement)this.bc.getService(var1);
      this.initDSI();

      for (int var2 = 0; var2 < this.buffer.length; var2++) {
         int var5 = this.buffer[var2][1];
         if (var5 != -1) {
            this.log.log(1000000, "DisplayManager#addingService switching to buffered displayType %1 on terminal: %2", var5, var2);
            this.setDisplayType(var2, var5);
            this.buffer[var2][1] = -1;
         }

         int var4;
         if ((var4 = this.buffer[var2][0]) != -1) {
            this.log.log(1000000, "DisplayManager#addingService switching to buffered displayContext %1 on terminal: %2", var4, var2);
            this.switchContext(var4, var2, this.displayListeners[var2]);
            this.buffer[var2][0] = -1;
         }

         int var3;
         if ((var3 = this.buffer[var2][2]) != -1) {
            this.log.log(1000000, "DisplayManager#addingService switching to buffered updateRate %1 on terminal: %2", var3, var2);
            this.setUpdateRate(var2, var3);
            this.buffer[var2][2] = -1;
         }
      }

      this.displayManagementIsAvailable();
      return this.dsiDispMgmt;
   }

   public void modifiedService(ServiceReference var1, Object var2) {
   }

   public void removedService(ServiceReference var1, Object var2) {
      this.bc.ungetService(var1);
      this.srDisplayManagement = null;
      this.dsiDispMgmt = null;
      this.initialized = false;
   }

   public void start(BundleContext var1) {
      this.log.log(10000000, "start");
      this.bc = var1;
      Hashtable var2 = new Hashtable();
      var2.put("DEVICE_NAME", DSIDisplayManagementListener.class.getName());
      var2.put("DEVICE_INSTANCE", new Integer(0));
      this.dsiDisplayManagementListener = new DSIDisplayListener(this);
      this.srDSIDisplayManagementListener = var1.registerService(DSIListener.class.getName(), this.dsiDisplayManagementListener, var2);
      this.displayManagerTracker = new ServiceTracker(this.bc, DSIDisplayManagement.class.getName(), this);
      this.displayManagerTracker.open();
      if (this.framework.isTarget()) {
         this.waitForDSIDisplayManagement();
      }
   }

   public void stop(BundleContext var1) {
      this.initialized = false;
      if (this.displayManagerTracker != null) {
         this.displayManagerTracker.close();
         this.displayManagerTracker = null;
      }

      if (this.srDisplayManagement != null) {
         var1.ungetService(this.srDisplayManagement);
         this.srDisplayManagement = null;
         this.dsiDispMgmt = null;
      }

      if (this.srDSIDisplayManagementListener != null) {
         this.srDSIDisplayManagementListener.unregister();
         this.srDSIDisplayManagementListener = null;
      }
   }

   public void setPosition(int var1, int var2, int var3, int var4) {
      if (!this.framework.isSimulator()) {
         if (this.dsiDispMgmt != null && this.initialized) {
            if (var1 == 33 && (var2 == 1 || var2 == 4)) {
               this.updateAltScreenSportLayout(var3);
            }

            this.log.log(1000000, "DisplayManager#setPosition displayable: %1, xPos: %2 , yPos: %3", var1, var3, var4);
            int var5 = this.getInternalDisplayID(var2);
            this.log.log(10000000, "DisplayManager#setPosition using internal terminal %1 for setPosition", var5);
            if (displayablePositions[var2][var1][0] == var3 && displayablePositions[var2][var1][1] == var4) {
               this.log.log(10000000, "DisplayManager#setPosition displayable %1 on terminal %2 already has desired position", var1, var5);
            } else {
               this.dsiDispMgmt.setPosition(var1, var5, var3, var4);
               displayablePositions[var2][var1][0] = var3;
               displayablePositions[var2][var1][1] = var4;
            }

            if (var1 == 20 && var2 == 7 && var3 == 0 && var4 == 0 && clusterRgiRelocEnabled()) {
               try {
                  int[] var6 = this.clusterRgiPosition();
                  this.dsiDispMgmt.setPosition(20, this.getInternalDisplayID(4), var6[0], var6[1]);
                  this.dsiDispMgmt.setOpacity(20, this.getInternalDisplayID(4), 100);
                  displayablePositions[4][20][0] = var6[0];
                  displayablePositions[4][20][1] = var6[1];
                  displayableOpacities[4][20] = 100;
               } catch (Throwable var7) {
               }
            }
         } else {
            this.log.log(10000, "Displaymanager not initialized");
         }
      }
   }

   public int[] getPosition(int var1, int var2) {
      return displayablePositions[var2][var1];
   }

   public int getOpacity(int var1, int var2) {
      return displayableOpacities[var2][var1];
   }

   protected synchronized void showDisplayablesResult(int var1, int[] var2, int var3, int var4) {
      int var5 = this.getHmiTerminalID(var1);
      this.log.log(1000000, "DisplayManager#showDisplayablesResult confirmed displayables: %1 for terminal %2", var2, var5);
      if (this.sessionIDs[var5] != var4 && var4 > 0) {
         this.log
            .log(
               100000,
               "DisplayManager#showDisplayablesResult displayables for terminal: %1 is confirmed for sessionID: %2, but newest session is: %3",
               var5,
               var4,
               this.sessionIDs[var5]
            );
      } else if (requestedContexts[var5] != null && var2 != null) {
         int[] var7 = requestedContexts[var5].displayableList;
         boolean var8 = var5 == 1 && this.mirror62Requested && this.isClusterMirrorDisplayableList(var7);
         boolean var6 = var7.length == var2.length;
         if (var6) {
            for (int var10 = 0; var10 < var7.length; var10++) {
               if (var7[var10] != var2[var10]) {
                  var6 = false;
               }
            }
         }

         confirmedActiveContext[var5] = var6 ? requestedContexts[var5] : new DisplayContext(-1, var2);
         this.lastRequestAnswered[var5] = true;
         if (var8) {
            this.mirror62Active = this.isClusterMirrorDisplayableList(var2);
            if (this.mirror62Active) {
               this.mirror62MapHidden = true;
               this.applyClusterOpacitySelection(clusterMap33Selected);
               this.log.log(1000000, "DisplayManager#OEM cluster context confirmed with mirror 62");
            } else {
               this.mirror62MapHidden = true;
               this.setClusterDisplayableOpacity(33, 0);
               this.setClusterDisplayableOpacity(62, 100);
               this.log.log(1000000, "DisplayManager#OEM map context did not confirm mirror 62; keeping map 33 hidden for retry");
            }
         }

         if (this.displayListeners[var5] != null) {
            ActiveContextEvent var11 = new ActiveContextEvent(this, var5, confirmedActiveContext[var5].id, var4, this.displayListeners[var5]);
            this.log
               .log(
                  10000000,
                  "DisplayManager#processEvent confirmation for context: %1 for external terminal %2 arrived, now post event to give callback in dispatch thread",
                  confirmedActiveContext[var5].id,
                  var5
               );
            this.framework.getHMIService().getEventDispatcher().postEvent(var11);
         }
      }

      this.notifyAll();
   }

   protected synchronized void deferUpdatesResult(int var1, int var2, int var3) {
      this.log.log(1000000, "DisplayManager#deferUpdatesResult received for display: %1 and displayable: %2 resultCode: %3", var1, var2, var3);
      if (!this.waitForDeferUpdates) {
         this.log.log(10000000, "DisplayManager#deferUpdatesResult received but not waiting for result any more");
      } else {
         this.notifyAll();
      }
   }

   protected synchronized void lockDisplayResult(int var1) {
      this.log.log(1000000, "DisplayManager#lockDisplayResult received resultCode: %1", var1);
      if (!this.waitForLock) {
         this.log.log(10000000, "DisplayManager#lockDisplayResult received but not waiting for result any more");
      } else {
         this.notifyAll();
      }
   }

   protected synchronized void unlockDisplayResult(int var1) {
      this.log.log(1000000, "DisplayManager#unlockDisplayResult received resultCode: %1", var1);
      if (!this.waitForUnLock) {
         this.log.log(10000000, "DisplayManager#unlockDisplayResult received but not waiting for result any more");
      } else {
         this.notifyAll();
      }
   }

   public synchronized void processEvent(ATIPEvent var1) {
      int var2 = ((ActiveContextEvent)var1).getSessionID();
      int var3 = ((ActiveContextEvent)var1).getTerminal();
      int var4 = ((ActiveContextEvent)var1).getActiveContext();
      if (this.log.isDebug()) {
         this.log.log(10000000, "DisplayManager#processEvent process delayed confirmed context: %1 for external terminal %2", var4, var3);
      }

      if (var2 == this.sessionIDs[var3]) {
         IDisplayListener var5 = ((ActiveContextEvent)var1).getDisplayListener();
         int var6 = ((ActiveContextEvent)var1).getActiveContext() % 100;
         var5.activeContext(var6, var3);
      } else if (this.log.isDebug()) {
         this.log
            .log(
               10000000,
               "DisplayManager#processEvent delayed confirmed context: %1 for external terminal %2 has old sessionID,  is not processed further",
               var4,
               var3
            );
      }
   }

   protected abstract void defineContexts();

   public void setDisplayType(int var1, int var2) {
      if (this.dsiDispMgmt != null && this.initialized) {
         int var3 = this.getInternalDisplayID(var1);
         this.log.log(1000000, "DisplayManager.setDisplayType terminalId = %1, type = %2, displayId = %3", var1, var2, var3);
         this.dsiDispMgmt.setDisplayType(var3, var2);
         this.buffer[var1][1] = -1;
      } else {
         this.log.log(10000, "Displaymanager not initialized");
         this.buffer[var1][1] = var2;
      }
   }

   public void setUpdateRate(int var1, int var2) {
      if (this.dsiDispMgmt != null && this.initialized) {
         int var3 = this.getInternalDisplayID(var1);
         this.log.log(1000000, "DisplayManager.setUpdateRate terminalId = %1, updateRate = %2, displayId = %3", var1, var2, var3);
         this.dsiDispMgmt.setUpdateRate(var3, var2);
         this.buffer[var1][2] = -1;
      } else {
         this.log.log(10000, "Displaymanager not initialized");
         this.buffer[var1][2] = var2;
      }
   }

   public void createImageDisplayable(ResourceLocator var1, int var2) {
      if (this.dsiDispMgmt != null) {
         this.log.log(1000000, "DisplayManager.createImageDisplayable displayable = %2, path = %1", var1.getUrl(), var2);
         this.dsiDispMgmt.createImageDisplayable(var1, var2);
      } else {
         this.log.log(10000, "Displaymanager not initialized");
      }
   }

   public int[] getExtends(int var1) {
      this.log.log(10000000, "DisplayManager.getExtends displayable = %1", var1);
      Object var2 = this.displayableExtents.get(new Integer(var1));
      if (var2 != null) {
         return (int[])var2;
      }

      this.dsiDispMgmt.getExtents(var1);
      return null;
   }

   public void setCropping(int var1, int var2, int var3, int var4, int var5, int var6, int var7, int var8, int var9, int var10) {
      if (!this.framework.isSimulator()) {
         if (this.dsiDispMgmt != null && this.initialized) {
            this.log.log(1000000, "DisplayManager#setCropping displayable: %1, srcX: %2, srcY: %3", var1, var3, var4);
            int var11 = this.getInternalDisplayID(var2);
            this.log.log(10000000, "DisplayManager#setCropping using internal terminal %1 for setCropping", var11);
            this.dsiDispMgmt.setCropping(var2, var1, var3, var4, var5, var6, var7, var8, var9, var10);
            displayablePositions[var2][var1][0] = var7;
            displayablePositions[var2][var1][1] = var8;
         } else {
            this.log.log(10000, "Displaymanager#setCropping dm not initialized");
         }
      }
   }

   public void declareContexts(Context[] var1) {
      if (var1 != null) {
         this.dc = new DisplayContext[var1.length];

         for (int var2 = 0; var2 < this.dc.length; var2++) {
            if (var1[var2] != null) {
               this.dc[var2] = new DisplayContext(var1[var2].getContextID(), var1[var2].getDisplayableList());
            }
         }
      }
   }

   public synchronized void deferUpdates(int var1, int var2) {
      if (!this.framework.isSimulator()) {
         if (this.dsiDispMgmt != null && this.initialized) {
            this.log.log(1000000, "DisplayManager#deferUpdates terminal: %1 displayable: %2", var1, var2);
            int var3 = this.getInternalDisplayID(var1);
            this.log.log(10000000, "DisplayManager#deferUpdates using internal terminal %1 for deferUpdates", var3);
            this.dsiDispMgmt.deferUpdates(var3, var2);

            try {
               this.waitForDeferUpdates = true;
               this.wait(100L);
               this.log.log(10000000, "DisplayManager#deferUpdates now continue");
               this.waitForDeferUpdates = false;
            } catch (InterruptedException var5) {
               this.log.log(10000, "interrupted while waiting for deferUpdates callback on terminal %1", var1);
               this.waitForDeferUpdates = false;
            }
         } else {
            this.log.log(10000, "Displaymanager#deferUpdates dm not initialized");
         }
      }
   }

   public void createImageDisplayable(String var1, int var2) {
      if (!this.framework.isSimulator()) {
         if (this.dsiDispMgmt != null && this.initialized) {
            this.log.log(10000000, "DisplayManager#createImageDisplayable displayableID: %1 imagePath: %2", new Integer(var2), var1);
            ResourceLocator var3 = new ResourceLocator(var1);
            this.dsiDispMgmt.createImageDisplayable(var3, var2);
         } else {
            this.log.log(10000, "Displaymanager#createImageDisplayable dm not initialized");
         }
      }
   }

   static {
      initializeDisplayableMapping();

      for (int var1 = 0; var1 < displayableOpacities.length; var1++) {
         for (int var0 = 0; var0 < displayableOpacities[var1].length; var0++) {
            displayableOpacities[var1][var0] = 100;
         }
      }

      for (int var3 = 0; var3 < displayablePositions.length; var3++) {
         for (int var2 = 0; var2 < displayablePositions[var3].length; var2++) {
            displayablePositions[var3][var2] = var3 != 1 && var3 != 7 ? new int[]{0, 0} : new int[]{-1, -1};
         }
      }
   }

   private static int[] withoutPhoneCard(int[] var0) {
      if (var0 == null) {
         return null;
      }

      int var1 = 0;

      for (int var5 : var0) {
         if (var5 != 20) {
            var1++;
         }
      }

      int[] var8 = new int[var1];
      int var9 = 0;

      for (int var7 : var0) {
         if (var7 != 20) {
            var8[var9++] = var7;
         }
      }

      return var8;
   }
}
