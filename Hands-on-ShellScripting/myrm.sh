#!/bin/bash

if [ ! -d "/home/.recyclebin" ]
then
	mkdir home/"$USER"/.recyclebin/
fi
for i in $@
do
	mv $i ~/.recyclebin
done
