// Artifact label: 2026-10-24. Decompiled universal TEST variant prepared 2026-11-04.
package de.audi.app.terminalmode.smartphone.carplay;

public class CarPlayManeuverMapper {
   public static final int NO_SYMBOL = 0;
   public static final int NO_INFO = 1;
   public static final int DIRECTION_TO_DESTINATION = 2;
   public static final int ARRIVED = 3;
   public static final int NEAR_DESTINATION = 4;
   public static final int ARRIVED_DESTINATION_OFFMAP = 5;
   public static final int OFF_ROAD = 6;
   public static final int OFF_MAP = 7;
   public static final int NO_ROUTE = 8;
   public static final int CALC_ROUTE = 9;
   public static final int RECALC_ROUTE = 10;
   public static final int FOLLOW_STREET = 11;
   public static final int CHANGE_LANE = 12;
   public static final int TURN = 13;
   public static final int TURN_ON_MAINROAD = 14;
   public static final int EXIT_RIGHT = 15;
   public static final int EXIT_LEFT = 16;
   public static final int SERVICE_ROAD_RIGHT = 17;
   public static final int SERVICE_ROAD_LEFT = 18;
   public static final int FORK_2 = 19;
   public static final int FORK_3 = 20;
   public static final int ROUNDABOUT_TRS_RIGHT = 21;
   public static final int ROUNDABOUT_TRS_LEFT = 22;
   public static final int SQUARE_TRS_RIGHT = 23;
   public static final int SQUARE_TRS_LEFT = 24;
   public static final int UTURN = 25;
   public static final int EXIT_ROUNDABOUT_TRS_RIGHT = 26;
   public static final int EXIT_ROUNDABOUT_TRS_LEFT = 27;
   public static final int PREPARE_TURN = 28;
   public static final int PREPARE_ROUNDABOUT = 29;
   public static final int PREPARE_SQUARE = 30;
   public static final int PREPARE_U_TURN = 31;
   public static final int MICHIGAN_TURN = 34;
   public static final int DOUBLE_TURN = 35;
   public static final int DIRECTION_TO_WAYPOINT = 38;
   public static final int DIR_STRAIGHT = 0;
   public static final int DIR_SLIGHT_LEFT = 32;
   public static final int DIR_LEFT = 64;
   public static final int DIR_SHARP_LEFT = 96;
   public static final int DIR_UTURN = 128;
   public static final int DIR_SHARP_RIGHT = 160;
   public static final int DIR_RIGHT = 192;
   public static final int DIR_SLIGHT_RIGHT = 224;
   public static final int JUNCTION_SINGLE_INTERSECTION = 0;
   public static final int JUNCTION_ROUNDABOUT = 1;
   public static final int DRIVING_SIDE_RIGHT = 0;
   public static final int DRIVING_SIDE_LEFT = 1;
   public static final int MT_NOT_SET = -1;
   public static final int MT_NO_TURN = 0;
   public static final int MT_LEFT_TURN = 1;
   public static final int MT_RIGHT_TURN = 2;
   public static final int MT_STRAIGHT_AHEAD = 3;
   public static final int MT_U_TURN = 4;
   public static final int MT_FOLLOW_ROAD = 5;
   public static final int MT_ENTER_ROUNDABOUT = 6;
   public static final int MT_EXIT_ROUNDABOUT = 7;
   public static final int MT_OFF_RAMP = 8;
   public static final int MT_ON_RAMP = 9;
   public static final int MT_ARRIVE_END_OF_NAVIGATION = 10;
   public static final int MT_START_ROUTE = 11;
   public static final int MT_ARRIVE_AT_DESTINATION = 12;
   public static final int MT_KEEP_LEFT = 13;
   public static final int MT_KEEP_RIGHT = 14;
   public static final int MT_ENTER_FERRY = 15;
   public static final int MT_EXIT_FERRY = 16;
   public static final int MT_CHANGE_FERRY = 17;
   public static final int MT_START_ROUTE_WITH_U_TURN = 18;
   public static final int MT_U_TURN_AT_ROUNDABOUT = 19;
   public static final int MT_LEFT_TURN_AT_END = 20;
   public static final int MT_RIGHT_TURN_AT_END = 21;
   public static final int MT_HIGHWAY_OFF_RAMP_LEFT = 22;
   public static final int MT_HIGHWAY_OFF_RAMP_RIGHT = 23;
   public static final int MT_ARRIVE_DESTINATION_LEFT = 24;
   public static final int MT_ARRIVE_DESTINATION_RIGHT = 25;
   public static final int MT_U_TURN_WHEN_POSSIBLE = 26;
   public static final int MT_ARRIVE_END_OF_DIRECTIONS = 27;
   public static final int MT_ROUNDABOUT_EXIT_1 = 28;
   public static final int MT_ROUNDABOUT_EXIT_2 = 29;
   public static final int MT_ROUNDABOUT_EXIT_3 = 30;
   public static final int MT_ROUNDABOUT_EXIT_4 = 31;
   public static final int MT_ROUNDABOUT_EXIT_5 = 32;
   public static final int MT_ROUNDABOUT_EXIT_6 = 33;
   public static final int MT_ROUNDABOUT_EXIT_7 = 34;
   public static final int MT_ROUNDABOUT_EXIT_8 = 35;
   public static final int MT_ROUNDABOUT_EXIT_9 = 36;
   public static final int MT_ROUNDABOUT_EXIT_10 = 37;
   public static final int MT_ROUNDABOUT_EXIT_11 = 38;
   public static final int MT_ROUNDABOUT_EXIT_12 = 39;
   public static final int MT_ROUNDABOUT_EXIT_13 = 40;
   public static final int MT_ROUNDABOUT_EXIT_14 = 41;
   public static final int MT_ROUNDABOUT_EXIT_15 = 42;
   public static final int MT_ROUNDABOUT_EXIT_16 = 43;
   public static final int MT_ROUNDABOUT_EXIT_17 = 44;
   public static final int MT_ROUNDABOUT_EXIT_18 = 45;
   public static final int MT_ROUNDABOUT_EXIT_19 = 46;
   public static final int MT_SHARP_LEFT_TURN = 47;
   public static final int MT_SHARP_RIGHT_TURN = 48;
   public static final int MT_SLIGHT_LEFT_TURN = 49;
   public static final int MT_SLIGHT_RIGHT_TURN = 50;
   public static final int MT_CHANGE_HIGHWAY = 51;
   public static final int MT_CHANGE_HIGHWAY_LEFT = 52;
   public static final int MT_CHANGE_HIGHWAY_RIGHT = 53;

