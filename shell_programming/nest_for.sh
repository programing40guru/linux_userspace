#!/bin/sh

for i in `seq 1 5`
do 

for j in `seq 1 5`
do

echo   $i*$j
echo `$i+1`
done
echo "\n"
done
