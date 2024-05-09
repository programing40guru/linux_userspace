#!/bin/bash

echo "enter string 1:"
read str1

echo "enter string 2:"
read str2

str3="$str1$str2"
echo $str3

echo "${str1}_${str2}"
read -p "Enter First Name: " name  
read -p "Enter State: " state  
read -p "Enter Age: " age  

combine="$name,$state,$age"
echo "Name,State,Age : $combine"
