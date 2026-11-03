// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.tghu.navi.app.cluster;

class MapClusterServiceProxy$2 implements Runnable {
   MapClusterServiceProxy$2(MapClusterServiceProxy var1) {
      this.this$0 = var1;
   }

   public void run() {
      MapClusterServiceProxy.access$000(this.this$0).log(10000000, "NaviClusterServiceProxy#switchToAShownContext()");
      MapClusterServiceProxy.access$100(this.this$0).switchKombiMapToAShownContext();
   }
}