   public static int[] map(int var0, int var1, int var2, int var3) {
      if (var0 == -1) {
         byte var20 = 0;
         byte var33 = 0;
         return new int[]{var20, var33};
      }

      if (var0 == 0 || var0 == 5) {
         byte var19 = 11;
         byte var32 = 0;
         return new int[]{var19, var32};
      }

      if (var0 == 10 || var0 == 12 || var0 == 27) {
         byte var18 = 3;
         byte var31 = 0;
         return new int[]{var18, var31};
      }

      if (var0 == 52) {
         byte var17 = 12;
         byte var30 = 64;
         return new int[]{var17, var30};
      }

      if (var0 == 53) {
         byte var16 = 12;
         short var29 = 192;
         return new int[]{var16, var29};
      }

      if (var0 == 15 || var0 == 17) {
         byte var15 = 11;
         byte var28 = 0;
         return new int[]{var15, var28};
      }

      if (var0 == 11 || var0 == 16 || var0 == 51) {
         byte var14 = 13;
         int var27 = directionFromTurnAngle(var1);
         return new int[]{var14, var27};
      }

      if (var0 == 19) {
         int var13 = var3 == 1 ? 22 : 21;
         short var26 = 128;
         return new int[]{var13, var26};
      }

      if (var0 == 6) {
         byte var12 = 13;
         int var24 = var3 == 1 ? 64 : 192;
         var24 = applyDsiNavBapDirectionOverride(var0, var24);
         return new int[]{var12, var24};
      }

      if (var2 == 0) {
         int var4;
         byte var5;
         switch (var0) {
            case 1:
               var5 = 13;
               var4 = 64;
               break;
            case 2:
               var5 = 13;
               var4 = 192;
               break;
            case 3:
               var5 = 13;
               var4 = 0;
               break;
            case 4:
            case 18:
            case 26:
               var5 = 25;
               if (var3 == 1) {
                  var4 = 192;
               } else {
                  var4 = 64;
               }
               break;
            case 5:
            case 6:
            case 7:
            case 10:
            case 11:
            case 12:
            case 15:
            case 16:
            case 17:
            case 19:
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
               var5 = 1;
               var4 = 0;
               break;
            case 8:
               if (var3 == 1) {
                  var5 = 16;
                  var4 = 32;
               } else {
                  var5 = 15;
                  var4 = 224;
               }
               break;
            case 9:
               var5 = 13;
               if (var3 == 1 && (var1 & 4294967295L) > 179L) {
                  var4 = 32;
               } else {
                  var4 = 224;
               }
               break;
            case 13:
            case 49:
               var5 = 13;
               var4 = 32;
               break;
            case 14:
            case 50:
               var5 = 13;
               var4 = 224;
               break;
            case 20:
               var5 = 13;
               var4 = dirFromEndOfRoadAngleLeft(var1);
               break;
            case 21:
               var5 = 13;
               var4 = dirFromEndOfRoadAngleRight(var1);
               break;
            case 22:
               var5 = 16;
               var4 = 32;
               break;
            case 23:
               var5 = 15;
               var4 = 224;
               break;
            case 24:
            case 25:
               var5 = 3;
               var4 = var0 == 24 ? 64 : 192;
               break;
            case 47:
               var5 = 13;
               var4 = 96;
               break;
            case 48:
               var5 = 13;
               var4 = 160;
         }

         var4 = applyDsiNavBapDirectionOverride(var0, var4);
         return new int[]{var5, var4};
      } else if (var2 != 1) {
         byte var11 = 1;
         byte var23 = 0;
         return new int[]{var11, var23};
      } else if (var0 == 7) {
         int var10 = var3 == 1 ? 27 : 26;
         int var22 = var3 == 1 ? 64 : 192;
         return new int[]{var10, var22};
      } else if (var0 >= 28 && var0 <= 46) {
         int var9 = var3 == 1 ? 22 : 21;
         int var21 = directionFromAngle16(var1);
         return new int[]{var9, var21};
      } else {
         byte var6 = 1;
         byte var7 = 0;
         return new int[]{var6, var7};
      }
   }

