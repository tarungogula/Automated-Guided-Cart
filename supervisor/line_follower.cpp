/* --- Generated the 6/5/2024 at 9:9 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 17:58:4 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower.h"

void Line_follower__main_reset(Line_follower__main_mem* self) {
  self->v_47 = true;
  self->v_43 = true;
  self->v_22 = true;
  self->v_18 = true;
  self->pnr = false;
  self->ck = Line_follower__St_W_PIDFollower;
}

void Line_follower__main_step(long sen0, long sen1, long sen2, long sen3,
                              long sen4, long switch_line, long threshold,
                              Line_follower__main_out* _out,
                              Line_follower__main_mem* self) {
  
  long v_34;
  long v_33;
  long v_32;
  long v_31;
  long v_30;
  long v_29;
  long v_28;
  long v_27;
  long v_26;
  long v_25;
  long v_23;
  long v_21;
  long v_19;
  long v_17;
  long v_16;
  long v_15;
  long v_14;
  long v_13;
  long error_1;
  long error_longegral_1;
  long error_derivative_1;
  long temp_value_1;
  long pid_value_1;
  long v_70;
  long v_69;
  long v_68;
  long v_67;
  long v_66;
  long v_65;
  long v_64;
  long v_63;
  long v_62;
  long v_61;
  long v_60;
  long v_59;
  long v_58;
  long v_57;
  long v_56;
  long v_55;
  long v_54;
  long v_53;
  long v_52;
  long v_51;
  long v_50;
  long v_48;
  long v_46;
  long v_44;
  long v_42;
  long v_41;
  long v_40;
  long v_39;
  long v_38;
  long v_37;
  long v_36;
  long v_35;
  long error;
  long error_longegral;
  long error_derivative;
  long temp_value;
  long pid_value;
  long nr_St_B_PIDFollower;
  Line_follower__st ns_St_B_PIDFollower;
  long dir_St_B_PIDFollower;
  long v_r_St_B_PIDFollower;
  long v_l_St_B_PIDFollower;
  long nr_St_W_PIDFollower;
  Line_follower__st ns_St_W_PIDFollower;
  long dir_St_W_PIDFollower;
  long v_r_St_W_PIDFollower;
  long v_l_St_W_PIDFollower;
  long v_12;
  long v_11;
  long v_10;
  long v_9;
  long v_8;
  long v_7;
  long v_6;
  long v_5;
  long v_4;
  long v_3;
  long v_2;
  long v_1;
  long v;
  Line_follower__st ns;
  long r;
  long nr;
  long a0;
  long a1;
  long a2;
  long a3;
  long a4;
  long sum_all;
  long b0;
  long b1;
  long b2;
  long b3;
  long b4;
  r = self->pnr;
  v_12 = (sen4<800);
  if (v_12) {
    b4 = true;
  } else {
    b4 = false;
  };
  v_11 = (sen3<800);
  if (v_11) {
    b3 = true;
  } else {
    b3 = false;
  };
  v_10 = (sen2<800);
  if (v_10) {
    b2 = true;
  } else {
    b2 = false;
  };
  v_9 = (sen1<800);
  if (v_9) {
    b1 = true;
  } else {
    b1 = false;
  };
  v_8 = (sen0<800);
  if (v_8) {
    b0 = true;
  } else {
    b0 = false;
  };
  v_5 = (sen0+sen1);
  v_6 = (v_5+sen2);
  v_7 = (v_6+sen3);
  sum_all = (v_7+sen4);
  v_4 = (sen4>950);
  if (v_4) {
    a4 = true;
  } else {
    a4 = false;
  };
  v_3 = (sen3>900);
  if (v_3) {
    a3 = true;
  } else {
    a3 = false;
  };
  v_2 = (sen2>900);
  if (v_2) {
    a2 = true;
  } else {
    a2 = false;
  };
  v_1 = (sen1>900);
  if (v_1) {
    a1 = true;
  } else {
    a1 = false;
  };
  v = (sen0>850);
  if (v) {
    a0 = true;
  } else {
    a0 = false;
  };
  switch (self->ck) {
    case Line_follower__St_W_PIDFollower:
      v_68 = (sen4>900);
      if (v_68) {
        v_69 = 3;
      } else {
        v_69 = 1;
      };
      v_67 = (sen0>900);
      if (v_67) {
        v_70 = 2;
      } else {
        v_70 = v_69;
      };
      v_61 = (sen0+sen1);
      v_62 = (v_61+sen2);
      v_63 = (v_62+sen3);
      v_64 = (v_63+sen4);
      v_65 = (v_64>4000);
      v_66 = (v_65&&threshold);
      if (v_66) {
        dir_St_W_PIDFollower = 4;
      } else {
        dir_St_W_PIDFollower = v_70;
      };
      if (self->v_47) {
        v_48 = true;
      } else {
        v_48 = r;
      };
      if (v_48) {
        v_50 = 0;
      } else {
        v_50 = self->v_49;
      };
      if (self->v_43) {
        v_44 = true;
      } else {
        v_44 = r;
      };
      v_42 = (sen1/10);
      v_40 = (sen3/10);
      v_38 = (sen0-sen4);
      v_39 = (v_38/10);
      v_41 = (v_39+v_40);
      error = (v_41-v_42);
      v_51 = (error/2);
      error_derivative = (error-v_50);
      v_46 = (self->v_45+error);
      if (v_44) {
        error_longegral = 0;
      } else {
        error_longegral = v_46;
      };
      v_52 = (error_longegral/5000);
      v_53 = (v_51+v_52);
      temp_value = (v_53+error_derivative);
      v_55 = (temp_value>25);
      if (v_55) {
        v_56 = 25;
      } else {
        v_56 = temp_value;
      };
      v_54 = (temp_value<-25);
      if (v_54) {
        pid_value = -25;
      } else {
        pid_value = v_56;
      };
      v_60 = (45+pid_value);
      v_59 = (pid_value==0);
      if (v_59) {
        v_r_St_W_PIDFollower = 45;
      } else {
        v_r_St_W_PIDFollower = v_60;
      };
      v_58 = (45-pid_value);
      v_57 = (pid_value==0);
      if (v_57) {
        v_l_St_W_PIDFollower = 45;
      } else {
        v_l_St_W_PIDFollower = v_58;
      };
      v_35 = (b1||b2);
      v_36 = (v_35||b3);
      v_37 = (v_36&&switch_line);
      if (v_37) {
        nr_St_W_PIDFollower = true;
        ns_St_W_PIDFollower = Line_follower__St_B_PIDFollower;
      } else {
        nr_St_W_PIDFollower = false;
        ns_St_W_PIDFollower = Line_follower__St_W_PIDFollower;
      };
      _out->v_l = v_l_St_W_PIDFollower;
      _out->v_r = v_r_St_W_PIDFollower;
      _out->dir = dir_St_W_PIDFollower;
      ns = ns_St_W_PIDFollower;
      nr = nr_St_W_PIDFollower;
      self->v_49 = error;
      self->v_47 = false;
      self->v_45 = error_longegral;
      self->v_43 = false;
      break;
    case Line_follower__St_B_PIDFollower:
      if (self->v_22) {
        v_23 = true;
      } else {
        v_23 = r;
      };
      if (v_23) {
        v_25 = 0;
      } else {
        v_25 = self->v_24;
      };
      if (self->v_18) {
        v_19 = true;
      } else {
        v_19 = r;
      };
      v_17 = (sen1/10);
      v_15 = (sen3/10);
      v_13 = (sen0-sen4);
      v_14 = (v_13/10);
      v_16 = (v_14+v_15);
      error_1 = (v_16-v_17);
      error_derivative_1 = (error_1-v_25);
      v_21 = (self->v_20+error_1);
      if (v_19) {
        error_longegral_1 = 0;
      } else {
        error_longegral_1 = v_21;
      };
      v_26 = (error_longegral_1/5000);
      v_27 = (error_1+v_26);
      temp_value_1 = (v_27+error_derivative_1);
      v_29 = (temp_value_1>25);
      if (v_29) {
        v_30 = 25;
      } else {
        v_30 = temp_value_1;
      };
      v_28 = (temp_value_1<-25);
      if (v_28) {
        pid_value_1 = -25;
      } else {
        pid_value_1 = v_30;
      };
      v_34 = (40+pid_value_1);
      v_33 = (pid_value_1==0);
      if (v_33) {
        v_l_St_B_PIDFollower = 40;
      } else {
        v_l_St_B_PIDFollower = v_34;
      };
      v_32 = (40-pid_value_1);
      v_31 = (pid_value_1==0);
      if (v_31) {
        v_r_St_B_PIDFollower = 40;
      } else {
        v_r_St_B_PIDFollower = v_32;
      };
      dir_St_B_PIDFollower = 5;
      nr_St_B_PIDFollower = false;
      ns_St_B_PIDFollower = Line_follower__St_B_PIDFollower;
      _out->v_l = v_l_St_B_PIDFollower;
      _out->v_r = v_r_St_B_PIDFollower;
      _out->dir = dir_St_B_PIDFollower;
      ns = ns_St_B_PIDFollower;
      nr = nr_St_B_PIDFollower;
      self->v_24 = error_1;
      self->v_22 = false;
      self->v_20 = error_longegral_1;
      self->v_18 = false;
      break;
    default:
      break;
  };
  self->pnr = nr;
  self->ck = ns;;
}

