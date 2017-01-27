#!/bin/bash

test -d ../build || mkdir -pv ../build
pushd ../build
CC=gcc
SDL_64=`sdl2-config --cflags --libs`
SDL_32="-I/usr/include/SDL2 -D_REENTRANT -L/usr/lib32 -lSDL2"
DEBUG_OPTS="-ggdb"
EXTRA_OPTS="-std=c11"
WARNING_OPTS="-Wall -Wno-write-strings -Wno-unused-variable -Wno-unused-function -fno-exceptions"
$CC $DEBUG_OPTS $WARNING_OPTS $EXTRA_OPTS -D_DEFAULT_SOURCE -o joytest.amd64.sdl ../src/joypad_test.c $SDL_64
$CC -m32 $DEBUG_OPTS $WARNING_OPTS $EXTRA_OPTS -D_DEFAULT_SOURCE -o joytest.i686.sdl ../src/joypad_test.c $SDL_32
