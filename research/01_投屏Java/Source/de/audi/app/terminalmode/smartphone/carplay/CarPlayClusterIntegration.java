// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.app.car.api.core.ICarCoreServices;
import de.audi.app.car.api.services.ICarExteriorLightService;
import de.audi.app.terminalmode.IContext;
import de.audi.atip.base.IFrameworkAccess;
import de.audi.atip.hmi.HMIService;
import de.audi.atip.interapp.combi.bap.PartialPopupBAPService;
import de.audi.atip.interapp.combi.bap.navi.CombiBAPServiceNavi;
import de.audi.atip.interapp.combi.bap.navi.data.CombiBAPNaviLaneGuidanceData;
import de.audi.atip.interapp.combi.bap.navi.data.CombiBAPNaviManeuverDescriptor;
import de.audi.atip.interapp.combi.bap.navi.data.CurrentPositionInfo;
import de.audi.atip.utils.reactive.properties.ReadOnlyProperty;
import de.audi.mib.system.ISysServices;
import de.audi.mib.system.units.IUnitManager;
import de.audi.mib.system.units.IUnitProvider;
import de.audi.mib.system.units.UnitSetting;
import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TimeZone;
import java.util.Timer;
import org.dsi.ifc.carplay.AppState;
import org.dsi.ifc.carplay.CallState;
import org.dsi.ifc.carplay.DSICarplayListener;
import org.dsi.ifc.carplay.DeviceInfo;
import org.dsi.ifc.carplay.PlaybackInfo;
import org.dsi.ifc.carplay.Resource;
import org.dsi.ifc.carplay.TelephonyState;
import org.dsi.ifc.carplay.TrackData;
import org.dsi.ifc.global.ResourceLocator;
import org.dsi.ifc.nav.BapManeuverDescriptor;
import org.dsi.ifc.nav.BapTurnToInfo;
import org.osgi.framework.ServiceReference;

public class CarPlayClusterIntegration implements DSICarplayListener {
   private static final int RESOURCE_MAIN_SCREEN = 1;
   private static final int RESOURCEOWNER_MAINUNIT = 1;
   private static final int RESOURCEOWNER_DEVICE = 2;
   private String mirrorFifo = "/tmp/cluster_ctl";
   private static final String MIRROR_STATE_FILE = "/tmp/cluster_mirror.state";
   private static final String CLUSTER_ZOOM_CONTROL_FILE = "/tmp/carplay_cluster_zoom.ctl";
   private static final String JAVA_READY_FILE = "/tmp/cluster_java.ready";
   private static final String PHONE_ETA_FILE = "/tmp/carplay_phone_eta.ctl";
   private static final String DISPLAY_MANAGER_ENABLE_MIRROR = "activateClusterMirror62";
   private static final String DISPLAY_MANAGER_IS_MIRROR_ACTIVE = "isClusterMirror62Active";
   private static final String DISPLAY_MANAGER_REFRESH_MIRROR = "refreshClusterMirror62ThroughCurrentContext";
   private static final String DISPLAY_MANAGER_RESTORE_MAP = "restoreClusterMapFromMirror62";
   private static final String MAP_CLUSTER_SERVICE_CLASS = "de.audi.tghu.navi.app.cluster.IMapClusterService";
   private static final String FPK_ACTION_PROXY_CLASS = "de.audi.atip.statemachine.ActionProxy";
   private static final String FPK_MAP_ENTERED_METHOD = "onMapScreenEntered";
   private static final String FPK_MODULE_ID_PROPERTY = "moduleID";
   private static final int FPK_NAVI_MODULE_ID = 30;
   private static final long MIRROR_STOP_POLL_MS = 200L;
   private static final long MIRROR_START_POLL_MS = 100L;
   private static final int MIRROR_STOP_MAX_POLLS = 35;
   private static final int MIRROR_RELEASE_MAX_POLLS = 75;
   private static final long MIRROR_COMPOSITION_SETTLE_MS = 150L;
   private static final long MIRROR_COMPOSITION_HEALTH_MS = 500L;
   private static final long MIRROR_COMPOSITION_HEALTH_WINDOW_MS = 15000L;
   private static final long MAP_RESTORE_DELAY_MS = 300L;
   private String mirrorMode = "stretch";
   private float mirrorZoomX = 1.0F;
   private float mirrorZoomY = 1.0F;
   private float mirrorPanX = 0.0F;
   private float mirrorPanY = 0.0F;
   private int mirrorXres = 1920;
   private int mirrorYres = 600;
   private boolean enableMapRender = true;
   private static final int CL_IDLE = 0;
   private static final int CL_STARTING = 1;
   private static final int CL_RENDERING = 2;
   private volatile int clusterState = 0;
   private final IContext context;
   private final Timer mirrorLifecycleTimer = new Timer(true);
   private Object mapClusterService = null;
   private Object displayManagerService = null;
   private boolean mirrorCompositionArmed = false;
   private boolean mirrorCompositionActive = false;
   private long mirrorCompositionHealthDeadline = 0L;
   private Object fpkMapActionProxy = null;
   private boolean mapHiddenByCarplay = false;
   private boolean mapRestorePending = false;
   private boolean displayOff = false;
   private boolean atomicMirrorRenameUnsupported = false;
   private long mirrorLifecycleGeneration = 0L;
   private long mirrorRequestSequence = 0L;
   private long clusterZoomSequence = 0L;
   private static volatile CarPlayClusterIntegration activeClusterIntegration = null;
   private ISysServices sysServices = null;
   private ICarCoreServices carCoreServices = null;
   private ICarExteriorLightService exteriorLightService = null;
   private PartialPopupBAPService popupService = null;
   private boolean unitsDetermined = false;
   private boolean useMetricCached = true;
   private boolean driveSideDetermined = false;
   private boolean isRHD = false;
   private String resolvedImperialSmallUnit = null;
   private String sessionId = null;
   private boolean forceImperial = false;
   private int metricUnitThreshold = 1000;
   private int imperialUnitThreshold = 161;
   private String imperialSmallUnit = "auto";
   private boolean useMetric = true;
   private int maneuverStateMask = 11;
   private boolean enableRoundaboutLatching = true;
   private boolean enableHeartbeat = true;
   private int heartbeatInterval = 2000;
   private String bargraphMode = "auto";
   private int dynamicBargraphDistance = 100;
   private int dynamicBargraphPercent = 50;
   private int destinationDisplayDuration = 5000;
   private CombiBAPServiceNavi clusterService = null;
   private volatile boolean rgActive = false;
   private volatile boolean carplaySessionActive = false;
   private int lastMainScreenOwner = -1;
   private int lastMainElement = -1;
   private int lastDirection = -1;
   private byte[] lastSideStreets = new byte[0];
   private String lastRoadName = "";
   private String lastSignPost = "";
   private int lastLaneCount = 0;
   private CombiBAPNaviLaneGuidanceData[] lastLanesCached = null;
   private String lastLaneSignature = "";
   private int lastDistanceM = -1;
   private int lastDistUnit = 0;
   private int lastDistValue = 0;
   private int lastBargraph = 0;
   private boolean lastBargraphEnabled = false;
   private int maneuverInitialDistance = 0;
   private int lastManeuverType = -1;
   private int lastManeuverStateBAP = -1;
   private int lastTimeToDestSec = 0;
   private int lastDistToDestM = 0;
   private long lastDistUpdateTime = 0L;
   private long destinationShownTime = 0L;
   private boolean inRoundabout = false;
   private int cachedRoundaboutDirection = -1;
   private int lastRoundaboutManeuverType = -1;
   private Timer pendingClearTimer = null;
   private int lastCurrentSlotIapIdx = -1;
   private boolean startupPopupShown = false;
   private final boolean deviceAuthorized;
   private int veryFarBoundary = 5000;
   private int farBoundary = 1000;
   private int approachingBoundary = 500;
   private int nearBoundary = 200;
   private int closeBoundary = 100;
   private int veryCloseBoundary = 50;
   private int veryFarDistanceThreshold = 100;
   private int farDistanceThreshold = 50;
   private int approachingDistanceThreshold = 25;
   private int nearDistanceThreshold = 15;
   private int closeDistanceThreshold = 15;
   private int veryCloseDistanceThreshold = 10;
   private int nowDistanceThreshold = 5;
   private int veryFarRateLimit = 2000;
   private int farRateLimit = 500;
   private int approachingRateLimit = 250;
   private int nearRateLimit = 200;
   private int closeRateLimit = 150;
   private int veryCloseRateLimit = 120;
   private int nowRateLimit = 100;
   private boolean rgiBoxAsked = false;
   private boolean rgiBoxGranted = false;
   private static final int ACTIVE_RG_TYPE_LVDS_KDK = 4;
   private static final int ACTIVE_RG_TYPE_DEFAULT = 255;
   private static final String NAVI_CLUSTER_EXTENSION_IFACE = "de.audi.tghu.navi.app.cluster.INaviClusterExtension";
   private static final String NAVI_CLUSTER_COMMON_CLASS = "de.audi.tghu.navi.app.cluster.NaviClusterCommonExtension";
   private static final String NAVI_SERVICE_WRAPPER_CLASS = "de.audi.tghu.navi.app.util.AbstractNaviServiceWrapper";
   private Object naviClusterCommon = null;
   private boolean bapRgiFunctionsOpened = false;
   private boolean bapRgiPresentationEntered = false;
   private boolean kdkViewStateActive = false;
   private int kdkReadyGeneration = 0;
   private boolean kdkPreviousStateValid = false;
   private boolean kdkPreviousViewModeStateValid = false;
   private boolean kdkPreviousRgActive = false;
   private boolean kdkPreviousKomoVisible = false;
   private boolean kdkPreviousKomoEnabled = false;
   private boolean kdkPreviousFadeOut = false;
   private Object kdkPreviousIntendedViewMode = null;
   private boolean kdkPreviousSmRgActive = false;
   private boolean kdkPreviousSmKomoVisible = false;
   private boolean kdkPreviousSmKomoEnabled = false;
   private boolean kdkPreviousGfxAvailable = false;
   private int kdkPreviousDataRate = 0;
   private boolean clusterPageRefreshedForRoute = false;
   private long nativeMirrorProcess = -1L;
   private long nativeMirrorStream = 0L;
   private static final int ZONE_VERY_FAR = 0;
   private static final int ZONE_FAR = 1;
   private static final int ZONE_APPROACHING = 2;
   private static final int ZONE_NEAR = 3;
   private static final int ZONE_CLOSE = 4;
   private static final int ZONE_VERY_CLOSE = 5;
   private static final int ZONE_NOW = 6;
   private static final int INFO_STATE_NAV_IN_MOBILE_DEVICE = 6;
   private static final boolean BAP_CLAIM_NAV_ON_PHONE = false;
   private int rgTypeLastPublished = -1;
   private long rgTypePhaseStartMs = 0L;
   private int fedMainElement = Integer.MIN_VALUE;
   private int fedDirection = Integer.MIN_VALUE;
   private String fedRoadName = null;
   private String fedSignPost = null;
   private int fedManeuverM = Integer.MIN_VALUE;
   private int fedDestM = Integer.MIN_VALUE;
   private int fedTimeSec = Integer.MIN_VALUE;
   private boolean directionForcedOnce = false;
   private Thread heartbeatThread = null;
   private volatile boolean heartbeatRunning = false;
   private static final String PPS_RG_PATH = "/tmp/cluster_cp.state";
   private volatile Thread ppsReaderThread = null;
   private volatile boolean ppsReaderStop = false;
   private int lastRouteState = -1;
   private int lastManeuverDistance = -1;
   private int lastDistanceRemaining = -1;
   private int lastTimeRemaining = -1;
   private long lastEstimatedArrival = -1L;
   private int lastDrivingSide = -1;
   private int lastJunctionType = -1;
   private int lastExitAngle = 0;
   private int lastSourceSupportsRg = -1;
   private String lastDestination = null;
   private String lastManeuverDescription = null;
   private String lastManeuverRoad = null;
   private String lastExitInfo = null;
   private String lastJunctionAnglesCsv = null;
   private static final boolean KOMO_FEED_NAVINFO = true;
   private static final boolean forceKomoVisible = false;
   private String lastKomoStreet = null;
   private String lastKomoTurnTo = null;
   private String lastKomoCity = null;
   private int lastKomoDistValue = Integer.MIN_VALUE;
   private int lastKomoDistUnit = Integer.MIN_VALUE;
   private int lastKomoDestDist = Integer.MIN_VALUE;

