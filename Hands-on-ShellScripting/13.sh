#!/bin/bash

echo "Enter a Number"
read num

i=1

echo -e "\n"

while [ $i -le 10 ]
do
          echo "$num x $i = $(( num * i ))"
          i=$(( i + 1 ))
done
