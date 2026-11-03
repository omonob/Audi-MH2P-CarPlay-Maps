// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

final class CarPlaySideStreets {
   private static final float[] EXITS_FULL_17 = new float[]{
      -180.0F, -157.5F, -135.0F, -112.5F, -90.0F, -67.5F, -45.0F, -22.5F, 0.0F, 22.5F, 45.0F, 67.5F, 90.0F, 112.5F, 135.0F, 157.5F, 180.0F
   };
   private static final float[] EXITS_15 = new float[]{
      -157.5F, -135.0F, -112.5F, -90.0F, -67.5F, -45.0F, -22.5F, 0.0F, 22.5F, 45.0F, 67.5F, 90.0F, 112.5F, 135.0F, 157.5F
   };
   private static final float[] EXITS_7 = new float[]{135.0F, 90.0F, 45.0F, 0.0F, -45.0F, -90.0F, -135.0F};
   private static final int EXIT_ANGLE_MISSING = 1000;
   private static final int SIDE_FIXED_LEFT = 192;
   private static final int SIDE_FIXED_RIGHT = 64;
   private static final int SIDE_FIXED_ZERO = 0;

   private CarPlaySideStreets() {
   }

   static byte[] calcSideStreetsBytes(int var0, int var1, int var2, int[] var3, int var4) {
      int[] var5 = calcSideStreetDirections(var0, var1, var2, var3, var4);
      return toByteArray(var5);
   }

   static int[] calcSideStreetDirections(int var0, int var1, int var2, int[] var3, int var4) {
      if (var0 == 7) {
         return new int[0];
      } else if (var0 == 6) {
         return new int[]{var2 == 1 ? 192 : 64};
      } else if (var0 == 8 || var0 == 22 || var0 == 23) {
         return new int[]{0};
      } else if (!computesSidestreets(var0, var1)) {
         return new int[0];
      } else if (var3 == null || var3.length == 0) {
         return new int[0];
      } else if (var4 == 1000) {
         return new int[0];
      } else if (var1 != 0 && var1 != 1) {
         return new int[0];
      } else {
         return var1 == 1 ? occupiedSidestreetsRoundabout(var2, var3, var4) : occupiedSidestreetsIntersection(var3, var4);
      }
   }

   private static int[] occupiedSidestreetsIntersection(int[] var0, int var1) {
      CarPlaySideStreets.SplitAngles var2 = splitAnglesNative(var0, var1);
      int[] var3 = var2.below;
      int[] var4 = var2.above;
      float var5 = closestExit(var1, EXITS_7);
      int var6 = indexOf(EXITS_7, var5);
      if (var6 < 0) {
         return new int[0];
      } else {
         float[] var7 = slice(EXITS_7, 0, var6);
         float[] var8 = reverseSlice(EXITS_7, var6 + 1, EXITS_7.length);
         if (var4.length <= var7.length && var3.length <= var8.length) {
            CarPlaySideStreets.EntryList var9 = new CarPlaySideStreets.EntryList(16);
            appendEntries(var9, var4, var7);
            appendEntries(var9, var3, var8);
            return emitUniqueDirectionCodes(var9);
         } else {
            return new int[0];
         }
      }
   }

   private static int[] occupiedSidestreetsRoundabout(int var0, int[] var1, int var2) {
      float var6 = closestExit(var2, EXITS_FULL_17);
      CarPlaySideStreets.SplitAngles var7 = splitAnglesNative(var1, var2);
      int[] var8 = var7.below;
      int[] var9 = var7.above;
      int[] var10 = var0 == 1 ? var8 : var9;
      int[] var5 = var0 == 1 ? var9 : var8;
      float[] var3;
      float[] var4;
      if (var6 != 180.0F && var6 != -180.0F) {
         int var12 = indexOf(EXITS_15, var6);
         if (var12 < 0) {
            var4 = copyFloats(EXITS_15);
            var3 = new float[0];
         } else {
            float[] var13 = reverseSlice(EXITS_15, var12 + 1, EXITS_15.length);
            float[] var14 = slice(EXITS_15, 0, var12);
            var4 = var0 == 1 ? var14 : var13;
            var3 = var0 == 1 ? var13 : var14;
         }
      } else {
         var4 = copyFloats(EXITS_15);
         var3 = new float[0];
      }

      if (var10.length > var4.length) {
         return new int[0];
      }

      CarPlaySideStreets.EntryList var16 = new CarPlaySideStreets.EntryList(24);
      appendEntries(var16, var10, var4);
      if (var5.length <= var3.length) {
         appendEntries(var16, var5, var3);
      }

      return emitUniqueDirectionCodes(var16);
   }

   private static void appendEntries(CarPlaySideStreets.EntryList var0, int[] var1, float[] var2) {
      if (var0 != null) {
         if (var1 != null && var1.length != 0) {
            if (var2 != null && var2.length != 0) {
               int var3 = var1.length;

               for (int var4 = 0; var4 < var1.length; var4++) {
                  float[] var5 = bestMatchingExitPairs(var1[var4], var3, var2);
                  float var6 = var5.length >= 2 ? var5[0] : Float.MAX_VALUE;
                  var0.add(new CarPlaySideStreets.Entry(var6, var5));
               }
            }
         }
      }
   }