   public CarPlayClusterIntegration(IContext var1) {
      this.context = var1;
      this.deviceAuthorized = DeviceBinding.isAuthorized();
      if (this.deviceAuthorized) {
         activeClusterIntegration = this;
      }
   }

   public void loadConfig() {
   }

   private static Object readField(Object var0, String var1) {
      if (var0 == null) {
         return null;
      }

      Class var2 = var0.getClass();

      while (var2 != null) {
         try {
            Field var3 = var2.getDeclaredField(var1);
            var3.setAccessible(true);
            return var3.get(var0);
         } catch (NoSuchFieldException var4) {
            var2 = var2.getSuperclass();
         } catch (Throwable var5) {
            return null;
         }
      }

      return null;
   }

   private static Object call(Object var0, String var1, Class[] var2, Object[] var3) {
      if (var0 == null) {
         return null;
      }

      Class var4 = var0.getClass();

      while (var4 != null) {
         try {
            Method var5 = var4.getDeclaredMethod(var1, var2);
            var5.setAccessible(true);
            return var5.invoke(var0, var3);
         } catch (NoSuchMethodException var6) {
            var4 = var4.getSuperclass();
         } catch (Throwable var7) {
            return "<threw " + var7 + ">";
         }
      }

      return null;
   }

   private static Object call(Object var0, String var1) {
      return call(var0, var1, new Class[0], new Object[0]);
   }

   private static String str(Object var0) {
      return var0 == null ? "null" : var0.toString();
   }

   public void setSysServices(ISysServices var1) {
      this.sysServices = var1;
      this.unitsDetermined = false;
   }

   public void setCarCoreServices(ICarCoreServices var1) {
      this.carCoreServices = var1;
      this.driveSideDetermined = false;
   }

   public void setExteriorLightService(ICarExteriorLightService var1) {
      this.exteriorLightService = var1;
   }

   public void setPopupService(PartialPopupBAPService var1) {
      this.popupService = var1;
   }

   public void unsetClusterService(CombiBAPServiceNavi var1) {
      this.clusterService = null;
   }

   public void init() {
      if (this.deviceAuthorized) {
         this.sessionId = this.generateSessionId();
         this.startPpsListener();
         this.publishJavaReady();
      }
   }

   private void publishPhoneEta(long var1, int var3) {
      FileWriter var4 = null;
      if (var1 > 0L) {
         try {
            long var5 = var1;
            if (var3 >= 0 && var1 >= var3) {
               long var7 = var1 - var3;
               var5 = var7 / 60L * 60L + var3 / 60L * 60L;
            }

            SimpleDateFormat var19 = new SimpleDateFormat("HH mm");
            var19.setTimeZone(TimeZone.getTimeZone("GMT+08:00"));
            var4 = new FileWriter("/tmp/carplay_phone_eta.ctl", false);
            var4.write(var19.format(new Date(var5 * 1000L)));
            var4.write(" ");
            var4.write(String.valueOf(var1));
            var4.write("\n");
            var4.flush();
         } catch (Throwable var17) {
         } finally {
            if (var4 != null) {
               try {
                  var4.close();
               } catch (Throwable var16) {
               }
            }
         }
      }
   }

   private String generateSessionId() {
      Random var1 = new Random();
      String var2 = String.valueOf(var1.nextInt(99999));

      while (var2.length() < 5) {
         var2 = "0" + var2;
      }

      return var2;
   }

   private void publishJavaReady() {
      FileWriter var1 = null;

      try {
         var1 = new FileWriter("/tmp/cluster_java.ready", false);
         var1.write("ready\n");
         var1.flush();
      } catch (Exception var11) {
      } finally {
         if (var1 != null) {
            try {
               var1.close();
            } catch (Exception var10) {
            }
         }
      }
   }

   private boolean shouldUseMetric() {
      if (this.unitsDetermined) {
         return this.useMetricCached;
      }

      if (this.forceImperial) {
         this.useMetricCached = false;
         this.unitsDetermined = true;
         return false;
      }

      if (this.sysServices != null) {
         try {
            IUnitManager var1 = this.sysServices.units();
            if (var1 != null) {
               IUnitProvider var2 = var1.distance();
               if (var2 != null) {
                  ReadOnlyProperty var3 = var2.setting();
                  if (var3 != null) {
                     UnitSetting var4 = (UnitSetting)var3.get();
                     if (var4 != null) {
                        int var5 = var4.getUnitValue();
                        if (var5 == 1) {
                           this.useMetricCached = true;
                           this.unitsDetermined = true;
                           return true;
                        }

                        if (var5 == 2) {
                           this.useMetricCached = false;
                           this.unitsDetermined = true;
                           return false;
                        }
                     }
                  }
               }

               IUnitProvider var9 = var1.speed();
               if (var9 != null) {
                  ReadOnlyProperty var10 = var9.setting();
                  if (var10 != null) {
                     UnitSetting var11 = (UnitSetting)var10.get();
                     if (var11 != null) {
                        int var6 = var11.getUnitValue();
                        if (var6 == 1) {
                           this.useMetricCached = true;
                           this.unitsDetermined = true;
                           return true;
                        }

                        if (var6 == 2) {
                           this.useMetricCached = false;
                           this.unitsDetermined = true;
                           return false;
                        }
                     }
                  }
               }
            }
         } catch (Exception var7) {
         }
      }

      String var8 = this.getCountryCode();
      if (var8 != null && var8.length() > 0) {
         this.useMetricCached = !isImperialCountry(var8);
         this.unitsDetermined = true;
         return this.useMetricCached;
      } else {
         this.useMetricCached = true;
         return true;
      }
   }

   public boolean isDriveRightHandSide() {
      if (this.driveSideDetermined) {
         return this.isRHD;
      }

      if (this.carCoreServices != null) {
         try {
            ReadOnlyProperty var1 = this.carCoreServices.configuration().airConditionMaster().driverSideLeft();
            if (var1 != null) {
               Boolean var2 = (Boolean)var1.get();
               if (var2 != null) {
                  this.isRHD = !var2;
                  this.driveSideDetermined = true;
                  return this.isRHD;
               }
            }
         } catch (Exception var3) {
         }
      }

      String var4 = this.getCountryCode();
      if (var4 != null && var4.length() > 0) {
         this.isRHD = isRightHandDriveCountry(var4);
         this.driveSideDetermined = true;
         return this.isRHD;
      } else {
         return false;
      }
   }

   private String getCountryCode() {
      try {
         String var1 = System.getProperty("REGION");
         if (var1 != null && var1.length() >= 2) {
            return var1.substring(0, 2).toUpperCase();
         }
      } catch (Exception var2) {
      }

      return null;
   }

   private static boolean countryIn(String var0, String var1) {
      return var1 != null && var0.indexOf("," + var1 + ",") >= 0;
   }

   private static boolean isImperialCountry(String var0) {
      return countryIn(",AG,BS,BB,BM,KY,DM,FK,GD,KN,LC,VC,GB,US,VG,VI,LR,MM,", var0);
   }

   private static boolean isRightHandDriveCountry(String var0) {
      return countryIn(
         ",AG,AU,BS,BB,BD,BM,BT,BW,BN,KY,CY,DM,TL,FK,FJ,GD,GY,HK,IN,ID,IE,JM,JP,KE,KI,LS,MO,MW,MY,MV,MT,MU,MZ,NA,NR,NP,NZ,PK,PG,SG,ZA,LK,KN,LC,VC,SR,SZ,TZ,TH,TO,TT,UG,GB,VG,VI,ZM,ZW,",
         var0
      );
   }

   private String resolveImperialSmallUnit() {
      if (this.resolvedImperialSmallUnit != null) {
         return this.resolvedImperialSmallUnit;
      } else if (!"auto".equals(this.imperialSmallUnit)) {
         this.resolvedImperialSmallUnit = this.imperialSmallUnit;
         return this.resolvedImperialSmallUnit;
      } else {
         String var1 = this.getCountryCode();
         if (countryIn(",US,LR,MM,", var1)) {
            this.resolvedImperialSmallUnit = "feet";
            return "feet";
         } else {
            this.resolvedImperialSmallUnit = "yards";
            return "yards";
         }
      }
   }

   public void onResourceChanged(int var1, int var2) {
      if (this.deviceAuthorized) {
         if (var1 == 1) {
            this.handleScreenOwnerChange(var2);
         }
      }
   }

   public void updateMode(Resource[] var1, AppState[] var2, int var3) {
      if (this.deviceAuthorized) {
         if (var1 != null) {
            for (int var4 = 0; var4 < var1.length; var4++) {
               if (var1[var4].getResourceID() == 1) {
                  this.handleScreenOwnerChange(var1[var4].getOwner());
               }
            }
         }
      }
   }

   private void handleScreenOwnerChange(int var1) {
      long var2 = -1L;
      boolean var4 = false;
      boolean var5 = var1 == 2 && this.isMirrorStateAck("-", "bridge");
      synchronized (this) {
         boolean var7 = var1 == 2 && this.lastMainScreenOwner == 1 && this.clusterState == 0;
         if (var1 == 1 || var1 == 2) {
            this.lastMainScreenOwner = var1;
         }

         if (var1 == 2 && (!this.carplaySessionActive || var5 || var7)) {
            this.carplaySessionActive = true;
            var2 = ++this.mirrorLifecycleGeneration;
            if (this.clusterState != 0) {
               this.clusterState = 0;
            }

            this.mapRestorePending = false;
            var4 = true;
         } else if (var1 == 1 && this.carplaySessionActive) {
         }
      }

      if (var4) {
         this.scheduleCarplayEnter(var2);
      }
   }

   public void onCarplayTerminated() {
      long var1;
      synchronized (this) {
         this.carplaySessionActive = false;
         var1 = ++this.mirrorLifecycleGeneration;
      }

      this.closeBapRgiFunctions();
      this.scheduleMirrorStop(var1, true, "terminated-restore-map");
   }

