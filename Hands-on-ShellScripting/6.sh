#!/bin/bash

read num
case $num in
	1)
		ls
		;;
	2)
		pwd
		;;
	3)
		who
		;;
	4)
		exit
		;;
esac
