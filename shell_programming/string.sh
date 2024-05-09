#!/bin/bash

str1="hello_coder"
str2="mehuliyo"

if [ $str1 = $str2 ]
then 
echo "both string are equal"
else 
echo "both string are not equal"
fi

#string are empty ??

if [ -n $str1 ]
then 
echo "string is not empty"
else 
echo "string isa empty"
fi

#length 

length=${#str1}
echo "length of $str1 is $length"

#sub string
substr="${str1:0:5}"

echo "sub string : $substr"
echo " now length of ${#substr}"



#split string

echo "Enter any string separated by space :"
read str

echo ""
IFS=' '
read -ra  ADDR<<<"$str"

for i in "${ADDR[@]}"
do
echo "$i"
done