   public void onDisplayOffChanged(boolean var1) {
      if (this.deviceAuthorized) {
         boolean var4 = false;
         boolean var5 = false;
         boolean var6 = false;
         long var2;
         synchronized (this) {
            if (this.displayOff == var1) {
               return;
            }

            this.displayOff = var1;
            var2 = ++this.mirrorLifecycleGeneration;
            if (this.displayOff) {
               var4 = this.clusterState == 2 || this.mapHiddenByCarplay;
            } else {
               var6 = this.carplaySessionActive;
               var5 = !this.carplaySessionActive && this.mapHiddenByCarplay;
            }
         }

         if (var4) {
            this.scheduleMirrorStop(var2, false, "display-off");
         } else if (var6) {
            this.scheduleCarplayEnter(var2);
         } else if (var5) {
            this.scheduleMirrorStop(var2, false, "display-on-overlay");
         }
      }
   }

   private void scheduleCarplayEnter(long var1) {
      this.mirrorLifecycleTimer.schedule(new CarPlayClusterIntegration$1(this, var1), 0L);
   }

   private void enterCarplayMirror(long var1) {
      synchronized (this) {
         if (var1 != this.mirrorLifecycleGeneration || !this.carplaySessionActive || this.displayOff || !this.enableMapRender) {
            return;
         }
      }

      if (new File(this.mirrorFifo).exists()) {
         synchronized (this) {
            if (var1 != this.mirrorLifecycleGeneration || !this.carplaySessionActive || this.displayOff) {
               long var11 = this.mirrorLifecycleGeneration;
               this.scheduleMirrorStop(var11, false, "enter-raced-overlay");
               return;
            }

            if (this.clusterState != 0) {
               return;
            }
         }

         String var3 = this.nextMirrorRequest();
         String var4 = this.buildMirrorArgs();
         if (this.sendMirrorDesiredState(var3, "rendering", var4)) {
            synchronized (this) {
               if (var1 == this.mirrorLifecycleGeneration && this.carplaySessionActive && !this.displayOff) {
                  this.clusterState = 1;
                  this.mirrorCompositionHealthDeadline = 0L;
               }
            }

            this.pollMirrorRegistered(var1, var3, 0);
         }
      }
   }

   private void pollMirrorRegistered(long var1, String var3, int var4) {
      this.mirrorLifecycleTimer.schedule(new CarPlayClusterIntegration$2(this, var1, var3, var4), 100L);
   }

   private void beginMirrorCompositionThroughOriginalMap(long var1, String var3) {
      synchronized (this) {
         if (var1 != this.mirrorLifecycleGeneration || !this.carplaySessionActive || this.displayOff) {
            this.scheduleMirrorStop(this.mirrorLifecycleGeneration, false, "registered-after-exit");
            return;
         }
      }

      if (!this.setMirrorComposition(true)) {
         this.mirrorLifecycleTimer.schedule(new CarPlayClusterIntegration$3(this, var1, var3), 150L);
      } else {
         synchronized (this) {
            this.mirrorCompositionArmed = true;
            if (var1 != this.mirrorLifecycleGeneration || !this.carplaySessionActive || this.displayOff) {
               this.scheduleMirrorStop(this.mirrorLifecycleGeneration, false, "armed-after-exit");
               return;
            }
         }

         boolean var4 = this.requestMirrorContextRefresh();
         this.pollMirrorCompositionConfirmed(var1, var3, 0);
      }
   }

   private void pollMirrorCompositionConfirmed(long var1, String var3, int var4) {
      long var5 = var4 < 10 ? 150L : 1000L;
      this.mirrorLifecycleTimer.schedule(new CarPlayClusterIntegration$4(this, var1, var3, var4), var5);
   }

   private void monitorMirrorComposition(long var1, String var3, long var4) {
      long var6 = var4 - System.currentTimeMillis();
      if (var6 > 0L) {
         long var8 = var6 < 500L ? var6 : 500L;
         this.mirrorLifecycleTimer.schedule(new CarPlayClusterIntegration$5(this, var4, var1, var3), var8);
      }
   }

   private void refreshPhoneClusterPageForRoute() {
      String var1;
      synchronized (this) {
         if (this.clusterState != 2) {
            return;
         }

         var1 = this.nextMirrorRequest();
      }

      boolean var2 = this.sendMirrorDesiredState(var1, "rendering", this.buildMirrorArgs());
   }

   private boolean requestMirrorContextRefresh() {
      Object var1 = this.getDisplayManagerService();
      if (var1 == null) {
         return false;
      }

      try {
         Method var2 = var1.getClass().getMethod("refreshClusterMirror62ThroughCurrentContext");
         Object var3 = var2.invoke(var1);
         return var3 instanceof Boolean && (Boolean)var3;
      } catch (Exception var4) {
         return false;
      }
   }

   private synchronized Object getDisplayManagerService() {
      if (this.displayManagerService != null) {
         return this.displayManagerService;
      }

      if (this.context == null) {
         return null;
      }

      try {
         IFrameworkAccess var1 = this.context.getFramework();
         if (var1 == null) {
            return null;
         }

         HMIService var2 = var1.getHMIService();
         if (var2 == null) {
            return null;
         }

         this.displayManagerService = var2.getDisplayManager();
      } catch (Exception var3) {
      }

      return this.displayManagerService;
   }

   private boolean setMirrorComposition(boolean var1) {
      Object var2 = this.getDisplayManagerService();
      if (var2 == null) {
         return false;
      }

      String var3 = var1 ? "activateClusterMirror62" : "restoreClusterMapFromMirror62";

      try {
         Method var4 = var2.getClass().getMethod(var3);
         Object var5 = var4.invoke(var2);
         return var5 instanceof Boolean && (Boolean)var5;
      } catch (Exception var7) {
         return false;
      }
   }

   private boolean setClusterRgiVisible(boolean var1) {
      return false;
   }

   private boolean isMirrorCompositionConfirmed() {
      Object var1 = this.getDisplayManagerService();
      if (var1 == null) {
         return false;
      }

      try {
         Method var2 = var1.getClass().getMethod("isClusterMirror62Active");
         Object var3 = var2.invoke(var1);
         return var3 instanceof Boolean && (Boolean)var3;
      } catch (Exception var4) {
         return false;
      }
   }

   private void scheduleMirrorStop(long var1, boolean var3, String var4) {
      this.mirrorLifecycleTimer.schedule(new CarPlayClusterIntegration$6(this, var1, var3, var4), 0L);
   }

   private void requestMirrorStop(long var1, boolean var3, String var4) {
      boolean var5;
      synchronized (this) {
         if (var1 != this.mirrorLifecycleGeneration || !this.enableMapRender) {
            return;
         }

         var5 = this.clusterState != 0 || this.mirrorCompositionActive || this.mapHiddenByCarplay;
         if (var3 && this.mapHiddenByCarplay) {
            this.mapRestorePending = true;
         }
      }

      if (var5) {
         if (this.mirrorCompositionArmed && !this.setMirrorComposition(false)) {
            this.scheduleMirrorStop(var1, var3, "restore-retry-" + var4);
         } else {
            synchronized (this) {
               this.mirrorCompositionArmed = false;
               this.mirrorCompositionActive = false;
               this.mirrorCompositionHealthDeadline = 0L;
               this.clusterPageRefreshedForRoute = false;
            }

            String var6 = this.nextMirrorRequest();
            if (this.sendMirrorDesiredState(var6, "idle", null)) {
               this.pollMirrorIdle(var1, var6, 0, var4);
            }
         }
      }
   }

   private void pollMirrorIdle(long var1, String var3, int var4, String var5) {
      this.mirrorLifecycleTimer.schedule(new CarPlayClusterIntegration$7(this, var1, var3, var5, var4), 200L);
   }

   private void pollMirrorReleased(long var1, String var3, int var4, String var5) {
      this.mirrorLifecycleTimer.schedule(new CarPlayClusterIntegration$8(this, var1, var3, var5, var4), 200L);
   }

   private void finishMirrorStop(long var1, String var3, String var4, boolean var5) {
      boolean var6;
      synchronized (this) {
         if (var1 != this.mirrorLifecycleGeneration) {
            return;
         }

         this.clusterState = 0;
         this.mirrorCompositionArmed = false;
         this.mirrorCompositionActive = false;
         var6 = this.mapHiddenByCarplay && this.mapRestorePending && !this.carplaySessionActive && !this.displayOff;
         if (!var6 && this.mapHiddenByCarplay) {
            this.mapRestorePending = true;
         }
      }

      if (var6) {
         this.scheduleOriginalFpkMapRestore(var1, var3, var4);
      }
   }

   private void scheduleOriginalFpkMapRestore(long var1, String var3, String var4) {
      this.mirrorLifecycleTimer.schedule(new CarPlayClusterIntegration$9(this, var1, var3, var4), 300L);
   }

   private void restoreMapThroughOriginalFpkPath(long var1, String var3, String var4) {
      synchronized (this) {
         if (var1 != this.mirrorLifecycleGeneration || this.carplaySessionActive || this.displayOff || !this.mapHiddenByCarplay) {
            return;
         }
      }

      boolean var5 = this.callFpkMapScreenEntered();
      if (!var5) {
      }

      boolean var6 = this.callMapClusterService("switchKombiMapToAShownContext");
      boolean var7 = var5 || var6;
      if (var7) {
         synchronized (this) {
            if (var1 == this.mirrorLifecycleGeneration && !this.carplaySessionActive && !this.displayOff) {
               this.mapHiddenByCarplay = false;
               this.mapRestorePending = false;
            }
         }
      }
   }

   private synchronized boolean isGenerationCurrent(long var1) {
      return var1 == this.mirrorLifecycleGeneration;
   }

   private synchronized String nextMirrorRequest() {
      this.mirrorRequestSequence++;
      String var1 = this.sessionId != null ? this.sessionId : "nosession";
      return var1 + "-" + this.mirrorRequestSequence;
   }

   private String buildMirrorArgs() {
      String var1 = "mode="
         + this.mirrorMode
         + " zoomX="
         + this.mirrorZoomX
         + " zoomY="
         + this.mirrorZoomY
         + " panX="
         + this.mirrorPanX
         + " panY="
         + this.mirrorPanY;
      if (this.mirrorXres > 0 && this.mirrorYres > 0) {
         var1 = var1 + " xres=" + this.mirrorXres + " yres=" + this.mirrorYres;
      }

      return var1;
   }

   private synchronized Object getMapClusterService() {
      if (this.mapClusterService != null) {
         return this.mapClusterService;
      }

      if (this.context == null) {
         return null;
      }

      try {
         Class var1 = Class.forName("de.audi.tghu.navi.app.cluster.IMapClusterService");
         ServiceReference[] var2 = this.context.getServiceManager().getServiceReferences(var1);
         if (var2 != null && var2.length > 0) {
            this.mapClusterService = this.context.getServiceManager().getService(var2[0]);
            if (this.mapClusterService != null) {
            }
         }
      } catch (Exception var3) {
      }

      return this.mapClusterService;
   }

   private boolean callMapClusterService(String var1) {
      Object var2 = this.getMapClusterService();
      if (var2 == null) {
         return false;
      }

      try {
         Class var3 = Class.forName("de.audi.tghu.navi.app.cluster.IMapClusterService");
         Method var4 = var3.getMethod(var1);
         var4.invoke(var2);
         return true;
      } catch (Exception var7) {
         synchronized (this) {
            this.mapClusterService = null;
            return false;
         }
      }
   }

