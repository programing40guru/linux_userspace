#!/bin/bash

echo -e "\nenter the path"
read path

if [ -f $path ]
then 
echo " file $path is exits "
fi

if [ -d $path ]
then 
echo "$path is a directory"
else 
echo "$path is NOT directory"
fi
