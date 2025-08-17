#!/bin/bash

a=`w $1 | awk '{print $4}' | sed -n '3p'`
echo "$1 logged in at $a "