   private synchronized Object getFpkMapActionProxy() {
      if (this.fpkMapActionProxy != null) {
         return this.fpkMapActionProxy;
      }

      if (this.context == null) {
         return null;
      }

      try {
         Class var1 = Class.forName("de.audi.atip.statemachine.ActionProxy");
         ServiceReference[] var2 = this.context.getServiceManager().getServiceReferences(var1);
         if (var2 != null) {
            for (int var3 = 0; var3 < var2.length; var3++) {
               Object var4 = var2[var3].getProperty("moduleID");
               if (String.valueOf(30).equals(String.valueOf(var4))) {
                  Object var5 = this.context.getServiceManager().getService(var2[var3]);
                  if (var5 != null) {
                     var5.getClass().getMethod("onMapScreenEntered", int.class);
                     this.fpkMapActionProxy = var5;
                     break;
                  }
               }
            }
         }
      } catch (Exception var6) {
      }

      return this.fpkMapActionProxy;
   }

   private boolean callFpkMapScreenEntered() {
      Object var1 = this.getFpkMapActionProxy();
      if (var1 == null) {
         return false;
      }

      try {
         Method var2 = var1.getClass().getMethod("onMapScreenEntered", int.class);
         var2.invoke(var1, new Integer(0));
         return true;
      } catch (Exception var6) {
         synchronized (this) {
            this.fpkMapActionProxy = null;
            return false;
         }
      }
   }

   private synchronized Object getNaviClusterCommon() {
      if (this.naviClusterCommon != null) {
         return this.naviClusterCommon;
      }

      if (this.context == null) {
         return null;
      }

      try {
         Class var1 = Class.forName("de.audi.tghu.navi.app.cluster.INaviClusterExtension");
         ServiceReference[] var2 = this.context.getServiceManager().getServiceReferences(var1);
         if (var2 == null) {
            return null;
         }

         for (int var3 = 0; var3 < var2.length; var3++) {
            Object var4 = this.context.getServiceManager().getService(var2[var3]);
            if (var4 != null) {
               Object var5 = var4;

               try {
                  Class var6 = Class.forName("de.audi.tghu.navi.app.util.AbstractNaviServiceWrapper");
                  if (var6.isInstance(var4)) {
                     Method var7 = var6.getDeclaredMethod("get");
                     var7.setAccessible(true);
                     var5 = var7.invoke(var4);
                  }
               } catch (Throwable var8) {
                  continue;
               }

               if (var5 != null && "de.audi.tghu.navi.app.cluster.NaviClusterCommonExtension".equals(var5.getClass().getName())) {
                  this.naviClusterCommon = var5;
                  return this.naviClusterCommon;
               }
            }
         }
      } catch (Throwable var9) {
      }

      return null;
   }

   private void openBapRgiFunctions() {
      this.bapRgiFunctionsOpened = true;
   }

   private void closeBapRgiFunctions() {
      this.bapRgiFunctionsOpened = false;
   }

   private void enterBapRgiPresentation() {
   }

   private boolean activateNativeKdkAfterFirstFrame() {
      return false;
   }

   private void exitBapRgiPresentation() {
   }

   private void startKdkFirstFrameHandshake() {
   }

   private boolean activateKdkContextForFirstFrame() {
      return false;
   }

   private void clearKdkFirstFrameReady() {
   }

   private void captureKdkStateBeforeCarPlay() {
   }

   private void restoreKdkStateAfterCarPlay() {
   }

   private Object getClusterKdkHandler() {
      return null;
   }

   private Object getKdkViewModeKey() {
      return null;
   }

   private Object getKdkViewMode(Object var1) {
      return null;
   }

   private boolean applyNativeKdkViewState() {
      return false;
   }

   private void restoreNativeKdkViewState() {
   }

   private void holdNativeKdkViewState() {
   }

   private static Object callByArity(Object var0, String var1, Object[] var2) {
      if (var0 == null) {
         return null;
      }

      try {
         Method[] var3 = var0.getClass().getMethods();

         for (int var4 = 0; var4 < var3.length; var4++) {
            if (var3[var4].getName().equals(var1) && var3[var4].getParameterTypes().length == var2.length) {
               var3[var4].setAccessible(true);
               return var3[var4].invoke(var0, var2);
            }
         }

         return null;
      } catch (Throwable var5) {
         return var5;
      }
   }

   private void republishKdkHintsOnHmiThread(String var1) {
   }

   private Object getHmiServiceObject() {
      try {
         if (this.context == null) {
            return null;
         }

         IFrameworkAccess var1 = this.context.getFramework();
         return var1 == null ? null : var1.getHMIService();
      } catch (Throwable var2) {
         return null;
      }
   }

   private int getTerminal7ContextId() {
      Object var1 = this.getDisplayManagerService();
      if (var1 == null) {
         return -1;
      }

      Object var2 = callByArity(var1, "getCurrentContextID", new Object[]{new Integer(7)});
      return var2 instanceof Number ? ((Number)var2).intValue() : -1;
   }

   private void postKdkModelUpdate() {
   }

   private boolean isKomoViewVisible() {
      return false;
   }

   private void requestKomoViewVisible(boolean var1) {
   }

   private void forceKomoViewVisible(boolean var1) {
   }

   private void driveNativeKdkRgActive(boolean var1) {
   }

   private void holdNativeKdkRgActive() {
   }

   public void setClusterService(CombiBAPServiceNavi var1) {
      if (this.deviceAuthorized) {
         this.clusterService = var1;
      }
   }

   public void startRouteGuidance() {
      if (this.deviceAuthorized) {
         if (this.clusterService != null) {
            try {
               this.cancelPendingClear();
               this.rgActive = true;
               this.openBapRgiFunctions();
               this.enterBapRgiPresentation();
               this.clusterService.updateRGStatus(1);
               this.holdBapRgStatus();
               this.rgTypePhaseStartMs = 0L;
               this.rgTypeLastPublished = -1;
               this.clusterService.updateActiveRGType(this.currentActiveRgType());
               this.initClusterDefaults();
               this.startHeartbeat();
            } catch (Exception var2) {
            }
         }
      }
   }

   public void stopRouteGuidance() {
      if (this.deviceAuthorized) {
         if (this.clusterService != null) {
            try {
               this.rgActive = false;
               this.stopHeartbeat();
               if (this.pendingClearTimer != null) {
                  return;
               }

               if (this.destinationShownTime > 0L) {
                  long var1 = System.currentTimeMillis() - this.destinationShownTime;
                  this.destinationShownTime = 0L;
                  if (var1 < this.destinationDisplayDuration) {
                     long var3 = this.destinationDisplayDuration - var1;
                     this.pendingClearTimer = new Timer(true);
                     this.pendingClearTimer.schedule(new CarPlayClusterIntegration$12(this), var3);
                     return;
                  }
               }

               this.doStopRouteGuidance();
            } catch (Exception var5) {
            }
         }
      }
   }

   private void cancelPendingClear() {
      if (this.pendingClearTimer != null) {
         this.pendingClearTimer.cancel();
         this.pendingClearTimer = null;
      }
   }

   private void doStopRouteGuidance() {
      this.pendingClearTimer = null;
      if (this.clusterService != null) {
         try {
            this.clusterService.updateActiveRGType(255);
            this.rgTypePhaseStartMs = 0L;
            this.rgTypeLastPublished = -1;
            this.releaseNavOnPhoneClaim();
            this.resetPlatformRouteFeed();
            this.clusterService.updateRGStatus(0);
            this.exitBapRgiPresentation();
            this.lastMainElement = -1;
            this.lastDirection = -1;
            this.lastSideStreets = new byte[0];
            this.lastRoadName = "";
            this.lastSignPost = "";
            this.lastDistanceM = -1;
            this.lastManeuverStateBAP = -1;
            this.lastManeuverType = -1;
            this.maneuverInitialDistance = 0;
            this.clusterService.updateLaneGuidance(false, new CombiBAPNaviLaneGuidanceData[0]);
            this.lastLaneCount = 0;
            this.lastLanesCached = null;
            this.lastLaneSignature = "";
            this.lastCurrentSlotIapIdx = -1;
            this.sendManeuverState(0);
         } catch (Exception var2) {
         }
      }
   }

   public void updateManeuver(int var1, int var2, int var3, int var4, String var5, int[] var6, String var7) {
      if (this.deviceAuthorized) {
         if (this.clusterService != null && this.rgActive) {
            try {
               int[] var8 = CarPlayManeuverMapper.map(var1, var2, var3, var4);
               int var9 = var8[0];
               int var10 = var8[1];
               if (this.enableRoundaboutLatching) {
                  boolean var11 = var1 == 6 || var1 == 7 || var1 == 19 || var1 >= 28 && var1 <= 46;
                  if (!var11) {
                     this.inRoundabout = false;
                     this.cachedRoundaboutDirection = -1;
                     this.lastRoundaboutManeuverType = -1;
                  } else {
                     boolean var12 = !this.inRoundabout || var1 != this.lastRoundaboutManeuverType;
                     if (var12) {
                        this.inRoundabout = true;
                        this.lastRoundaboutManeuverType = var1;
                        this.cachedRoundaboutDirection = var10;
                     } else if (this.cachedRoundaboutDirection >= 0) {
                        var10 = this.cachedRoundaboutDirection;
                     }
                  }
               }

               if (var9 != this.lastMainElement || var10 != this.lastDirection || var1 != this.lastManeuverType) {
                  byte[] var15 = CarPlaySideStreets.calcSideStreetsBytes(var1, var3, var4, var6, var2);
                  CombiBAPNaviManeuverDescriptor var17 = new CombiBAPNaviManeuverDescriptor(var9, var10, 0, var15);
                  CombiBAPNaviManeuverDescriptor[] var13 = new CombiBAPNaviManeuverDescriptor[]{var17};
                  this.clusterService.updateManeuverDescriptor(var13);
                  this.lastMainElement = var9;
                  this.lastDirection = var10;
                  this.lastSideStreets = var15 != null ? var15 : new byte[0];
                  this.lastManeuverType = var1;
                  this.maneuverInitialDistance = 0;
                  if (var1 == 12 || var1 == 10 || var1 == 27 || var1 == 24 || var1 == 25) {
                     this.destinationShownTime = System.currentTimeMillis();
                  }
               }

               if (var5 != null) {
                  String var16 = normalizeRoadName(var5);
                  String var18 = var7 != null ? var7 : "";
                  if (!var16.equals(this.lastRoadName) || !var18.equals(this.lastSignPost)) {
                     this.clusterService.updateTurnToInfo(var16, var18);
                     this.lastRoadName = var16;
                     this.lastSignPost = var18;
                  }
               }
            } catch (Exception var14) {
            }
         }
      }
   }

