// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

import de.audi.app.car.api.core.ICarCoreServices;
import de.audi.app.car.api.services.ICarExteriorLightService;
import de.audi.app.terminalmode.IContext;
import de.audi.app.terminalmode.ISPIScreenConnectedProvider;
import de.audi.app.terminalmode.SmartphoneType;
import de.audi.app.terminalmode.TMTTSHandler;
import de.audi.app.terminalmode.TerminalModeUtils;
import de.audi.app.terminalmode.audio.IAudioManager;
import de.audi.app.terminalmode.audio.TMAudioConnection;
import de.audi.app.terminalmode.config.ITerminalModeConfiguration;
import de.audi.app.terminalmode.device.TMDevice;
import de.audi.app.terminalmode.device.TMDevice.ConnectionState;
import de.audi.app.terminalmode.diagnosis.IDiagnosisCommandProvider;
import de.audi.app.terminalmode.diagnosis.IDiagnosisDataProvider;
import de.audi.app.terminalmode.dsi.IAppState;
import de.audi.app.terminalmode.dsi.IDSIAppState;
import de.audi.app.terminalmode.dsi.IDSIResource;
import de.audi.app.terminalmode.dsi.IResource;
import de.audi.app.terminalmode.dsi.DSIResource.Builder;
import de.audi.app.terminalmode.dsi.carplay.CarPlayAppState;
import de.audi.app.terminalmode.dsi.carplay.CarPlayResource;
import de.audi.app.terminalmode.dsi.carplay.CarplayAudioType;
import de.audi.app.terminalmode.dsi.carplay.CarplayButton;
import de.audi.app.terminalmode.dsi.carplay.CarplayButtonState;
import de.audi.app.terminalmode.dsi.carplay.CarplayDSILifecycleController;
import de.audi.app.terminalmode.dsi.carplay.CarplayUtils;
import de.audi.app.terminalmode.dsi.carplay.ICarplayDSIController;
import de.audi.app.terminalmode.dsi.carplay.ICarplayDSIControllerListener;
import de.audi.app.terminalmode.dsi.carplay.MainAudioTypeUpdate;
import de.audi.app.terminalmode.dsi.carplay.ScreenId;
import de.audi.app.terminalmode.logging.LoggingUtil;
import de.audi.app.terminalmode.smartphone.AbstractDSISmartphoneManager;
import de.audi.app.terminalmode.smartphone.ILastmodehandler;
import de.audi.app.terminalmode.smartphone.IPhoneCallController;
import de.audi.app.terminalmode.smartphone.ISmartphoneProperties;
import de.audi.app.terminalmode.smartphone.ISpeechRequestHandler;
import de.audi.app.terminalmode.smartphone.IDSISmartphoneManager.RequestModeChangeCallback;
import de.audi.app.terminalmode.statemachine.Application;
import de.audi.app.terminalmode.statemachine.ApplicationOwner;
import de.audi.app.terminalmode.statemachine.ApplicationStateChange;
import de.audi.app.terminalmode.statemachine.IStateHandler;
import de.audi.app.terminalmode.statemachine.ITMState;
import de.audi.app.terminalmode.statemachine.ITMStateListener;
import de.audi.app.terminalmode.statemachine.Resource;
import de.audi.app.terminalmode.statemachine.ResourceOwner;
import de.audi.app.terminalmode.statemachine.ResourceOwnerChange;
import de.audi.app.terminalmode.statemachine.ResourceState;
import de.audi.app.terminalmode.statemachine.ResourceStateChange;
import de.audi.app.terminalmode.statemachine.commands.AbstractCommand;
import de.audi.app.terminalmode.statemachine.commands.AbstractDSICommand;
import de.audi.app.terminalmode.statemachine.commands.SendResponseModeChanged;
import de.audi.app.terminalmode.statemachine.commands.SetSampleRate;
import de.audi.app.terminalmode.statemachine.commands.UpdateMode;
import de.audi.atip.hmi.modelaccess.ChoiceModelApp;
import de.audi.atip.interapp.combi.bap.PartialPopupBAPService;
import de.audi.atip.interapp.combi.bap.navi.CombiBAPServiceNavi;
import de.audi.atip.util.Util;
import de.audi.atip.utils.generics.GMap;
import de.audi.atip.utils.generics.Generics;
import de.audi.atip.utils.reactive.bindings.SPIBoolean;
import de.audi.atip.utils.reactive.observables.Observables;
import de.audi.atip.utils.reactive.observables.Subscription;
import de.audi.mib.system.ISysServices;
import de.esolutions.fw.util.commons.Buffer;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import org.osgi.framework.ServiceReference;

