#!/bin/sh

echo "enter ax value "
read x

if [ $x -ne 10 ]
then
echo "pass "
exit 1
else 
echo "failed"
exit 0
fi