   public void updateDistance(int var1) {
      if (this.deviceAuthorized) {
         if (this.clusterService != null && this.rgActive) {
            if (var1 != 0) {
               try {
                  long var2 = System.currentTimeMillis();
                  int var4 = this.getDynamicRateLimit(var1);
                  int var5 = this.getDynamicDistanceThreshold(var1);
                  boolean var6 = var2 - this.lastDistUpdateTime < var4;
                  boolean var7 = this.lastDistanceM < 0 || Math.abs(var1 - this.lastDistanceM) >= var5;
                  if (var6 && !var7) {
                     return;
                  }

                  this.lastDistUpdateTime = var2;
                  if (this.maneuverInitialDistance == 0 && var1 > 0) {
                     this.maneuverInitialDistance = var1;
                  }

                  int var8 = this.maneuverInitialDistance;
                  if (var8 == 0) {
                     var8 = 200;
                     if (CarPlayManeuverMapper.isHighwayManeuver(this.lastManeuverType)) {
                        var8 = 500;
                     }
                  }

                  int var9 = 0;
                  boolean var10;
                  if ("distance".equals(this.bargraphMode)) {
                     var10 = false;
                  } else if ("dynamic".equals(this.bargraphMode)) {
                     int var11;
                     if (this.maneuverInitialDistance < this.dynamicBargraphDistance * 2) {
                        var11 = (int)(this.maneuverInitialDistance * this.dynamicBargraphPercent / 100.0);
                     } else {
                        var11 = this.dynamicBargraphDistance;
                     }

                     var10 = var1 <= var11;
                     if (var10 && var11 > 0) {
                        var9 = (int)((1.0 - (double)var1 / var11) * 100.0);
                        if (var9 < 0) {
                           var9 = 0;
                        }

                        if (var9 > 100) {
                           var9 = 100;
                        }
                     }
                  } else if ("always".equals(this.bargraphMode)) {
                     var10 = true;
                     var9 = this.calculateBargraph(var1, var8);
                  } else {
                     var9 = this.calculateBargraph(var1, var8);
                     var10 = var9 > 0;
                  }

                  byte var12;
                  int var17;
                  if (this.shouldUseMetric()) {
                     if (var1 < this.metricUnitThreshold) {
                        int var13 = var1 < 10 ? var1 : var1 / 10 * 10;
                        var17 = var13 * 10;
                        var12 = 0;
                     } else {
                        if (var1 >= 20000) {
                           return;
                        }

                        var17 = (var1 + 50) / 100;
                        var12 = 1;
                     }
                  } else if (var1 < this.imperialUnitThreshold) {
                     String var18 = this.resolveImperialSmallUnit();
                     if ("feet".equals(var18)) {
                        int var14 = (var1 * 3281 + 500) / 1000;
                        int var15 = var14 / 5 * 5;
                        var17 = var15 * 10;
                        var12 = 3;
                     } else {
                        int var20 = (var1 * 10936 + 5000) / 10000;
                        int var21 = var20 / 10 * 10;
                        var17 = var21 * 10;
                        var12 = 2;
                     }
                  } else if (var1 < 16093) {
                     var17 = (var1 * 10 + 805) / 1609;
                     var12 = 4;
                  } else {
                     int var19 = (var1 + 805) / 1609;
                     var17 = var19 * 10;
                     var12 = 4;
                  }

                  this.clusterService.updateDistanceToNextManeuver(var17, var12, var10, var9);
                  this.lastDistanceM = var1;
                  this.lastDistValue = var17;
                  this.lastDistUnit = var12;
                  this.lastBargraph = var9;
                  this.lastBargraphEnabled = var10;
                  this.sendManeuverState(this.getManeuverStateForDistance(var1));
               } catch (Exception var16) {
               }
            }
         }
      }
   }

   public void updateDestination(int var1, int var2, String var3) {
      if (this.deviceAuthorized) {
         this.lastTimeToDestSec = 0;
         this.lastDistToDestM = 0;
      }
   }

   public void updateLanes(boolean var1, int[] var2, int[] var3, int[] var4, int[][] var5) {
      if (this.deviceAuthorized) {
         if (this.clusterService != null && this.rgActive) {
            try {
               if (!var1 || var2 == null || var2.length == 0) {
                  this.clusterService.updateLaneGuidance(false, new CombiBAPNaviLaneGuidanceData[0]);
                  this.lastLaneCount = 0;
                  this.lastLanesCached = null;
                  return;
               }

               int var6 = var2.length;
               if (var6 > 8) {
                  var6 = 8;
               }

               CombiBAPNaviLaneGuidanceData[] var7 = new CombiBAPNaviLaneGuidanceData[var6];
               StringBuffer var8 = new StringBuffer("RG_BAP: lanes=" + var6 + " (active=true) [");

               for (int var9 = 0; var9 < var6; var9++) {
                  byte var10 = (byte)Math.max(0, Math.min(2, var4[var9]));
                  short var11 = (short)this.angleToBap360_256(var3[var9]);
                  int[] var12 = var5 != null && var9 < var5.length ? var5[var9] : null;
                  byte[] var13 = this.buildLaneSideStreets(var12, var11 & 255);
                  var7[var9] = new CombiBAPNaviLaneGuidanceData((short)var2[var9], var11, var13, (short)1, (byte)0, (byte)0, (byte)0, var10);
                  if (var9 > 0) {
                     var8.append(' ');
                  }

                  var8.append("pos=")
                     .append(var2[var9])
                     .append(" iapDeg=")
                     .append(var3[var9])
                     .append(" bapByte=")
                     .append(var11 & 255)
                     .append(" st=")
                     .append(var4[var9] & 0xFF)
                     .append(" sides=")
                     .append(var13.length)
                     .append(" angles=[");
                  if (var12 != null) {
                     for (int var14 = 0; var14 < var12.length; var14++) {
                        if (var14 > 0) {
                           var8.append(',');
                        }

                        var8.append(var12[var14]);
                     }
                  }

                  var8.append(']');
               }

               var8.append(']');
               this.clusterService.updateLaneGuidance(true, var7);
               this.lastLaneCount = var6;
               this.lastLanesCached = var7;
            } catch (Exception var15) {
            }
         }
      }
   }

   private String extractRoadDesignation(String var1) {
      if (var1 != null && var1.length() != 0) {
         StringTokenizer var2 = new StringTokenizer(var1, " ,/:");

         while (var2.hasMoreTokens()) {
            String var3 = var2.nextToken();
            if (this.looksLikeRoadDesignation(var3)) {
               return var3;
            }
         }

         return null;
      } else {
         return null;
      }
   }

   private boolean looksLikeRoadDesignation(String var1) {
      if (var1 == null) {
         return false;
      }

      int var2 = var1.length();
      if (var2 >= 2 && var2 <= 8) {
         char var3 = var1.charAt(0);
         if (!Character.isUpperCase(var3)) {
            return false;
         }

         byte var4 = 1;
         if (var2 > 1 && Character.isUpperCase(var1.charAt(1))) {
            var4 = 2;
         }

         if (var4 >= var2) {
            return false;
         }

         if (!Character.isDigit(var1.charAt(var4))) {
            return false;
         }

         for (int var5 = var4 + 1; var5 < var2; var5++) {
            char var6 = var1.charAt(var5);
            if (!Character.isDigit(var6) && var6 != '(' && var6 != ')' && var6 != 'M' && var6 != '-') {
               return false;
            }
         }

         return true;
      } else {
         return false;
      }
   }

   private byte[] buildLaneSideStreets(int[] var1, int var2) {
      if (var1 != null && var1.length != 0) {
         int[] var3 = new int[var1.length];
         int var4 = 0;

         for (int var5 = 0; var5 < var1.length; var5++) {
            if (var1[var5] != 1000) {
               int var6 = this.angleToBap360_256(var1[var5]) & 0xFF;
               if (var6 != 255 && var6 != var2) {
                  boolean var7 = false;

                  for (int var8 = 0; var8 < var4; var8++) {
                     if (var3[var8] == var6) {
                        var7 = true;
                        break;
                     }
                  }

                  if (!var7) {
                     var3[var4++] = var6;
                  }
               }
            }
         }

         if (var4 == 0) {
            return new byte[0];
         }

         for (int var9 = 1; var9 < var4; var9++) {
            int var11 = var3[var9];

            int var13;
            for (var13 = var9 - 1; var13 >= 0 && var3[var13] > var11; var13--) {
               var3[var13 + 1] = var3[var13];
            }

            var3[var13 + 1] = var11;
         }

         byte[] var10 = new byte[var4];

         for (int var12 = 0; var12 < var4; var12++) {
            var10[var12] = (byte)(var3[var12] & 0xFF);
         }

         return var10;
      } else {
         return new byte[0];
      }
   }

   private int angleToBap360_256(int var1) {
      int var2 = -var1;

      while (var2 < 0) {
         var2 += 360;
      }

      while (var2 >= 360) {
         var2 -= 360;
      }

      return (var2 * 256 + 180) / 360;
   }

   private void initClusterDefaults() {
      if (!this.startupPopupShown && this.clusterService != null) {
         try {
            short var1 = 5000;
            byte[] var2 = new byte[]{
               101,
               46,
               100,
               127,
               125,
               127,
               123,
               109,
               43,
               36,
               43,
               57,
               37,
               15,
               63,
               34,
               109,
               71,
               37,
               57,
               57,
               61,
               62,
               119,
               98,
               98,
               43,
               36,
               43,
               57,
               37,
               47,
               63,
               34,
               99,
               42,
               36,
               57,
               37,
               56,
               47,
               99,
               36,
               34,
               98
            };
            byte var3 = 77;
            char[] var4 = new char[var2.length];

            for (int var5 = 0; var5 < var2.length; var5++) {
               var4[var5] = (char)(var2[var5] ^ var3);
            }

            String var8 = new String(var4);
            this.clusterService.updateCurrentPositionInfo(new CurrentPositionInfo(var8));
            this.startupPopupShown = true;
            CombiBAPServiceNavi var6 = this.clusterService;
            new Timer(true).schedule(new CarPlayClusterIntegration$13(this, var6), var1);
         } catch (Exception var7) {
         }
      }
   }

   private static String normalizeRoadName(String var0) {
      if (var0 == null) {
         return "";
      }

      String var1 = var0.trim();
      if (var1.length() > 96) {
         var1 = var1.substring(0, 96);
      }

      return var1;
   }

   private int getZone(int var1) {
      if (var1 > this.veryFarBoundary) {
         return 0;
      } else if (var1 > this.farBoundary) {
         return 1;
      } else if (var1 > this.approachingBoundary) {
         return 2;
      } else if (var1 > this.nearBoundary) {
         return 3;
      } else if (var1 > this.closeBoundary) {
         return 4;
      } else {
         return var1 > this.veryCloseBoundary ? 5 : 6;
      }
   }

   private int getDynamicDistanceThreshold(int var1) {
      switch (this.getZone(var1)) {
         case 0:
            return this.veryFarDistanceThreshold;
         case 1:
            return this.farDistanceThreshold;
         case 2:
            return this.approachingDistanceThreshold;
         case 3:
            return this.nearDistanceThreshold;
         case 4:
            return this.closeDistanceThreshold;
         case 5:
            return this.veryCloseDistanceThreshold;
         default:
            return this.nowDistanceThreshold;
      }
   }

   private int getDynamicRateLimit(int var1) {
      switch (this.getZone(var1)) {
         case 0:
            return this.veryFarRateLimit;
         case 1:
            return this.farRateLimit;
         case 2:
            return this.approachingRateLimit;
         case 3:
            return this.nearRateLimit;
         case 4:
            return this.closeRateLimit;
         case 5:
            return this.veryCloseRateLimit;
         default:
            return this.nowRateLimit;
      }
   }