   private static int applyDsiNavBapDirectionOverride(int var0, int var1) {
      if (var0 != 6 && var0 != 7 && var0 != 19 && var0 != 4 && var0 != 18 && var0 != 26 && (var0 < 28 || var0 > 46)) {
         if (var0 == 8 || var0 == 9 || var0 == 22 || var0 == 23 || var0 == 13 || var0 == 14 || var0 == 49 || var0 == 50 || var0 == 47 || var0 == 48) {
            return var1;
         } else if (var1 == 32 || var1 == 64 || var1 == 96) {
            return 64;
         } else if (var1 == 224 || var1 == 192 || var1 == 160) {
            return 192;
         } else {
            return var1 == 128 ? 128 : 0;
         }
      } else {
         return var1;
      }
   }

   public static int directionFromAngle16(int var0) {
      int var2 = var0;
      if (var2 > 180) {
         var2 = 180;
      }

      if (var2 < -180) {
         var2 = -180;
      }

      int var1;
      if ((var1 = (int)Math.floor((var2 + 180) / 22.5 + 0.5)) < 0) {
         var1 = 0;
      }

      if (var1 > 16) {
         var1 = 16;
      }

      int[] var3 = new int[]{128, 112, 96, 80, 64, 48, 32, 16, 0, 240, 224, 208, 192, 176, 160, 144, 128};
      return var3[var1];
   }

   private static int directionFromTurnAngle(int var0) {
      if (var0 == 1000 || var0 == -1000) {
         return 0;
      } else if (var0 == 0) {
         return 0;
      } else {
         return var0 < 0 ? 64 : 192;
      }
   }

   private static int dirFromEndOfRoadAngleLeft(int var0) {
      if (var0 != 0 && var0 < 0 && var0 >= -180) {
         if (var0 >= -67) {
            return 32;
         }

         if (var0 < -112) {
            return 96;
         }
      }

      return 64;
   }

   private static int dirFromEndOfRoadAngleRight(int var0) {
      if (var0 != 0 && var0 > 0 && var0 <= 180) {
         if (var0 <= 67) {
            return 224;
         }

         if (var0 > 112) {
            return 160;
         }
      }

      return 192;
   }

   public static boolean isHighwayManeuver(int var0) {
      return var0 == 8 || var0 == 9 || var0 == 22 || var0 == 23 || var0 == 51 || var0 == 52 || var0 == 53;
   }

   public static boolean isValidType(int var0) {
      return var0 >= 0 && var0 <= 53;
   }
}
