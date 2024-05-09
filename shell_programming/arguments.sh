#!/bin/sh

hello () {

echo "number of aruments is $1"
echo "name of script is $2"
echo "first arguments is $3"
echo "second arguments is $4"

return "$3"
}
var="$#"
hello "$var" "$0" "$1" "$2"
#var1="$hello"
echo "$?"