public class CarPlayDSIManager
   extends AbstractDSISmartphoneManager
   implements ICarplayDSIControllerListener,
   ITMStateListener,
   IDiagnosisDataProvider,
   IDiagnosisCommandProvider {
   private static final String LOGCLASS = "CarPlayDSIManager";
   private final CarplayDSILifecycleController carPlayDSILifecycleController;
   private final Map messageMap;
   private volatile CarPlayResource currentActiveResource;
   private volatile int activeApplications;
   private final ITMState currentState;
   private final ISpeechRequestHandler speechRequestHandler;
   private final IPhoneCallController phoneCallController;
   private final ICarplayDSIController carPlayDSIController;
   private final IStateHandler stateHandler;
   private final CarplaySmartphoneProperties carplaySmartphoneProperties;
   private volatile boolean waitForAudioType;
   private final IAudioManager audiomanager;
   private final ISmartphoneProperties smartphoneProperties;
   private volatile Subscription rvcSubscription;
   private volatile Subscription rvcSubscription2;
   private final ILastmodehandler lastmodehandler;
   private final ISPIScreenConnectedProvider screenConnectedProvider;
   private final ITerminalModeConfiguration configuration;
   private volatile boolean screenHiddenByPopup = false;
   private volatile boolean MUScreenBorrowRequestSend = false;
   private volatile boolean screenVisibleAfterPoup = false;
   private volatile boolean screenLastModeSentWithStartService = false;
   private volatile SPIBoolean sdsActive = SPIBoolean.INITIAL;
   private final TMTTSHandler ttsHandler;
   private final int REQUIRE_NOTHING = 0;
   private final int REQUIRE_REQUESTUI = 1;
   private final int REQUIRE_TAKE = 2;
   private int rvcOffConstraint = 0;
   private final String DIAG_UPDATE_TEXTINPUT = "textInput(boolean)";
   private CarPlayClusterIntegration clusterIntegration;

   public CarPlayDSIManager(
      IContext var1,
      CarplayDSILifecycleController var2,
      IStateHandler var3,
      CarplaySmartphoneProperties var4,
      IAudioManager var5,
      ISmartphoneProperties var6,
      ILastmodehandler var7,
      ISPIScreenConnectedProvider var8,
      ITerminalModeConfiguration var9,
      TMTTSHandler var10
   ) {
      super(var1, SmartphoneType.CARPLAY);
      this.carPlayDSILifecycleController = var2;
      this.messageMap = new HashMap();
      this.configuration = var9;
      this.stateHandler = var3;
      this.lastmodehandler = var7;
      this.currentState = var3.getCurrentState();
      this.audiomanager = var5;
      this.carPlayDSIController = this.carPlayDSILifecycleController.getDioDsiController();
      this.speechRequestHandler = new CarPlaySpeechRequestHandler(var1, this.carPlayDSIController);
      this.carplaySmartphoneProperties = var4;
      this.smartphoneProperties = var6;
      this.screenConnectedProvider = var8;
      this.phoneCallController = new CarPlayDSIManager$1(this);
      this.ttsHandler = var10;
   }

   public void init() {
      super.init();
      this.carPlayDSILifecycleController.init();

      try {
         this.clusterIntegration = new CarPlayClusterIntegration(this.context);
         this.clusterIntegration.loadConfig();

         try {
            ServiceReference[] var1 = this.context.getServiceManager().getServiceReferences(CombiBAPServiceNavi.class);
            if (var1 != null && var1.length > 0) {
               CombiBAPServiceNavi var2 = (CombiBAPServiceNavi)this.context.getServiceManager().getService(var1[0]);
               if (var2 != null) {
                  this.clusterIntegration.setClusterService(var2);
               }
            }
         } catch (Exception var7) {
            this.logger.log(100000, "[%1.init] CombiBAPServiceNavi lookup failed: %2", "CarPlayDSIManager", var7.toString());
         }

         try {
            ServiceReference[] var9 = this.context.getServiceManager().getServiceReferences(ISysServices.class);
            if (var9 != null && var9.length > 0) {
               ISysServices var13 = (ISysServices)this.context.getServiceManager().getService(var9[0]);
               if (var13 != null) {
                  this.clusterIntegration.setSysServices(var13);
               }
            }
         } catch (Exception var6) {
            this.logger.log(100000, "[%1.init] ISysServices lookup failed: %2", "CarPlayDSIManager", var6.toString());
         }

         try {
            ServiceReference[] var10 = this.context.getServiceManager().getServiceReferences(ICarCoreServices.class);
            if (var10 != null && var10.length > 0) {
               ICarCoreServices var14 = (ICarCoreServices)this.context.getServiceManager().getService(var10[0]);
               if (var14 != null) {
                  this.clusterIntegration.setCarCoreServices(var14);
               }
            }
         } catch (Exception var5) {
            this.logger.log(100000, "[%1.init] ICarCoreServices lookup failed: %2", "CarPlayDSIManager", var5.toString());
         }

         try {
            ServiceReference[] var11 = this.context.getServiceManager().getServiceReferences(ICarExteriorLightService.class);
            if (var11 != null && var11.length > 0) {
               ICarExteriorLightService var15 = (ICarExteriorLightService)this.context.getServiceManager().getService(var11[0]);
               if (var15 != null) {
                  this.clusterIntegration.setExteriorLightService(var15);
               }
            }
         } catch (Exception var4) {
            this.logger.log(100000, "[%1.init] ICarExteriorLightService lookup failed: %2", "CarPlayDSIManager", var4.toString());
         }

         try {
            ServiceReference[] var12 = this.context.getServiceManager().getServiceReferences(PartialPopupBAPService.class);
            if (var12 != null && var12.length > 0) {
               PartialPopupBAPService var16 = (PartialPopupBAPService)this.context.getServiceManager().getService(var12[0]);
               if (var16 != null) {
                  this.clusterIntegration.setPopupService(var16);
               }
            }
         } catch (Exception var3) {
            this.logger.log(100000, "[%1.init] PartialPopupBAPService lookup failed: %2", "CarPlayDSIManager", var3.toString());
         }

         this.clusterIntegration.init();
         this.context.getServiceManager().registerDSIListener(0, "org.dsi.ifc.carplay.DSICarplayListener", this.clusterIntegration);
         this.logger.log(1000000, "[%1.init] CarPlayClusterIntegration registered", "CarPlayDSIManager");
      } catch (Exception var8) {
         this.logger.log(100000, "[%1.init] Failed: %2", "CarPlayDSIManager", var8.toString());
      }

      this.carPlayDSILifecycleController.setStateListener(this);
      this.stateHandler.addStateListener(this);
      this.context.getDiagnosisManager().addDataProvider(-1, this);
      this.context.getDiagnosisManager().addCommandProvider(-1, this);
      this.rvcSubscription = Observables.combineLatest(this.smartphoneProperties.getPropertyMURVCActive(), this.smartphoneProperties.getDisplayIsOff())
         .subscribe(new CarPlayDSIManager$2(this));
      this.rvcSubscription2 = Observables.combineLatest(
            this.smartphoneProperties.getPropertyMURVCActive(), this.smartphoneProperties.getPropertySPIServiceState()
         )
         .subscribe(new CarPlayDSIManager$3(this));
   }

   public void deinit() {
      this.stateHandler.removeStateListener(this);
      this.carPlayDSILifecycleController.deinit();
      super.deinit();
      if (null != this.rvcSubscription) {
         this.rvcSubscription.cancel();
      }

      if (null != this.rvcSubscription2) {
         this.rvcSubscription2.cancel();
      }
   }

   private void updateTMStateWithAudioMediaState(ResourceState var1) {
      ITMState var2 = this.stateHandler.getCurrentState();
      var2.setStateForResource(Resource.AUDIO_MEDIA, var1);
      this.stateHandler.updateState(var2);
   }

   public void activate() {
      if (this.active) {
         this.logger.log(1000000, "[%1.activate] Already active.", "CarPlayDSIManager");
      } else {
         this.active = true;
         super.activate();
         this.logger.log(1000000, "[%1.activate]", "CarPlayDSIManager");
         this.carplaySmartphoneProperties.activate();
         this.context.getTMKeyEventController().setDSIKeyEventController(this.carPlayDSILifecycleController.getKeyEventController());
         if (this.isDsiAvailable()) {
            this.smartphoneManagerListener.updateDSIState(true);
         }

         GMap var1 = Generics.newHashMap();
         var1.put(new ResourceStateChange(Resource.AUDIO_MEDIA, ResourceState.NORMAL, ResourceState.PAUSED), new CarPlayDSIManager$4(this));
         var1.put(new ResourceStateChange(Resource.AUDIO_MEDIA, ResourceState.NORMAL, ResourceState.PAUSED_BY_MUTE), new CarPlayDSIManager$5(this));
         var1.put(new ResourceStateChange(Resource.AUDIO_MEDIA, ResourceState.PAUSED, ResourceState.NORMAL), new CarPlayDSIManager$6(this));
         var1.put(new ResourceStateChange(Resource.AUDIO_MEDIA, ResourceState.PAUSED_BY_MUTE, ResourceState.NORMAL), new CarPlayDSIManager$7(this));
         var1.put(new ResourceStateChange(Resource.AUDIO_MEDIA, ResourceState.PAUSED, ResourceState.PAUSED_BY_MUTE), new CarPlayDSIManager$8(this));
         this.addRequestModeChanges(var1);
         this.stateHandler.addStateChangeActions(var1);
      }
   }

   private void addRequestModeChanges(GMap var1) {
      var1.put(new ResourceOwnerChange(Resource.SCREEN, ResourceOwner.MAINUNIT, ResourceOwner.DEVICE), new CarPlayDSIManager$9(this));
      var1.put(new ResourceOwnerChange(Resource.SCREEN, ResourceOwner.DEVICE, ResourceOwner.MAINUNIT), new CarPlayDSIManager$10(this));
      var1.put(new ResourceOwnerChange(Resource.AUDIO_MEDIA, ResourceOwner.DEVICE, ResourceOwner.MAINUNIT), new CarPlayDSIManager$11(this));
      var1.put(new ApplicationStateChange(Application.SPEECH, ApplicationOwner.DEVICE, ApplicationOwner.NOBODY), new CarPlayDSIManager$12(this));
      var1.put(new ApplicationStateChange(Application.SPEECH, ApplicationOwner.NOBODY, ApplicationOwner.MAINUNIT), new CarPlayDSIManager$13(this));
      var1.put(new ApplicationStateChange(Application.SPEECH, ApplicationOwner.MAINUNIT, ApplicationOwner.NOBODY), new CarPlayDSIManager$14(this));
      var1.put(new ApplicationStateChange(Application.SPEECH, ApplicationOwner.MAINUNIT, ApplicationOwner.DEVICE), new CarPlayDSIManager$15(this));
      var1.put(new ApplicationStateChange(Application.NAVI, ApplicationOwner.DEVICE, ApplicationOwner.MAINUNIT), new CarPlayDSIManager$16(this));
      var1.put(new ApplicationStateChange(Application.NAVI, ApplicationOwner.NOBODY, ApplicationOwner.MAINUNIT), new CarPlayDSIManager$17(this));
      var1.put(new ApplicationStateChange(Application.NAVI, ApplicationOwner.MAINUNIT, ApplicationOwner.NOBODY), new CarPlayDSIManager$18(this));
   }

   public void deactivate() {
      if (!this.active) {
         this.logger.log(1000000, "[%1.deactivate] Mgr is not active.", "CarPlayDSIManager");
      } else {
         this.logger.log(1000000, "[%1.deactivate]", "CarPlayDSIManager");
         if (this.clusterIntegration != null) {
            this.clusterIntegration.onCarplayTerminated();
         }

         this.carplaySmartphoneProperties.deactivate();
         this.stateHandler.removeStateChangeActions();
         super.deactivate();
         this.active = false;
         this.smartphoneManagerListener.updateDSIState(false);
      }
   }

   public void startService(ITMState var1) {
      this.updateActiveApplications(var1);
      this.carPlayDSIController.startService(this.getAppStates(var1), this.filterAudioResources(this.getResources(var1, true)));
      this.screenLastModeSentWithStartService = this.lastmodehandler.isScreenLastmode();
   }

   public void responseUpdateMode(ITMState var1, long var2) {
      this.updateActiveApplications(var1);
      CarplayRequest var4 = (CarplayRequest)this.messageMap.get(Util.createLong(var2));
      this.logger.log(1000000, "[%1.responseUpdateMode] msgId=%2", "CarPlayDSIManager", var2);
      if (null != var4 && 2 == var4.getType()) {
         this.carPlayDSIController.responseUpdateMainAudioType((CarplayAudioType)var4.getParameter("AUDIOTYPE"));
      } else if (-1L != var2) {
         this.carPlayDSIController.responseUpdateMode(this.filterAudioResources(this.getResources(var1, true)), this.getAppStates(var1));
      }
   }

   public void requestModeChange(ITMState var1, String var2, RequestModeChangeCallback var3) {
      throw new UnsupportedOperationException("CarPlay will access this directly. Method to be removed from the interface!");
   }

   public void requestConstraintsChange(ITMState var1, Resource var2, boolean var3) {
      this.logger.log(1000000, "[%1.requestConstraintsChange] %2 %3", "CarPlayDSIManager", var3 ? "restricted" : "allowed", var2);
      this.updateActiveApplications(var1);
      this.carPlayDSIController.requestModeChange(new IDSIAppState[0], this.getResourcesForContraintsChange(var2, var3), "requestConstraintsChange");
      if (!var3 && Resource.SCREEN.is(var2)) {
         this.screenLastModeSentWithStartService = false;
         if (ResourceOwner.DEVICE.is(var1.getOwnerForResource(Resource.SCREEN))) {
            this.requestUI(ScreenId.SCREENID_CARPLAY);
         } else if (this.rvcOffConstraint == 1) {
            this.rvcOffConstraint = 0;
            this.requestUI(ScreenId.SCREENID_CARPLAY);
         }
      }
   }

   private IDSIResource[] getResourcesForContraintsChange(Resource var1, boolean var2) {
      if (var1.is(Resource.SCREEN)) {
         if (var2) {
            return new IDSIResource[]{
               new Builder()
                  .setpOwner(1)
                  .setpResourceId(1)
                  .setDsiResourceId(2)
                  .setDsiResourceOwner(1)
                  .setDsiTakeType(3)
                  .setDsiBorrowConstraint(0)
                  .setDsiTakeConstraint(0)
                  .setDsiUnborrowConstraint(3)
                  .setDsiTransferPriority(1)
                  .build()
            };
         } else if (this.rvcOffConstraint == 2) {
            this.rvcOffConstraint = 0;
            return new IDSIResource[]{
               new Builder()
                  .setpOwner(1)
                  .setpResourceId(1)
                  .setDsiResourceId(2)
                  .setDsiResourceOwner(1)
                  .setDsiTakeType(1)
                  .setDsiTransferPriority(1)
                  .setDsiTakeConstraint(2)
                  .setDsiBorrowConstraint(1)
                  .setDsiUnborrowConstraint(0)
                  .build()
            };
         } else {
            return new IDSIResource[]{
               new Builder()
                  .setpOwner(1)
                  .setpResourceId(1)
                  .setDsiResourceId(2)
                  .setDsiResourceOwner(0)
                  .setDsiTakeType(4)
                  .setDsiBorrowConstraint(0)
                  .setDsiTakeConstraint(0)
                  .setDsiUnborrowConstraint(0)
                  .setDsiTransferPriority(0)
                  .build()
            };
         }
      } else if (var1.is(Resource.AUDIO_MEDIA)) {
         return var2
            ? new IDSIResource[]{
               new Builder()
                  .setpOwner(1)
                  .setpResourceId(3)
                  .setDsiResourceId(1)
                  .setDsiResourceOwner(1)
                  .setDsiTakeType(3)
                  .setDsiBorrowConstraint(0)
                  .setDsiTakeConstraint(0)
                  .setDsiUnborrowConstraint(3)
                  .setDsiTransferPriority(1)
                  .build()
            }
            : new IDSIResource[]{
               new Builder()
                  .setpOwner(1)
                  .setpResourceId(3)
                  .setDsiResourceId(1)
                  .setDsiResourceOwner(0)
                  .setDsiTakeType(4)
                  .setDsiBorrowConstraint(0)
                  .setDsiTakeConstraint(0)
                  .setDsiUnborrowConstraint(0)
                  .setDsiTransferPriority(0)
                  .build()
            };
      } else {
         return new IDSIResource[0];
      }
   }

   private IDSIResource[] filterAudioResources(IDSIResource[] var1) {
      return this.filterAudioResources(var1, true);
   }

   private IDSIResource[] filterAudioResources(IDSIResource[] var1, boolean var2) {
      IDSIResource[] var3 = new IDSIResource[2];

      for (int var4 = 0; var4 < var1.length; var4++) {
         if (3 == var1[var4].getResourceId()) {
            if (this.waitForAudioType && var1[var4].getOwner() != 2) {
               var3[1] = this.createResource(3, 2, var2);
            } else {
               var3[1] = var1[var4];
            }
         } else if (1 == var1[var4].getResourceId()) {
            var3[0] = var1[var4];
         }
      }

      return var3;
   }

   private IDSIResource[] getResources(ITMState var1, boolean var2) {
      return new IDSIResource[]{
         var1.getStateForResource(Resource.AUDIO_MEDIA).is(ResourceState.PAUSED_BY_MUTE)
            ? new Builder()
               .setpOwner(1)
               .setpResourceId(3)
               .setDsiResourceId(1)
               .setDsiResourceOwner(1)
               .setDsiTakeType(3)
               .setDsiBorrowConstraint(0)
               .setDsiTakeConstraint(0)
               .setDsiUnborrowConstraint(1)
               .setDsiTransferPriority(1)
               .build()
            : (
               var1.getStateForResource(Resource.AUDIO_MEDIA).is(ResourceState.PAUSED)
                  ? new Builder()
                     .setpOwner(1)
                     .setpResourceId(3)
                     .setDsiResourceId(1)
                     .setDsiResourceOwner(1)
                     .setDsiTakeType(3)
                     .setDsiBorrowConstraint(0)
                     .setDsiTakeConstraint(0)
                     .setDsiUnborrowConstraint(2)
                     .setDsiTransferPriority(1)
                     .build()
                  : this.createResource(
                     3,
                     !var1.isResourceOwnerMainUnit(Resource.AUDIO_MEDIA)
                           && !var1.getStateForResource(Resource.AUDIO_MEDIA).is(new ResourceState[]{ResourceState.PAUSED, ResourceState.PAUSED_BY_MUTE})
                        ? 2
                        : 1,
                     var2
                  )
            ),
         this.createResource(4, var1.isResourceOwnerMainUnit(Resource.AUDIO_PHONE) ? 1 : 2, var2),
         this.createResource(5, var1.isResourceOwnerMainUnit(Resource.AUDIO_SPEECH) ? 1 : 2, var2),
         this.createResource(7, var1.isResourceOwnerMainUnit(Resource.AUDIO_RINGTONE) ? 1 : 2, var2),
         this.createResource(1, var1.isResourceOwnerMainUnit(Resource.SCREEN) ? 1 : 2, var2)
      };
   }

   private void requestUI(ScreenId var1) {
      this.logger.log(1000000, "[%1.requestUI] %2", "CarPlayDSIManager", var1);
      this.carPlayDSIController.requestUI(var1);
   }

   protected IDSIAppState createAppState(int var1, int var2, int var3) {
      return new CarPlayAppState(var1, var2, var3);
   }

   private IDSIResource createResource(int var1, int var2, boolean var3) {
      return new CarPlayResource(var1, var2, var3 ? this.getActiveApplications() : this.activeApplications);
   }

   private int getActiveApplications() {
      return this.activeApplications + this.context.getConfiguration().applicationOffset();
   }

   private void updateActiveApplications(ITMState var1) {
      this.activeApplications = var1.isAppOwnerMainUnit(Application.SPEECH) ? (this.activeApplications |= 16) : (this.activeApplications &= -17);
      this.activeApplications = var1.isAppOwnerMainUnit(Application.PHONE) ? (this.activeApplications |= 2) : (this.activeApplications &= -3);
      this.activeApplications = var1.isAppOwnerMainUnit(Application.NAVI) ? (this.activeApplications |= 8) : (this.activeApplications &= -9);
      this.activeApplications = var1.isResourceOwnerMainUnit(Resource.AUDIO_MEDIA) ? (this.activeApplications |= 4) : (this.activeApplications &= -5);
      this.logger.log(1000000, "[%1.updateActiveApplications] %2", "CarPlayDSIManager", LoggingUtil.activeApplicationBitsToString(this.activeApplications));
   }

   public void updateMode(IAppState[] var1, IResource[] var2) {
      if (this.clusterIntegration != null) {
         for (int var4 = 0; var4 < var2.length; var4++) {
            int var3 = var2[var4].getResourceId();
            int var5 = var2[var4].getOwner();
            if (!(Boolean)this.smartphoneProperties.getDisplayIsOff().get() || var3 != 1) {
               this.clusterIntegration.onResourceChanged(var3, var5);
            }
         }
      }

      ArrayList var7 = new ArrayList(var2.length);

      for (int var6 = 0; var6 < var2.length; var6++) {
         if (var2[var6].getResourceId() == 2) {
            if (var2[var6].getOwner() != 1) {
               if (var2[var6].getOwner() == 2) {
                  this.waitForAudioType = true;
               }
            } else {
               var7.add(new CarPlayResource(3, 1, this.getActiveApplications()));
               var7.add(new CarPlayResource(4, 1, this.getActiveApplications()));
               var7.add(new CarPlayResource(5, 1, this.getActiveApplications()));
               var7.add(new CarPlayResource(7, 1, this.getActiveApplications()));
               this.currentActiveResource = null;
               this.waitForAudioType = false;
            }
         } else if ((Boolean)this.smartphoneProperties.getDisplayIsOff().get() && var2[var6].getResourceId() == 1) {
            this.logger.log(1000000, "[%1.updateMode] Display OFF -> no update for the screen.", "CarPlayDSIManager");
         } else {
            var7.add(var2[var6]);
         }
      }

      CarplayRequest var8 = new CarplayRequest(++this.messageIdCounter, 1);
      this.messageMap.put(Util.createLong(var8.getMessageId()), var8);
      this.updateMode(var8.getMessageId(), var1, var7.toArray(new IResource[var7.size()]));
   }

   public void updateTextInputState(boolean var1) {
      this.smartphoneManagerListener.updateTextInputState(var1);
   }

   public void duckAudio(int var1, double var2) {
      this.logger.log(1000000, "[%1.duckAudio] dur=%2 vol=%3", "CarPlayDSIManager", String.valueOf(var1), String.valueOf(var2));
      this.smartphoneManagerListener.duckAudio(var1, var2);
   }

   public void unduckAudio(int var1) {
      this.logger.log(1000000, "[%1.unduckAudio] dur=%2", "CarPlayDSIManager", var1);
      this.smartphoneManagerListener.unduckAudio(var1);
   }

   public void updateMainAudioType(MainAudioTypeUpdate var1) {
      this.logger
         .log(1000000, "[%1.updateMainAudioType] %2 %3", "CarPlayDSIManager", TerminalModeUtils.logAudioType(var1.getAudioType()), var1.getSampleRate());
      this.waitForAudioType = false;
      byte var2 = 0;
      CarplayAudioType var3 = CarplayAudioType.NONE;
      TMAudioConnection var4 = TMAudioConnection.INVALID;
      switch (var1.getAudioType()) {
         case 1:
            var2 = 7;
            var3 = CarplayAudioType.ALERT;
            var4 = TMAudioConnection.RINGTONE;
            break;
         case 2:
            var2 = 3;
            var3 = CarplayAudioType.MEDIA;
            var4 = TMAudioConnection.MEDIA;
            this.ttsHandler.terminateTTS();
            break;
         case 3:
            var2 = 4;
            var3 = CarplayAudioType.TELEPHONY;
            var4 = TMAudioConnection.PHONE;
            break;
         case 4:
            var2 = 5;
            var3 = CarplayAudioType.SPEECHRECOGNITION;
      }

      if (5 == var2 && (Boolean)this.smartphoneProperties.getDisplayIsOff().get() && null != this.context.getFramework().getPowerMgr()) {
         this.context.getFramework().getMsgDistrib().sendMessage(1025);
         this.context.getFramework().getPowerMgr().keyPTTPressed();
      }

      if (this.configuration.isSetSampleRateRequired() && TMAudioConnection.INVALID.isNot(var4) && -1 != var1.getSampleRate()) {
         this.context
            .getCommandListHelper()
            .create()
            .addSingle(new SetSampleRate(this.context, this.audiomanager, var4, var1.getSampleRate()))
            .execute("CarplayDSIManager.updateMainAudioType");
      }

      CarplayRequest var5 = new CarplayRequest(++this.messageIdCounter, 2);
      var5.addParameter("AUDIOTYPE", var3);
      this.messageMap.put(Util.createLong(var5.getMessageId()), var5);
      CarPlayResource var6 = this.currentActiveResource;
      CarPlayResource var7 = this.currentActiveResource = 0 != var2 ? new CarPlayResource(var2, 2, this.getActiveApplications()) : null;
      if (null != var6 && (var6.getResourceId() != 3 || null == this.currentActiveResource)) {
         CarPlayResource var8 = new CarPlayResource(var6.getResourceId(), 1, this.getActiveApplications());
         if (null != this.currentActiveResource) {
            this.updateMode(var5.getMessageId(), new IAppState[0], new IResource[]{var8, this.currentActiveResource});
         } else {
            this.updateMode(var5.getMessageId(), new IAppState[0], new IResource[]{var8});
         }
      } else {
         this.updateMode(var5.getMessageId(), new IAppState[0], new IResource[]{this.currentActiveResource});
      }
   }

   public void updateMode(long var1, IAppState[] var3, IResource[] var4) {
      this.logger.log(1000000, "[%1.updateMode]", "CarPlayDSIManager");
      AbstractCommand var5 = this.getCurrentCommand();
      if (null == var5 || !var5.updateStates(var3, var4, var1)) {
         this.context
            .getCommandListHelper()
            .create()
            .addSingle(new UpdateMode(this.context, this, var3, var4, var1, this.stateHandler))
            .addSingle(new SendResponseModeChanged(this.context, this, var3, var4, var1, this.stateHandler))
            .execute("SmartphoneManager.updateMode");
      }
   }

   private AbstractCommand getCurrentCommand() {
      return (AbstractCommand)this.context.getCommandListManager().getActiveCommand().get();
   }

   public void seek(boolean var1, boolean var2) {
   }

   public void skip(boolean var1) {
   }

   public void skipButton(boolean var1, boolean var2) {
      this.carPlayDSIController
         .postButtonEvent(var1 ? CarplayButton.SKIP_FORWARD : CarplayButton.SKIP_BACKWARD, var2 ? CarplayButtonState.RELEASED : CarplayButtonState.PRESSED);
   }

   public void resume() {
   }

   public void pause(boolean var1) {
   }

   public void oemAppSelected() {
      this.logger.log(1000000, "[%1.oemAppSelected]", "CarPlayDSIManager");
      ChoiceModelApp var1 = this.context.getChoiceModel(3200014);
      var1.setValue(var1.getValue() == 0 ? 1 : 0);
   }

   public void updateState(ITMState var1) {
      this.currentState.update(var1);
   }

   public String getDiagKey() {
      return "getActiveConstraints";
   }

   public String getDiagValue() {
      Buffer var1 = new Buffer(200);
      int var2 = this.getActiveApplications();
      var1.append("Active apps: ");
      var1.append(var2);
      var1.append("\nScreen\n transfer type: ");
      var1.append(CarplayUtils.logTransferType(CarplayUtils.getDsiTransferType(var2, true, false)));
      var1.append("\ntake constraint: ");
      var1.append(CarplayUtils.logResourceSharingPolicy(CarplayUtils.getDsiTakeConstraint(var2, true, false, false, false)));
      var1.append("\nborrow constraint: ");
      var1.append(CarplayUtils.logResourceSharingPolicy(CarplayUtils.getDsiBorrowConstraint(var2, true, false)));
      var1.append("\nunborrow constraint: ");
      var1.append(CarplayUtils.logResourceSharingPolicy(CarplayUtils.getDsiUnborrowConstraint(var2, true, false)));
      var1.append("\nAudio\n transfer type: ");
      var1.append(CarplayUtils.logTransferType(CarplayUtils.getDsiTransferType(var2, false, false)));
      var1.append("\n take constraint: ");
      var1.append(CarplayUtils.logResourceSharingPolicy(CarplayUtils.getDsiTakeConstraint(var2, false, false, false, false)));
      var1.append("\n borrow constraint: ");
      var1.append(CarplayUtils.logResourceSharingPolicy(CarplayUtils.getDsiBorrowConstraint(var2, false, false)));
      var1.append("\n unborrow constraint: ");
      var1.append(CarplayUtils.logResourceSharingPolicy(CarplayUtils.getDsiUnborrowConstraint(var2, false, false)));
      return var1.toString();
   }

   public String[] getDiagKeys() {
      return new String[]{"textInput(boolean)"};
   }

   public void executeDiagCommand(String var1, String[] var2) {
      if ("textInput(boolean)".equals(var1) && null != var2 && var2.length >= 1) {
         boolean var3 = Boolean.valueOf(var2[0]);
         this.updateTextInputState(var3);
      }
   }

   public void requestNightMode(boolean var1) {
      this.carPlayDSIController.requestNightMode(var1);
   }

   public ISpeechRequestHandler getSpeechRequestHandler() {
      return this.speechRequestHandler;
   }

   public IPhoneCallController getPhoneCallController() {
      return this.phoneCallController;
   }

   public ILastmodehandler getLastmodeHandler() {
      return this.lastmodehandler;
   }

   public void screenChangeAction() {
      this.logger.log(1000000, "[%1.execute] Apple screen is coming", "CarPlayDSIManager");
      this.context.getFramework().getHMIService().removeCurrentPopup(0);
   }

   public void setScreenHiddenByPopup() {
      if (ResourceOwner.DEVICE.is(this.currentState.getOwnerForResource(Resource.SCREEN))) {
         this.screenHiddenByPopup = true;
      }
   }

   public void setScreenVisibleAfterPopup() {
      this.screenVisibleAfterPoup = true;
   }

   private class RequestAudio extends AbstractDSICommand {
      private static final String LOGCLASS = "RequestModeChangeCarPlay";
      private final IStateHandler stateHandler;

      public RequestAudio(IContext var2, IStateHandler var3) {
         super(var2.getLogger().main(), "RequestModeChangeCarPlay", var2, var2.getSmartphoneDSIManager());
         this.stateHandler = var3;
      }

      public void execute() {
         this.logger.log(1000000, "### CMD ### [%1]", "RequestModeChangeCarPlay");
         TMDevice var1 = this.context.getDeviceManager().getActiveDevice();
         if (null == var1 || var1.connectionState().is(ConnectionState.NOT_ATTACHED)) {
            this.stateHandler.setOwnerForResource(Resource.AUDIO_MEDIA, ResourceOwner.MAINUNIT);
            this.finish();
         }

         CarPlayDSIManager.this.carPlayDSIController
            .requestModeChange(
               new IDSIAppState[0],
               new IDSIResource[]{
                  new Builder()
                     .setpOwner(1)
                     .setpResourceId(3)
                     .setDsiResourceId(1)
                     .setDsiResourceOwner(1)
                     .setDsiTakeType(1)
                     .setDsiTransferPriority(1)
                     .setDsiTakeConstraint(2)
                     .setDsiBorrowConstraint(1)
                     .setDsiUnborrowConstraint(0)
                     .build()
               },
               "Audio Teardown"
            );
         this.stateHandler.setOwnerForResource(Resource.AUDIO_MEDIA, ResourceOwner.MAINUNIT);
         this.finish();
      }
   }

   private class RequestModeChangeCarPlay extends AbstractDSICommand {
      private static final String LOGCLASS = "RequestModeChangeCarPlay";
      private final ITMState newState;
      private final IStateHandler stateHandler;

      public RequestModeChangeCarPlay(IContext var2, ITMState var3, IStateHandler var4) {
         super(var2.getLogger().main(), "RequestModeChangeCarPlay", var2, var2.getSmartphoneDSIManager());
         this.newState = var3;
         this.stateHandler = var4;
      }

      public void execute() {
         this.logger.log(1000000, "### CMD ### [%1]", "RequestModeChangeCarPlay");
         TMDevice var1 = this.context.getDeviceManager().getActiveDevice();
         if (null == var1 || var1.connectionState().is(ConnectionState.NOT_ATTACHED)) {
            this.stateHandler.updateState(this.newState);
            this.finish();
         }

         this.requestModeChangeCP(this.newState, "user action");
         this.stateHandler.updateState(this.newState);
         this.finish();
      }

      private void requestModeChangeCP(ITMState var1, String var2) {
         CarPlayDSIManager.this.updateActiveApplications(var1);
         if (TerminalModeUtils.equalsResourcesOwner(CarPlayDSIManager.this.currentState.getResourceOwner(), var1.getResourceOwner())) {
            CarPlayDSIManager.this.carPlayDSIController.requestModeChange(CarPlayDSIManager.this.getAppStates(var1), new IDSIResource[0], var2);
         } else {
            if (CarPlayDSIManager.this.currentState.isResourceOwnerMainUnit(Resource.SCREEN) && var1.isResourceOwnerDevice(Resource.SCREEN)) {
               if (this.context.getConfiguration().applicationOffset() > 0) {
                  CarPlayDSIManager.this.carPlayDSIController
                     .requestModeChange(
                        CarPlayDSIManager.this.getAppStates(var1),
                        CarPlayDSIManager.this.filterAudioResources(CarPlayDSIManager.this.getResources(var1, false), false),
                        var2
                     );
               }

               if (!(Boolean)CarPlayDSIManager.this.smartphoneProperties.getDisplayIsOff().get()) {
                  SPIBoolean var4 = (SPIBoolean)CarPlayDSIManager.this.smartphoneProperties.getPropertyMUHFPPhonecallActive().get();
                  if (!var4.isInitializing() && var4.getBoolean()) {
                     CarPlayDSIManager.this.carPlayDSIController
                        .requestModeChange(
                           new IDSIAppState[0], new IDSIResource[]{TerminalModeUtils.getUnborrowScreen()}, "mainunit call active and screen entered"
                        );
                  }

                  if (CarPlayDSIManager.this.screenVisibleAfterPoup) {
                     CarPlayDSIManager.this.carPlayDSIController
                        .requestModeChange(new IDSIAppState[0], new IDSIResource[]{TerminalModeUtils.getUnborrowScreen()}, "Screen Setup");
                     CarPlayDSIManager.this.screenVisibleAfterPoup = false;
                     CarPlayDSIManager.this.MUScreenBorrowRequestSend = false;
                     return;
                  }

                  CarPlayDSIManager.this.requestUI(ScreenId.SCREENID_CARPLAY);
               }

               if (CarPlayDSIManager.this.currentState.getOwnerForResource(Resource.AUDIO_MEDIA) == var1.getOwnerForResource(Resource.AUDIO_MEDIA)) {
                  return;
               }
            }

            if (!CarPlayDSIManager.this.currentState.isResourceStatePausedByMute(Resource.AUDIO_MEDIA) || !var1.isResourceOwnerMainUnit(Resource.AUDIO_MEDIA)) {
               CarPlayDSIManager.this.waitForAudioType = var1.getOwnerForResource(Resource.AUDIO_MEDIA).isNot(ResourceOwner.MAINUNIT)
                  && var1.getStateForResource(Resource.AUDIO_MEDIA).is(ResourceState.NORMAL);
               IDSIResource[] var3 = CarPlayDSIManager.this.filterAudioResources(CarPlayDSIManager.this.getResources(var1, true));
               if (CarPlayDSIManager.this.currentState.getOwnerForResource(Resource.AUDIO_MEDIA) == var1.getOwnerForResource(Resource.AUDIO_MEDIA)
                  && CarPlayDSIManager.this.currentState.getStateForResource(Resource.AUDIO_MEDIA)
                     == CarPlayDSIManager.this.currentState.getStateForResource(Resource.AUDIO_MEDIA)) {
                  if (CarPlayDSIManager.this.screenHiddenByPopup) {
                     CarPlayDSIManager.this.carPlayDSIController
                        .requestModeChange(new IDSIAppState[0], new IDSIResource[]{TerminalModeUtils.getBorrowScreenNotification()}, "Screen teardown");
                     CarPlayDSIManager.this.screenHiddenByPopup = false;
                     CarPlayDSIManager.this.MUScreenBorrowRequestSend = true;
                     return;
                  }

                  var3 = new IDSIResource[]{var3[0]};
               }

               CarPlayDSIManager.this.carPlayDSIController.requestModeChange(CarPlayDSIManager.this.getAppStates(var1), var3, var2);
            }
         }
      }
   }
}
