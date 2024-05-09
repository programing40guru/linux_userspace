#!/bin/bash

data=("Mehul" "hiren" "Tarang" "pratham")
echo "${data[@]}"
echo "${data[*]}"

echo "item index 0 is : ${data[0]}"
echo "item index 1 is : ${data[1]}"
echo "item index 2 is : ${data[2]}"
echo "item index 3 is : ${data[3]}"

data[4]="ankit bhai"
echo "new data add wit new array : ${data[@]}"

echo "now replace ankit bhai to kalarav bhai "
data[4]="kalarav bhai"

echo "so new data : ${data[@]}"

data[5]="dadu"
echo "new data : ${data[@]}"

echo "unset data "
unset data[5]

echo "new data is : ${data[@]}"

