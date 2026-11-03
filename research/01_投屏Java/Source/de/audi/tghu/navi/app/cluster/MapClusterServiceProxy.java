// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.tghu.navi.app.cluster;

import de.audi.app.terminalmode.smartphone.carplay.CarPlayClusterIntegration;
import de.audi.atip.log.LogChannel;
import de.audi.atip.utils.dispatching.IDispatcher;
import de.audi.tghu.navi.app.dispatcher.ENaviDispatcher;
import de.audi.tghu.navi.app.dispatcher.NaviDispatcherFactory;
import de.audi.tghu.navi.app.map.enums.ESetupOption;
import de.audi.tghu.navi.app.map.mapcontent.MapContentList;
import de.audi.tghu.navi.app.util.NaviDisposable;
import de.eso.hmiservice.display.DisplayManager;
import org.osgi.framework.BundleContext;
import org.osgi.framework.ServiceReference;
import org.osgi.util.tracker.ServiceTracker;
import org.osgi.util.tracker.ServiceTrackerCustomizer;

public class MapClusterServiceProxy extends NaviDisposable implements ServiceTrackerCustomizer, IMapClusterService {
   private final BundleContext bundleContext;
   private final LogChannel logChannel;
   private final ServiceTracker serviceTracker;
   private IMapClusterService mapClusterService = null;
   private final IDispatcher dispatcher;

   public MapClusterServiceProxy(String var1, LogChannel var2, BundleContext var3, NaviDispatcherFactory var4) {
      this.logChannel = var2;
      this.bundleContext = var3;
      this.dispatcher = var4.createDispatcher(ENaviDispatcher.CLUSTER, var1, var2);
      this.serviceTracker = new ServiceTracker(var3, IMapClusterService.class.getName(), this);
      this.serviceTracker.open();
   }

   public void dispose() {
      this.serviceTracker.close();
   }

   public Object addingService(ServiceReference var1) {
      if (this.bundleContext != null && var1 != null) {
         Object var2 = this.bundleContext.getService(var1);
         if (!(var2 instanceof IMapClusterService)) {
            this.logChannel.log(10000, "NaviClusterServiceProxy#addingService() - got invalid service: %1", var2);
            this.bundleContext.ungetService(var1);
            return null;
         } else {
            this.logChannel.log(1000000, "NaviClusterServiceProxy#addingService() - got navi cluster service");
            this.mapClusterService = (IMapClusterService)var2;
            return var2;
         }
      } else {
         this.logChannel.log(10000, "NaviClusterServiceProxy#addingService() - bundleContext: %1, reference: %2", this.bundleContext, var1);
         return null;
      }
   }

   public void modifiedService(ServiceReference var1, Object var2) {
   }

   public void removedService(ServiceReference var1, Object var2) {
      if (var1 == null) {
         this.logChannel.log(10000, "NaviClusterServiceProxy#removedService() - got null reference");
      } else {
         if (var2 instanceof IMapClusterService) {
            this.mapClusterService = null;
         } else {
            this.logChannel.log(10000, "NaviClusterFPKActivator#removedService() - invalid service: %1", var2);
         }

         this.bundleContext.ungetService(var1);
      }
   }

   public boolean isAvailable() {
      return this.mapClusterService != null;
   }

   public void setKombiMapSetupOption(ESetupOption var1, int var2) {
      this.dispatcher.execute(new MapClusterServiceProxy$1(this, var1, var2));
   }

   public void switchKombiMapToAShownContext() {
      this.dispatcher.execute(new MapClusterServiceProxy$2(this));
   }

   public void switchKombiMapToHiddenContext() {
      this.dispatcher.execute(new MapClusterServiceProxy$3(this));
   }

   public void changeMapContentListItemSelection(MapContentList var1) {
      this.dispatcher.execute(new MapClusterServiceProxy$4(this, var1));
   }

   public void selectAllMapContents(boolean var1) {
      this.dispatcher.execute(new MapClusterServiceProxy$5(this, var1));
   }

   public void selectAllMapContents(MapContentList var1, boolean var2) {
      this.dispatcher.execute(new MapClusterServiceProxy$6(this, var1, var2));
   }

   public void changeMapContentStaticItemSelection(ESetupOption var1) {
      this.dispatcher.execute(new MapClusterServiceProxy$7(this, var1));
   }

   public void changeZoomLevel(int var1) {
      if (DisplayManager.isClusterMap33Selected() || !CarPlayClusterIntegration.forwardMapZoomToCarplay(var1)) {
         this.dispatcher.execute(new MapClusterServiceProxy$8(this, var1));
      }
   }

   public void notifyViewSizeChanged(boolean var1) {
      this.dispatcher.execute(new MapClusterServiceProxy$9(this, var1));
   }

   public void suspendSetup() {
      this.dispatcher.execute(new MapClusterServiceProxy$10(this));
   }

   public void resumeSetupAndStore() {
      this.dispatcher.execute(new MapClusterServiceProxy$11(this));
   }
}
