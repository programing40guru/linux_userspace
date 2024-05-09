#!/bin/sh
a=0
until [ $a -gt 10 ]
do

echo $a
sleep 1
a=`expr $a + 1`

done  
