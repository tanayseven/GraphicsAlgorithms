#!/bin/bash

len=${#1}-2 #finds the length of the fileto be compiled subtracts 1

#echos the command format to be printed
echo "Compiling using command: "
echo "gcc -o ${1:0:len}.o \`pkg-config --cflags --libs gtk+-3.0\` DrawingWindow.c $1 "

#actually runs the command, if errors will be echoed here
gcc -o ${1:0:len}.o `pkg-config --cflags --libs gtk+-3.0` DrawingWindow.c $1 
