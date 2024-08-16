/* --- Generated the 6/5/2024 at 9:9 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 17:58:4 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H

#include "line_follower_types.h"
typedef struct Line_follower__main_mem {
  long v_24;
  long v_22;
  long v_20;
  long v_18;
  long v_49;
  long v_47;
  long v_45;
  long v_43;
  Line_follower__st ck;
  long pnr;
} Line_follower__main_mem;

typedef struct Line_follower__main_out {
  long v_l;
  long v_r;
  long dir;
} Line_follower__main_out;

void Line_follower__main_reset(Line_follower__main_mem* self);

void Line_follower__main_step(long sen0, long sen1, long sen2, long sen3,
                              long sen4, long switch_line, long threshold,
                              Line_follower__main_out* _out,
                              Line_follower__main_mem* self);

#endif // LINE_FOLLOWER_H
