#!/bin/sh

EXEC=./JazInt
MAKE=make
JAZ_DIR=sampleJaz
SRC_DIR=src

runJaz() {
  for FILE in $(find $JAZ_DIR -name "*.jaz")
  do
    echo "...Interpreting: $FILE"
    echo "..."
    $EXEC $FILE
    echo "...done..."
  done
  echo "...All files interpreted..."
}

cleanObjs() {
  echo "...Cleaning up..."
  for FILE in $($SRC_DIR -name "*.o")
  do
    rm -v $FILE
  done
}


if [ -e $EXEC ]
then
  echo "...Starting interpreter..."
  runJaz
elif [ -e $MAKE ]
then
  cleanObjs
  echo "...making executable..."
  $MAKE 
fi