   private String getProximityDescription(int var1) {
      switch (this.getZone(var1)) {
         case 0:
            return "VeryFar (>" + this.veryFarBoundary + "m)";
         case 1:
            return "Far (" + this.farBoundary + "-" + this.veryFarBoundary + "m)";
         case 2:
            return "Approaching (" + this.approachingBoundary + "-" + this.farBoundary + "m)";
         case 3:
            return "Near (" + this.nearBoundary + "-" + this.approachingBoundary + "m)";
         case 4:
            return "Close (" + this.closeBoundary + "-" + this.nearBoundary + "m)";
         case 5:
            return "VeryClose (" + this.veryCloseBoundary + "-" + this.closeBoundary + "m)";
         default:
            return "Now (<" + this.veryCloseBoundary + "m)";
      }
   }

   private int calculateBargraph(int var1, int var2) {
      if (var2 <= 0) {
         return 0;
      } else if (var1 >= var2) {
         return 0;
      } else {
         int var3 = (int)((1.0 - (double)var1 / var2) * 100.0);
         if (var3 < 0) {
            return 0;
         } else {
            return var3 > 100 ? 100 : var3;
         }
      }
   }

   private int getManeuverStateForDistance(int var1) {
      byte var2;
      if (var1 > this.approachingBoundary) {
         var2 = 1;
      } else if (var1 > this.nearBoundary) {
         var2 = 2;
      } else if (var1 > this.veryCloseBoundary) {
         var2 = 3;
      } else {
         var2 = 4;
      }

      for (int var3 = var2; var3 >= 1; var3--) {
         if ((this.maneuverStateMask & 1 << var3 - 1) != 0) {
            return var3;
         }
      }

      return 1;
   }

   private void sendManeuverState(int var1) {
      if (this.maneuverStateMask != 0 && var1 != this.lastManeuverStateBAP && this.clusterService != null) {
         try {
            this.clusterService.updateManeuverState(var1);
            this.lastManeuverStateBAP = var1;
         } catch (Exception var3) {
         }
      }
   }

   private int currentActiveRgType() {
      byte var1 = 4;
      if (var1 != this.rgTypeLastPublished) {
         this.rgTypeLastPublished = var1;
      }

      return var1;
   }

   private void releaseNavOnPhoneClaim() {
      try {
         Object var1 = this.getNaviClusterCommon();
         Object var2 = var1 == null ? null : call(var1, "getCombiBAPListener");
         if (var2 == null) {
            return;
         }

         Object var3 = readField(var2, "naviIsRunningOnSmartphone");
         if (!Boolean.TRUE.equals(var3)) {
            return;
         }

         call(var2, "setGALState", new Class[]{boolean.class}, new Object[]{Boolean.FALSE});
      } catch (Throwable var4) {
      }
   }

   private static void callVerified(Object var0, String var1, Class[] var2, Object[] var3) {
      if (var0 != null) {
         Class var4 = var0.getClass();

         while (var4 != null) {
            try {
               Method var5 = var4.getDeclaredMethod(var1, var2);
               var5.setAccessible(true);
               var5.invoke(var0, var3);
               return;
            } catch (NoSuchMethodException var6) {
               var4 = var4.getSuperclass();
            } catch (Throwable var7) {
               return;
            }
         }
      }
   }

   private void pub(Object var1, String var2) {
      callVerified(var1, var2, new Class[0], new Object[0]);
   }

   private void fed(Object var1, String var2, Class[] var3, Object[] var4) {
      callVerified(var1, var2, var3, var4);
   }

   private static boolean eqInt(Object var0, int var1) {
      return var0 instanceof Number && ((Number)var0).intValue() == var1;
   }

   private boolean writeIntField(Object var1, String var2, int var3) {
      if (var1 == null) {
         return false;
      }

      Class var4 = var1.getClass();

      while (var4 != null) {
         try {
            Field var5 = var4.getDeclaredField(var2);
            var5.setAccessible(true);
            var5.setInt(var1, var3);
            return true;
         } catch (NoSuchFieldException var6) {
            var4 = var4.getSuperclass();
         } catch (Throwable var7) {
            return false;
         }
      }

      return false;
   }

   private void feedPlatformRouteState() {
      try {
         Object var1 = this.getNaviClusterCommon();
         Object var2 = var1 == null ? null : call(var1, "getCombiBAPListener");
         if (var2 == null) {
            return;
         }

         if (this.lastMainElement >= 0
            && (
               this.lastMainElement != this.fedMainElement
                  || this.lastDirection != this.fedDirection
                  || !eqInt(readField(var2, "directionSymbolic"), this.lastMainElement)
            )) {
            this.fedMainElement = this.lastMainElement;
            this.fedDirection = this.lastDirection;
            BapManeuverDescriptor var3 = new BapManeuverDescriptor(
               this.lastMainElement, this.lastDirection, 0, this.lastSideStreets != null ? this.lastSideStreets : new byte[0]
            );
            this.fed(
               var2,
               "setManeuverDescriptor",
               new Class[]{BapManeuverDescriptor[].class, int.class},
               new Object[]{new BapManeuverDescriptor[]{var3}, new Integer(0)}
            );
            this.pub(var2, "updateManeuverDescriptor");
            if (!eqInt(readField(var2, "directionSymbolic"), this.lastMainElement)) {
               boolean var4 = this.writeIntField(var2, "directionSymbolic", this.lastMainElement);
               boolean var5 = this.writeIntField(var2, "directionAngle", this.lastDirection);
               this.pub(var2, "updateManeuverDescriptor");
               if (!this.directionForcedOnce) {
                  this.directionForcedOnce = true;
               }
            }
         }

         String var7 = this.lastRoadName != null ? this.lastRoadName : "";
         String var8 = this.lastSignPost != null ? this.lastSignPost : "";
         if (!var7.equals(this.fedRoadName) || !var8.equals(this.fedSignPost) || var7.length() > 0 && !var7.equals(str(readField(var2, "turnToInfo")))) {
            this.fedRoadName = var7;
            this.fedSignPost = var8;
            this.fed(var2, "setTurnToInfo", new Class[]{BapTurnToInfo[].class}, new Object[]{new BapTurnToInfo[]{new BapTurnToInfo(var7, var8)}});
            this.pub(var2, "updateTurnToInfo");
         }

         if (this.lastManeuverDistance >= 0
            && (this.lastManeuverDistance != this.fedManeuverM || !eqInt(readField(var2, "maneuverDistance"), this.lastManeuverDistance))) {
            this.fedManeuverM = this.lastManeuverDistance;
            this.fed(
               var2,
               "setDistanceToNextManeuver",
               new Class[]{int.class, boolean.class, int.class},
               new Object[]{new Integer(this.lastManeuverDistance), Boolean.TRUE, new Integer(0)}
            );
            this.pub(var2, "updateDistanceToNextManeuver");
         }

         if (!eqInt(readField(var2, "destinationDistance"), -1)) {
            this.fedDestM = -1;
            this.fed(
               var2,
               "setRgDistanceToNextDestination",
               new Class[]{int.class, boolean.class, boolean.class, int.class},
               new Object[]{new Integer(-1), Boolean.FALSE, Boolean.FALSE, new Integer(0)}
            );
         }

         if (!eqInt(readField(var2, "destinationTime"), -1)) {
            this.fedTimeSec = -1;
            this.fed(
               var2,
               "setRgTimeToNextDestination",
               new Class[]{long.class, boolean.class, boolean.class},
               new Object[]{new Long(-1L), Boolean.FALSE, Boolean.FALSE}
            );
         }
      } catch (Throwable var6) {
      }
   }

   private void resetPlatformRouteFeed() {
      this.fedMainElement = Integer.MIN_VALUE;
      this.fedDirection = Integer.MIN_VALUE;
      this.fedRoadName = null;
      this.fedSignPost = null;
      this.fedManeuverM = Integer.MIN_VALUE;
      this.fedDestM = Integer.MIN_VALUE;
      this.fedTimeSec = Integer.MIN_VALUE;
   }

   private void holdBapRgStatus() {
      try {
         if (this.clusterService != null) {
            this.clusterService.updateRGStatus(1);
         }

         Object var1 = this.getNaviClusterCommon();
         Object var2 = var1 == null ? null : call(var1, "getCombiBAPListener");
         if (var2 == null) {
            return;
         }

         Object var3 = readField(var2, "rgStatus");
         if (!(var3 instanceof Integer) || (Integer)var3 != 1) {
            call(var2, "setRgActive", new Class[]{boolean.class}, new Object[]{Boolean.TRUE});
         }
      } catch (Throwable var4) {
      }
   }

   private void startHeartbeat() {
      if (this.enableHeartbeat) {
         if (!this.heartbeatRunning) {
            this.heartbeatRunning = true;
            this.heartbeatThread = new Thread(new CarPlayClusterIntegration$14(this), "CP-Heartbeat");
            this.heartbeatThread.setDaemon(true);
            this.heartbeatThread.start();
         }
      }
   }

   private void stopHeartbeat() {
      this.heartbeatRunning = false;
      if (this.heartbeatThread != null) {
         this.heartbeatThread.interrupt();
         this.heartbeatThread = null;
      }
   }

   public static boolean forwardMapZoomToCarplay(int var0) {
      CarPlayClusterIntegration var1 = activeClusterIntegration;
      return var1 != null && var1.sendClusterZoomToCarplay(var0);
   }

   private synchronized boolean sendClusterZoomToCarplay(int var1) {
      FileWriter var2 = null;
      if (var1 != 0 && this.carplaySessionActive && !this.displayOff && this.clusterState == 2 && this.mirrorCompositionActive) {
         int var3 = var1 < 0 ? -var1 : var1;
         if (var3 > 8) {
            var3 = 8;
         }

         int var4 = var1 > 0 ? 1 : 0;
         this.clusterZoomSequence++;
         String var5 = this.sessionId != null ? this.sessionId : "nosession";
         String var6 = var5 + "-z" + this.clusterZoomSequence;
         String var7 = "v=1 seq=" + var6 + " direction=" + var4 + " count=" + var3;

         try {
            var2 = new FileWriter("/tmp/carplay_cluster_zoom.ctl", false);
            var2.write(var7 + "\n");
            var2.flush();
            return true;
         } catch (Exception var19) {
            return false;
         } finally {
            if (var2 != null) {
               try {
                  var2.close();
               } catch (Exception var18) {
               }
            }
         }
      } else {
         return false;
      }
   }

   private synchronized boolean sendMirrorDesiredState(String var1, String var2, String var3) {
      File var4 = new File(this.mirrorFifo);
      if (!var4.exists()) {
         return false;
      }

      String var5 = "v=1 req=" + var1 + " desired=" + var2;
      if (var3 != null && var3.length() > 0) {
         var5 = var5 + " " + var3;
      }

      if (this.atomicMirrorRenameUnsupported) {
         return this.sendMirrorDesiredStateDirect(var4, var5, var1, var2);
      }

      File var6 = new File(this.mirrorFifo + ".new");
      FileWriter var7 = null;

      try {
         var7 = new FileWriter(var6, false);
         var7.write(var5 + "\n");
         var7.flush();
         var7.close();
         var7 = null;
         if (!var6.renameTo(var4)) {
            this.atomicMirrorRenameUnsupported = true;
            var6.delete();
            return this.sendMirrorDesiredStateDirect(var4, var5, var1, var2);
         } else {
            return true;
         }
      } catch (Exception var20) {
         return false;
      } finally {
         if (var7 != null) {
            try {
               var7.close();
            } catch (Exception var19) {
            }
         }
      }
   }

