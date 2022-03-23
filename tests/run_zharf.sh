#!/bin/bash

###
#	Usage: ./run_zharf.sh <program to fuzz> <input dir> <output dir> <init input file>
#	License: MIT
#
#	By: Luciano Remes
###

zcc -o program.elf $1 && \
zharf -i $2 -o $3 -f $4 program.elf $4 && \
rm -f program.elf

