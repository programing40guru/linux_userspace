#!/bin/bash


echo "today is" `date`

echo -e "\nwhat is your name"
read name

echo -e "\nadd new row.. $name!"

#writing to file..
echo -e "$name add same text to  input.txt file .">>input.txt


echo ""

echo "now read file data "
while read line 
do 
echo $line
done <input.txt
