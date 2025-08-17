#!/bin/bash

hour=`date +%H`

if [ $hour -ge 6 -a $hour -le 11 ]
then
	echo Good Morning

elif [ $hour -ge 12 -a $hour -le 15 ]
then
	echo Good Afternoon
else
	echo Good Evening
fi