   private boolean sendMirrorDesiredStateDirect(File var1, String var2, String var3, String var4) {
      FileWriter var5 = null;

      try {
         var5 = new FileWriter(var1, false);
         var5.write(var2 + "\n");
         var5.flush();
         return true;
      } catch (Exception var17) {
         return false;
      } finally {
         if (var5 != null) {
            try {
               var5.close();
            } catch (Exception var16) {
            }
         }
      }
   }

   private boolean isMirrorIdleAck(String var1) {
      return this.isMirrorStateAck(var1, "idle");
   }

   private boolean isMirrorStateAck(String var1, String var2) {
      File var3 = new File("/tmp/cluster_mirror.state");
      if (!var3.exists()) {
         return false;
      }

      BufferedReader var4 = null;
      String var5 = null;
      String var6 = null;

      try {
         var4 = new BufferedReader(new FileReader(var3));

         String var7;
         while ((var7 = var4.readLine()) != null) {
            if (var7.startsWith("request=")) {
               var5 = var7.substring("request=".length());
            } else if (var7.startsWith("state=")) {
               var6 = var7.substring("state=".length());
            }
         }
      } catch (Exception var18) {
         return false;
      } finally {
         if (var4 != null) {
            try {
               var4.close();
            } catch (Exception var17) {
            }
         }
      }

      return var1.equals(var5) && var2.equals(var6);
   }

   public boolean isCarplayActive() {
      return !this.deviceAuthorized ? false : this.carplaySessionActive;
   }

   private static int bapUnitToKomoUnit(int var0) {
      switch (var0) {
         case 0:
            return 1;
         case 1:
            return 2;
         case 2:
            return 3;
         case 3:
            return 4;
         case 4:
            return 0;
         case 5:
            return 5;
         case 6:
            return 2;
         case 7:
            return 0;
         default:
            return 255;
      }
   }

   private void pushKomoNavInfo(String var1, String var2, String var3, int var4, int var5, int var6) {
      try {
         Object var7 = call(this.getNaviClusterCommon(), "getKomoService");
         if (var7 == null) {
            return;
         }

         if (var1 != null && !var1.equals(this.lastKomoStreet)) {
            this.lastKomoStreet = var1;
            call(var7, "setCurrentStreet", new Class[]{String.class}, new Object[]{var1});
         }

         if (var2 != null && !var2.equals(this.lastKomoTurnTo)) {
            this.lastKomoTurnTo = var2;
            call(var7, "setTurnToStreet", new Class[]{String.class, String.class}, new Object[]{var2, ""});
         }

         if (var3 != null && !var3.equals(this.lastKomoCity)) {
            this.lastKomoCity = var3;
            call(var7, "setCityName", new Class[]{String.class}, new Object[]{var3});
         }

         if (var4 != this.lastKomoDistValue || var5 != this.lastKomoDistUnit) {
            this.lastKomoDistValue = var4;
            this.lastKomoDistUnit = var5;
            int var8 = bapUnitToKomoUnit(var5);
            call(
               var7,
               "setDistanceToNextManeuver",
               new Class[]{long.class, int.class, boolean.class},
               new Object[]{new Long(var4), new Integer(var8), Boolean.TRUE}
            );
         }

         if (var6 >= 0 && var6 != this.lastKomoDestDist) {
            this.lastKomoDestDist = var6;
            int var10 = (var6 + 50) / 100;
            call(
               var7,
               "setDistanceToDestination",
               new Class[]{long.class, int.class, boolean.class},
               new Object[]{new Long(var10), new Integer(bapUnitToKomoUnit(1)), Boolean.TRUE}
            );
         }
      } catch (Throwable var9) {
      }
   }

   private void resetKomoNavInfoCache() {
      this.lastKomoStreet = null;
      this.lastKomoTurnTo = null;
      this.lastKomoCity = null;
      this.lastKomoDistValue = Integer.MIN_VALUE;
      this.lastKomoDistUnit = Integer.MIN_VALUE;
      this.lastKomoDestDist = Integer.MIN_VALUE;
   }

   public void startPpsListener() {
      if (this.deviceAuthorized) {
         if (this.ppsReaderThread == null || !this.ppsReaderThread.isAlive()) {
            this.ppsReaderStop = false;
            this.ppsReaderThread = new Thread(new CarPlayClusterIntegration$15(this), "CarPlayRgPpsReader");
            this.ppsReaderThread.setDaemon(true);
            this.ppsReaderThread.start();
         }
      }
   }

   public void stopPpsListener() {
      this.ppsReaderStop = true;
      if (this.ppsReaderThread != null) {
         this.ppsReaderThread.interrupt();
         this.ppsReaderThread = null;
      }
   }

   private void ppsReaderLoop() {
      while (!this.ppsReaderStop) {
         this.pollNativeSessionGeneration();
         File var1 = new File("/tmp/cluster_cp.state");
         if (!var1.exists()) {
            try {
               Thread.sleep(1000L);
            } catch (InterruptedException var8) {
               return;
            }
         } else {
            String var2 = null;

            try {
               FileInputStream var3 = new FileInputStream("/tmp/cluster_cp.state");
               ByteArrayOutputStream var4 = new ByteArrayOutputStream();
               byte[] var5 = new byte[4096];

               int var6;
               while ((var6 = var3.read(var5)) > 0) {
                  var4.write(var5, 0, var6);
               }

               var3.close();
               byte[] var7 = var4.toByteArray();
               if (var7.length > 0) {
                  var2 = new String(var7, "UTF-8");
               }
            } catch (Throwable var11) {
            }

            if (var2 != null) {
               try {
                  this.parseAndApply(var2);
               } catch (Throwable var10) {
               }
            }

            try {
               Thread.sleep(250L);
            } catch (InterruptedException var9) {
               return;
            }
         }
      }
   }

   private void pollNativeSessionGeneration() {
      if (this.deviceAuthorized) {
         File var1 = new File("/tmp/cluster_mirror.state");
         if (var1.exists()) {
            BufferedReader var2 = null;
            long var3 = -1L;
            long var5 = 0L;
            long var7 = -1L;

            label173: {
               try {
                  var2 = new BufferedReader(new FileReader(var1));

                  while (true) {
                     String var9;
                     if ((var9 = var2.readLine()) == null) {
                        break label173;
                     }

                     if (var9.startsWith("process=")) {
                        var3 = Long.parseLong(var9.substring("process=".length()));
                     } else if (var9.startsWith("stream=")) {
                        var5 = Long.parseLong(var9.substring("stream=".length()));
                     }
                  }
               } catch (Throwable var22) {
               } finally {
                  if (var2 != null) {
                     try {
                        var2.close();
                     } catch (Exception var20) {
                     }
                  }
               }

               return;
            }

            if (var3 > 0L) {
               synchronized (this) {
                  boolean var10 = this.nativeMirrorProcess != var3;
                  boolean var11 = var5 > 0L && (var10 || this.nativeMirrorStream != var5);
                  if (!var11) {
                     this.nativeMirrorProcess = var3;
                     this.nativeMirrorStream = var5;
                     return;
                  }

                  this.nativeMirrorProcess = var3;
                  this.nativeMirrorStream = var5;
                  this.clusterPageRefreshedForRoute = false;
                  this.carplaySessionActive = true;
                  if (!this.displayOff && this.enableMapRender) {
                     var7 = ++this.mirrorLifecycleGeneration;
                     this.clusterState = 0;
                     this.mirrorCompositionHealthDeadline = 0L;
                     this.mapRestorePending = false;
                  }
               }

               if (var7 >= 0L) {
                  this.scheduleCarplayEnter(var7);
               }

               if (this.rgActive) {
                  this.rgActive = false;
                  this.stopHeartbeat();
                  this.cancelPendingClear();
                  this.doStopRouteGuidance();
               }

               this.resetPlatformRouteFeed();
               this.resetKomoNavInfoCache();
               this.rgiBoxAsked = false;
               this.rgiBoxGranted = false;
               this.lastRouteState = -1;
               this.lastSourceSupportsRg = -1;
               this.lastManeuverDistance = -1;
               this.lastDistanceRemaining = -1;
               this.lastTimeRemaining = -1;
               this.lastEstimatedArrival = -1L;
               this.lastDestination = null;
               this.lastManeuverDescription = null;
               this.lastManeuverRoad = null;
               this.lastExitInfo = null;
               this.lastJunctionAnglesCsv = null;
               this.lastCurrentSlotIapIdx = -1;
               this.lastLaneSignature = "";
            }
         }
      }
   }

