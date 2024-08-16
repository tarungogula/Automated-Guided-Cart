/* --- Generated the 6/5/2024 at 9:9 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 17:58:4 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H

#include "line_follower_types.h"
typedef struct Line_follower__main_mem {
  int v_24;
  int v_22;
  int v_20;
  int v_18;
  int v_49;
  int v_47;
  int v_45;
  int v_43;
  Line_follower__st ck;
  int pnr;
} Line_follower__main_mem;

typedef struct Line_follower__main_out {
  int v_l;
  int v_r;
  int dir;
} Line_follower__main_out;

void Line_follower__main_reset(Line_follower__main_mem* self);

void Line_follower__main_step(int sen0, int sen1, int sen2, int sen3,
                              int sen4, int switch_line, int threshold,
                              Line_follower__main_out* _out,
                              Line_follower__main_mem* self);

#endif // LINE_FOLLOWER_H
