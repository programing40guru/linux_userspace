#!/bin/sh
a=0
while [ $a -lt 10 ]
do 
echo "oyy hiren $a"
a=`expr $a + 1`

done


echo "enter Password"
read pass

while [ $pass != "1234" ]
do
echo "SORRY try again"
read pass

done
echo "WoW Correct Pass"