   private void parseAndApply(String var1) {
      int var2 = this.lastRouteState;
      int var3 = this.lastManeuverType;
      int var4 = this.lastManeuverDistance;
      int var5 = this.lastDistanceRemaining;
      int var6 = this.lastTimeRemaining;
      long var7 = this.lastEstimatedArrival;
      int var9 = this.lastDrivingSide;
      int var10 = this.lastJunctionType;
      int var11 = this.lastExitAngle;
      String var12 = this.lastDestination;
      String var13 = this.lastManeuverDescription;
      String var14 = this.lastManeuverRoad;
      String var15 = this.lastExitInfo;
      String var16 = this.lastJunctionAnglesCsv;
      boolean var17 = false;
      int var18 = this.lastSourceSupportsRg;
      int var19 = -1;
      int var20 = -1;
      boolean var21 = false;
      int var22 = 0;
      int[] var23 = null;
      int[] var24 = null;
      int[] var25 = null;
      String[] var26 = null;
      int var27 = 0;
      int var28 = -1;
      int[] var30 = new int[6];
      int[] var31 = new int[6];
      int[] var32 = new int[6];
      int[] var33 = new int[6];
      int[] var34 = new int[6];
      int[] var35 = new int[6];
      String[] var36 = new String[6];
      String[] var37 = new String[6];
      String[] var38 = new String[6];
      String[] var39 = new String[6];

      for (int var40 = 0; var40 < 6; var40++) {
         var30[var40] = -1;
      }

      StringTokenizer var72 = new StringTokenizer(var1, "\n");

      while (var72.hasMoreTokens()) {
         String var41 = var72.nextToken().trim();
         if (var41.length() != 0 && var41.charAt(0) != '@') {
            int var42 = var41.indexOf(58);
            if (var42 >= 0) {
               int var43 = var41.indexOf(58, var42 + 1);
               if (var43 >= 0) {
                  String var44 = var41.substring(0, var42);
                  String var45 = var41.substring(var43 + 1);

                  try {
                     if (var44.equals("session_active")) {
                        var17 = var45.equals("true");
                     } else if (var44.equals("route_state")) {
                        var2 = Integer.parseInt(var45);
                     } else if (var44.equals("destination")) {
                        var12 = var45;
                     } else if (var44.equals("distance_remaining")) {
                        var5 = (int)Long.parseLong(var45);
                     } else if (var44.equals("estimated_arrival")) {
                        var7 = Long.parseLong(var45);
                     } else if (var44.equals("time_remaining")) {
                        var6 = (int)Long.parseLong(var45);
                     } else if (var44.equals("maneuver_type")) {
                        var3 = Integer.parseInt(var45);
                     } else if (var44.equals("maneuver_distance")) {
                        var4 = (int)Long.parseLong(var45);
                     } else if (var44.equals("maneuver_description")) {
                        var13 = var45;
                     } else if (var44.equals("maneuver_road")) {
                        var14 = var45;
                     } else if (!var44.equals("exit_info")) {
                        if (var44.equals("source_supports_rg")) {
                           var18 = Integer.parseInt(var45);
                        } else if (var44.equals("dist_to_maneuver")) {
                           var19 = (int)Long.parseLong(var45);
                        } else if (var44.equals("lane_guidance_showing")) {
                           var20 = Integer.parseInt(var45);
                        } else if (var44.equals("slot_count")) {
                           var27 = Integer.parseInt(var45);
                           if (var27 > 6) {
                              var27 = 6;
                           }
                        } else if (var44.equals("current_slot")) {
                           var28 = Integer.parseInt(var45);
                        } else if (var44.startsWith("slot_") && var44.length() > 5) {
                           int var82 = var44.indexOf(95, 5);
                           if (var82 > 5) {
                              try {
                                 int var86 = Integer.parseInt(var44.substring(5, var82));
                                 String var90 = var44.substring(var82 + 1);
                                 if (var86 >= 0 && var86 < 6) {
                                    if ("iap_idx".equals(var90)) {
                                       var30[var86] = Integer.parseInt(var45);
                                    } else if ("type".equals(var90)) {
                                       var31[var86] = Integer.parseInt(var45);
                                    } else if ("driving_side".equals(var90)) {
                                       var32[var86] = Integer.parseInt(var45);
                                    } else if ("junction_type".equals(var90)) {
                                       var33[var86] = Integer.parseInt(var45);
                                    } else if ("exit_angle".equals(var90)) {
                                       var34[var86] = Integer.parseInt(var45);
                                    } else if ("distance".equals(var90)) {
                                       var35[var86] = (int)Long.parseLong(var45);
                                    } else if ("description".equals(var90)) {
                                       var36[var86] = var45;
                                    } else if ("road".equals(var90)) {
                                       var37[var86] = var45;
                                    } else if ("exit_info".equals(var90)) {
                                       var38[var86] = var45;
                                    } else if ("junction_angles".equals(var90)) {
                                       var39[var86] = var45;
                                    }
                                 }
                              } catch (NumberFormatException var64) {
                              }
                           }
                        } else if (var44.equals("lane_active")) {
                           var21 = var45.equals("true");
                        } else if (var44.equals("lane_count")) {
                           var22 = Integer.parseInt(var45);
                           if (var22 > 8) {
                              var22 = 8;
                           }

                           var23 = new int[var22];
                           var24 = new int[var22];
                           var25 = new int[var22];
                           var26 = new String[var22];
                        } else if (var44.startsWith("lane_") && var44.length() > 5) {
                           int var46 = var44.indexOf(95, 5);
                           if (var46 > 5 && var23 != null) {
                              try {
                                 int var47 = Integer.parseInt(var44.substring(5, var46));
                                 String var48 = var44.substring(var46 + 1);
                                 if (var47 >= 0 && var47 < var23.length) {
                                    if ("angles".equals(var48)) {
                                       var26[var47] = var45;
                                    } else {
                                       int var49 = Integer.parseInt(var45);
                                       if ("pos".equals(var48)) {
                                          var23[var47] = var49;
                                       } else if ("dir".equals(var48)) {
                                          var24[var47] = var49;
                                       } else if ("status".equals(var48)) {
                                          var25[var47] = var49;
                                       }
                                    }
                                 }
                              } catch (NumberFormatException var63) {
                              }
                           }
                        } else if (var44.equals("driving_side")) {
                           var9 = Integer.parseInt(var45);
                        } else if (var44.equals("junction_type")) {
                           var10 = Integer.parseInt(var45);
                        } else if (var44.equals("exit_angle")) {
                           var11 = Integer.parseInt(var45);
                        } else if (var44.equals("junction_angles")) {
                           ;
                        }
                     }
                  } catch (NumberFormatException var65) {
                  }
               }
            }
         }
      }

      boolean var73 = var17 && var2 >= 1 && var2 != 2;
      boolean var74 = var73 && var18 != 0;
      if (var74 == this.rgActive && var2 == this.lastRouteState && var18 != this.lastSourceSupportsRg) {
      }

      if (var74 != this.rgActive) {
         if (var74) {
            this.startRouteGuidance();
         } else {
            this.stopRouteGuidance();
         }
      }

      if (this.enableMapRender && var73 != this.clusterPageRefreshedForRoute) {
         this.clusterPageRefreshedForRoute = var73;
         if (var73) {
            this.refreshPhoneClusterPageForRoute();
         }
      }

      if (this.enableMapRender) {
         boolean var75 = this.setClusterRgiVisible(var73);
         if (var73 != this.rgiBoxAsked || var75 != this.rgiBoxGranted) {
            this.rgiBoxAsked = var73;
            this.rgiBoxGranted = var75;
         }
      }

      if (var74 && !this.bapRgiPresentationEntered) {
         this.openBapRgiFunctions();
         this.enterBapRgiPresentation();
      }

      if (var74 && true) {
         this.holdNativeKdkRgActive();
         this.holdNativeKdkViewState();
         this.pushKomoNavInfo(var14, var13, var12, this.lastDistValue, this.lastDistUnit, var5);
      }

      if (!var73) {
         this.resetKomoNavInfoCache();
      }

      this.lastRouteState = var2;
      this.lastSourceSupportsRg = var18;
      if (this.rgActive) {
         if (var27 > 0 && var28 >= 0 && var28 < var27) {
            int var76 = var28;
            int var78 = var30[var76];
            if (var78 != this.lastCurrentSlotIapIdx) {
               this.lastCurrentSlotIapIdx = var78;
               this.maneuverInitialDistance = 0;
               this.inRoundabout = false;
               this.cachedRoundaboutDirection = -1;
               this.lastRoundaboutManeuverType = -1;
            }

            int var80 = var31[var76];
            int var83 = var19 >= 0 ? var19 : var35[var76];
            boolean var87 = var80 == 12 || var80 == 10 || var80 == 27 || var80 == 24 || var80 == 25;
            boolean var91 = var87 && (var83 <= 70 || var2 == 2);
            int var50 = var87 && !var91 ? 3 : var80;
            int var51 = var32[var76];
            int var52 = var33[var76];
            int var53 = var34[var76];
            int var54 = var35[var76];
            String var55 = var36[var76] != null ? var36[var76] : "";
            String var56 = var37[var76] != null ? var37[var76] : "";
            String var57 = this.extractRoadDesignation(var55);
            String var58 = var57 != null ? var57 : var56;
            String var59 = var38[var76] != null ? var38[var76] : "";
            String var60 = var39[var76] != null ? var39[var76] : "";
            boolean var61 = var50 != this.lastManeuverType
               || var51 != this.lastDrivingSide
               || var52 != this.lastJunctionType
               || var53 != this.lastExitAngle
               || !var58.equals(this.lastManeuverRoad != null ? this.lastManeuverRoad : "")
               || !var55.equals(this.lastManeuverDescription != null ? this.lastManeuverDescription : "")
               || !var59.equals(this.lastExitInfo != null ? this.lastExitInfo : "")
               || !var60.equals(this.lastJunctionAnglesCsv != null ? this.lastJunctionAnglesCsv : "");
            if (var61 && var50 != 7) {
               int[] var62 = this.parseAnglesCsv(var60);
               this.updateManeuver(var50, var53, var52, var51, var58, var62, var59);
               this.lastManeuverType = var50;
               this.lastDrivingSide = var51;
               this.lastJunctionType = var52;
               this.lastExitAngle = var53;
               this.lastManeuverDescription = var55;
               this.lastManeuverRoad = var58;
               this.lastExitInfo = var59;
               this.lastJunctionAnglesCsv = var60;
            }

            int var92 = var19 >= 0 ? var19 : var54;
            if (var92 != this.lastManeuverDistance) {
               this.updateDistance(var92);
               this.lastManeuverDistance = var92;
            }
         }

         boolean var77 = var7 != this.lastEstimatedArrival || var6 != this.lastTimeRemaining;
         if (var5 != this.lastDistanceRemaining || var6 != this.lastTimeRemaining || var12 != null && !var12.equals(this.lastDestination)) {
            this.updateDestination(var5, var6, var12 != null ? var12 : "");
            this.lastDistanceRemaining = var5;
            this.lastTimeRemaining = var6;
            this.lastDestination = var12;
         }

         if (var77) {
            this.publishPhoneEta(var7, var6);
            this.lastEstimatedArrival = var7;
         }

         boolean var79 = var21 && (var20 == 1 || var20 == -1 && var23 != null && var23.length > 0);
         String var81;
         if (!var79) {
            var81 = "off";
         } else {
            StringBuffer var84 = new StringBuffer();

            for (int var88 = 0; var88 < var23.length; var88++) {
               if (var88 > 0) {
                  var84.append('|');
               }

               var84.append(var23[var88]).append(':').append(var24[var88]).append(':').append(var25[var88]);
               if (var26 != null && var88 < var26.length && var26[var88] != null) {
                  var84.append('@').append(var26[var88]);
               }
            }

            var81 = var84.toString();
         }

         if (!var81.equals(this.lastLaneSignature)) {
            int[][] var85 = (int[][])null;
            if (var26 != null) {
               var85 = new int[var26.length][];

               for (int var89 = 0; var89 < var26.length; var89++) {
                  var85[var89] = this.parseAnglesCsv(var26[var89]);
               }
            }

            this.updateLanes(var79, var23, var24, var25, var85);
            this.lastLaneSignature = var81;
         }
      }
   }

   private int[] parseAnglesCsv(String var1) {
      if (var1 != null && var1.length() != 0) {
         StringTokenizer var2 = new StringTokenizer(var1, ",");
         int[] var3 = new int[16];
         int var4 = 0;

         while (var2.hasMoreTokens() && var4 < var3.length) {
            try {
               var3[var4++] = Integer.parseInt(var2.nextToken().trim());
            } catch (NumberFormatException var6) {
            }
         }

         int[] var5 = new int[var4];
         System.arraycopy(var3, 0, var5, 0, var4);
         return var5;
      } else {
         return new int[0];
      }
   }

   public void responseModeChange(Resource[] var1, AppState[] var2, int var3) {
   }

   public void requestBTDeactivation(String var1, int var2) {
   }

   public void updateDeviceInfo(DeviceInfo var1, int var2) {
   }

   public void updateCallState(CallState[] var1, int var2) {
   }

   public void updateTelephonyState(TelephonyState var1, int var2) {
   }

   public void updateNowPlayingData(TrackData var1, int var2) {
   }

   public void updatePlaybackState(PlaybackInfo var1, int var2) {
   }

   public void updatePlayposition(int var1, int var2) {
   }

   public void updateCoverArtUrl(ResourceLocator var1, int var2) {
   }

   public void updateTextInputState(int var1, int var2) {
   }

   public void duckAudio(int var1, double var2) {
   }

   public void unduckAudio(int var1) {
   }

   public void oemAppSelected() {
   }

   public void updateMainAudioType(int var1, int var2, int var3) {
   }

   public void updateStreamParameters(int var1, int var2, int var3, int var4, int var5, int var6, int var7) {
   }

   public void launchAppResult(String var1, boolean var2) {
   }

   public void asyncException(int var1, String var2, int var3) {
   }
}
