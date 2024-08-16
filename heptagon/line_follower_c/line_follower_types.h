/* --- Generated the 6/5/2024 at 9:9 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 17:58:4 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_TYPES_H
#define LINE_FOLLOWER_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
typedef enum {
  Line_follower__St_W_PIDFollower,
  Line_follower__St_B_PIDFollower
} Line_follower__st;

Line_follower__st Line_follower__st_of_string(char* s);

char* string_of_Line_follower__st(Line_follower__st x, char* buf);

static const int Line_follower__kp = 1;

static const int Line_follower__ki = 100;

static const int Line_follower__kd = 10000;

#endif // LINE_FOLLOWER_TYPES_H
