#!/bin/sh
echo "enter x value "
read y

x=18
if [ $x -le $y ]
then
echo "now you yang"

else 
echo "you are child"
fi

echo "enter ractangale length "
read len

echo "enter ractangle width "
read width

area=$((len * width))
	echo "the are of the rectangle is : $area"

time=$(date +%H)

	if [ $time -lt 12 ];then
	message="Good Morning Bro"
	elif [ $time -lt 18 ];then
	message="Good Afternoon Bro"
	else 
	echo "Good Evening Bro"
	fi
	echo "$message"
