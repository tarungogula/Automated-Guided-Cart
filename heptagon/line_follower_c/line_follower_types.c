/* --- Generated the 6/5/2024 at 9:9 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 17:58:4 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower_types.h"

Line_follower__st Line_follower__st_of_string(char* s) {
  if ((strcmp(s, "St_W_PIDFollower")==0)) {
    return Line_follower__St_W_PIDFollower;
  };
  if ((strcmp(s, "St_B_PIDFollower")==0)) {
    return Line_follower__St_B_PIDFollower;
  };
}

char* string_of_Line_follower__st(Line_follower__st x, char* buf) {
  switch (x) {
    case Line_follower__St_W_PIDFollower:
      strcpy(buf, "St_W_PIDFollower");
      break;
    case Line_follower__St_B_PIDFollower:
      strcpy(buf, "St_B_PIDFollower");
      break;
    default:
      break;
  };
  return buf;
}

