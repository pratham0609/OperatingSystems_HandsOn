#!/bin/bash

for i in $@
do
	touch $i
	echo "$i created"
done
