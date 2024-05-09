#!/bin/sh

hello () {
echo "hello i am $1 $2"
return 10
}

hello function guru

#ret=$?
echo "return value is $?"

#nested function

pro () {
echo "i am pro"
pro1
}

pro1 () {
echo "then i am pro1 child "
}

pro
