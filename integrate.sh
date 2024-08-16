#!/usr/bin/env bash
cd "heptagon/"
(./simulate.sh -s main -p $1.ept -k 1)   # $1 == line_follower (give it while running bash file) Run " ./integrate.sh line_follower"

cd ".."

dest_src=$pwd."/supervisor" # path in supervisor directory  (destination)
src=$pwd."/heptagon/$1_c"   # path in heptagon directory (source)
cp "$src/$1_types.c" "$dest_src/$1_types.cpp"
cp "$src/$1_types.h" "$dest_src/$1_types.h"
cp "$src/$1.c" "$dest_src/$1.cpp"
cp "$src/$1.h" "$dest_src/$1.h"
sed -i 's/int/long/g' "$dest_src/$1.cpp"
sed -i 's/int/long/g' "$dest_src/$1.h"
sed -i 's/int/long/g' "$dest_src/$1_types.h"
sed --in-place '/pervasives.h/d' "$dest_src/line_follower_types.h"