   private static int[] emitUniqueDirectionCodes(CarPlaySideStreets.EntryList var0) {
      if (var0 != null && var0.size() != 0) {
         sortEntriesByMinDiff(var0);
         CarPlaySideStreets.IntList var1 = new CarPlaySideStreets.IntList(16);

         for (int var2 = 0; var2 < var0.size(); var2++) {
            CarPlaySideStreets.Entry var3 = var0.get(var2);
            if (var3 != null && var3.pairs != null) {
               float[] var4 = var3.pairs;

               for (byte var5 = 1; var5 < var4.length; var5 += 2) {
                  int var6 = angleToDirectionCode(var4[var5]);
                  if (!var1.contains(var6)) {
                     var1.add(var6);
                     break;
                  }
               }
            }
         }

         return var1.toArray();
      } else {
         return new int[0];
      }
   }

   private static void sortEntriesByMinDiff(CarPlaySideStreets.EntryList var0) {
      for (int var1 = 1; var1 < var0.size(); var1++) {
         CarPlaySideStreets.Entry var3 = var0.get(var1);
         float var4 = var3 != null ? var3.minDiff : Float.MAX_VALUE;

         int var2;
         for (var2 = var1 - 1; var2 >= 0; var2--) {
            CarPlaySideStreets.Entry var6 = var0.get(var2);
            float var5 = var6 != null ? var6.minDiff : Float.MAX_VALUE;
            if (var5 <= var4) {
               break;
            }

            var0.set(var2 + 1, var6);
         }

         var0.set(var2 + 1, var3);
      }
   }

   private static float[] bestMatchingExitPairs(int var0, int var1, float[] var2) {
      if (var2 != null && var2.length != 0 && var1 > 0) {
         if (var1 > var2.length) {
            var1 = var2.length;
         }

         float var4 = var0;
         float[] var5 = new float[var2.length];
         int[] var6 = new int[var2.length];

         for (int var3 = 0; var3 < var2.length; var6[var3] = var3++) {
            float var7 = var2[var3] - var4;
            if (var7 < 0.0F) {
               var7 = -var7;
            }

            var5[var3] = var7;
         }

         for (int var12 = 1; var12 < var6.length; var12++) {
            int var10 = var6[var12];
            float var11 = var5[var10];

            int var8;
            float var9;
            int var13;
            for (var8 = var12 - 1; var8 >= 0 && !((var9 = var5[var13 = var6[var8]]) <= var11); var8--) {
               var6[var8 + 1] = var13;
            }

            var6[var8 + 1] = var10;
         }

         float[] var14 = new float[var1 * 2];

         for (int var15 = 0; var15 < var1; var15++) {
            int var16 = var6[var15];
            var14[var15 * 2] = var5[var16];
            var14[var15 * 2 + 1] = var2[var16];
         }

         return var14;
      } else {
         return new float[0];
      }
   }

   private static float closestExit(float var0, float[] var1) {
      if (var1 != null && var1.length != 0) {
         float var2 = var1[0];
         float var3 = abs(var2 - var0);

         for (int var4 = 1; var4 < var1.length; var4++) {
            float var5 = abs(var1[var4] - var0);
            if (var5 < var3) {
               var3 = var5;
               var2 = var1[var4];
            }
         }

         return var2;
      } else {
         return 0.0F;
      }
   }

   private static float abs(float var0) {
      return var0 < 0.0F ? -var0 : var0;
   }

   private static int indexOf(float[] var0, float var1) {
      if (var0 == null) {
         return -1;
      }

      for (int var2 = 0; var2 < var0.length; var2++) {
         if (var0[var2] == var1) {
            return var2;
         }
      }

      return -1;
   }

   private static float[] slice(float[] var0, int var1, int var2) {
      if (var0 == null) {
         return new float[0];
      }

      if (var1 < 0) {
         var1 = 0;
      }

      if (var2 > var0.length) {
         var2 = var0.length;
      }

      if (var2 <= var1) {
         return new float[0];
      }

      float[] var3 = new float[var2 - var1];

      for (int var4 = 0; var4 < var3.length; var4++) {
         var3[var4] = var0[var1 + var4];
      }

      return var3;
   }

   private static float[] reverseSlice(float[] var0, int var1, int var2) {
      float[] var3 = slice(var0, var1, var2);

      for (int var4 = 0; var4 < var3.length / 2; var4++) {
         float var5 = var3[var4];
         var3[var4] = var3[var3.length - 1 - var4];
         var3[var3.length - 1 - var4] = var5;
      }

      return var3;
   }

   private static float[] copyFloats(float[] var0) {
      if (var0 == null) {
         return new float[0];
      }

      float[] var1 = new float[var0.length];

      for (int var2 = 0; var2 < var0.length; var2++) {
         var1[var2] = var0[var2];
      }

      return var1;
   }

