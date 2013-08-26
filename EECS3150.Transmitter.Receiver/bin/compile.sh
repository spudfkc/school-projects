#!/bin/bash
src_receiver=../src/receiver/eecs3150.01.receiver.c
src_transmitter=../src/transmitter/eecs3150.01.transmitter.c

output_dir=.

GCC=`which gcc`

if [ -z $GCC ]; then
  echo "gcc not found!"
  exit 1
fi

script_dir=`dirname $0`

if [ $script_dir -eq . ]; then
  script_dir=`pwd`
fi

src_receiver=$script_dir/$src_receiver
src_transmitter=$script_dir/$src_transmitter

echo "Compiling: $src_receiver"
gcc $src_receiver -o $output_dir/receiver

echo "Compiling: $src_transmitter"
gcc $src_transmitter -o $output_dir/transmitter

echo "Done."
