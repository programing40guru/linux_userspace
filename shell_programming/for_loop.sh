#!/bin/sh

for a in 1 2 3 4 5 6 7 8 9 10
do

if [ $a -eq 5 ]
then

echo "_"
continue 

fi

if [ $a -eq 10 ]
then 
break
fi

echo "done..$a"
done