   private static CarPlaySideStreets.SplitAngles splitAnglesNative(int[] var0, int var1) {
      if (var0 != null && var0.length != 0) {
         CarPlaySideStreets.IntList var2 = new CarPlaySideStreets.IntList(var0.length);
         CarPlaySideStreets.IntList var3 = new CarPlaySideStreets.IntList(var0.length);

         for (int var4 = 0; var4 < var0.length; var4++) {
            int var5 = var0[var4];
            if (var5 > var1) {
               var3.add(var5);
            } else if (var5 < var1) {
               var2.add(var5);
            }
         }

         return new CarPlaySideStreets.SplitAngles(var2.toArray(), var3.toArray());
      } else {
         return new CarPlaySideStreets.SplitAngles(new int[0], new int[0]);
      }
   }

   private static int angleToDirectionCode(float var0) {
      int var1 = (int)(var0 / 22.5F);
      if (var0 < 0.0F && var1 * 22.5F != var0) {
         var1--;
      }

      if (var1 < -8) {
         var1 = -8;
      }

      if (var1 > 8) {
         var1 = 8;
      }

      return var1 <= 0 ? -var1 * 16 : (16 - var1) * 16;
   }

   private static boolean computesSidestreets(int var0, int var1) {
      switch (var0) {
         case 1:
         case 2:
         case 3:
         case 13:
         case 14:
         case 20:
         case 21:
         case 47:
         case 48:
         case 49:
         case 50:
            return var1 == 0;
         case 4:
         case 5:
         case 6:
         case 7:
         case 8:
         case 9:
         case 10:
         case 12:
         case 15:
         case 17:
         case 18:
         case 22:
         case 23:
         case 24:
         case 25:
         case 26:
         case 27:
         case 28:
         case 29:
         case 30:
         case 31:
         case 32:
         case 33:
         case 34:
         case 35:
         case 36:
         case 37:
         case 38:
         case 39:
         case 40:
         case 41:
         case 42:
         case 43:
         case 44:
         case 45:
         case 46:
         default:
            return var0 >= 28 && var0 <= 46 && var1 == 1;
         case 11:
         case 16:
         case 19:
         case 51:
            return true;
      }
   }

   private static byte[] toByteArray(int[] var0) {
      if (var0 != null && var0.length != 0) {
         byte[] var1 = new byte[var0.length];

         for (int var2 = 0; var2 < var0.length; var2++) {
            var1[var2] = (byte)(var0[var2] & 0xFF);
         }

         return var1;
      } else {
         return new byte[0];
      }
   }

   private static final class Entry {
      final float minDiff;
      final float[] pairs;

      Entry(float var1, float[] var2) {
         this.minDiff = var1;
         this.pairs = var2 != null ? var2 : new float[0];
      }
   }

   private static final class EntryList {
      private CarPlaySideStreets.Entry[] a;
      private int n;

      EntryList(int var1) {
         if (var1 < 0) {
            var1 = 0;
         }

         this.a = new CarPlaySideStreets.Entry[var1];
         this.n = 0;
      }

      void add(CarPlaySideStreets.Entry var1) {
         if (var1 != null) {
            if (this.n >= this.a.length) {
               int var2 = this.a.length == 0 ? 8 : this.a.length * 2;
               CarPlaySideStreets.Entry[] var3 = new CarPlaySideStreets.Entry[var2];

               for (int var4 = 0; var4 < this.n; var4++) {
                  var3[var4] = this.a[var4];
               }

               this.a = var3;
            }

            this.a[this.n++] = var1;
         }
      }

      int size() {
         return this.n;
      }

      CarPlaySideStreets.Entry get(int var1) {
         return this.a[var1];
      }

      void set(int var1, CarPlaySideStreets.Entry var2) {
         this.a[var1] = var2;
      }
   }

   private static final class IntList {
      private int[] a;
      private int n;

      IntList(int var1) {
         if (var1 < 0) {
            var1 = 0;
         }

         this.a = new int[var1];
         this.n = 0;
      }

      void add(int var1) {
         if (this.n >= this.a.length) {
            int var2 = this.a.length == 0 ? 4 : this.a.length * 2;
            int[] var3 = new int[var2];

            for (int var4 = 0; var4 < this.n; var4++) {
               var3[var4] = this.a[var4];
            }

            this.a = var3;
         }

         this.a[this.n++] = var1;
      }

      boolean contains(int var1) {
         for (int var2 = 0; var2 < this.n; var2++) {
            if (this.a[var2] == var1) {
               return true;
            }
         }

         return false;
      }

      int[] toArray() {
         if (this.n == 0) {
            return new int[0];
         }

         int[] var1 = new int[this.n];

         for (int var2 = 0; var2 < this.n; var2++) {
            var1[var2] = this.a[var2];
         }

         return var1;
      }
   }

   private static final class SplitAngles {
      final int[] below;
      final int[] above;

      SplitAngles(int[] var1, int[] var2) {
         this.below = var1 != null ? var1 : new int[0];
         this.above = var2 != null ? var2 : new int[0];
      }
   }
}
