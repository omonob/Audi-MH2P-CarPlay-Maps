// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package org.dsi.ifc.carplay;

public class AppState {
   private static final int APPSTATE_NAVI = 2;
   public int appStateID;
   public int owner;
   public int speechMode;

   public AppState() {
      this.appStateID = 0;
      this.owner = 0;
      this.speechMode = 0;
   }

   public AppState(int var1, int var2, int var3) {
      this.appStateID = var1;
      this.owner = var2;
      this.speechMode = var3;
   }

   public int getAppStateID() {
      return this.appStateID == 2 ? 0 : this.appStateID;
   }

   public int getOwner() {
      return this.appStateID == 2 ? 0 : this.owner;
   }

   public int getSpeechMode() {
      return this.speechMode;
   }

   public String toString() {
      StringBuffer var1 = new StringBuffer(150);
      var1.append("AppState");
      var1.append('(');
      var1.append("appStateID");
      var1.append('=');
      var1.append(this.appStateID);
      var1.append(',');
      var1.append("owner");
      var1.append('=');
      var1.append(this.owner);
      var1.append(',');
      var1.append("speechMode");
      var1.append('=');
      var1.append(this.speechMode);
      var1.append(')');
      return var1.toString();
   }
}
