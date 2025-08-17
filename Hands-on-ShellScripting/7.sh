#!/bin/bash

echo "Enter : 1-copy 2-remove 3-rename"
read input

case $input in
	1)
		echo "Enter name of file to be copied"
		read i1
		echo "Enter target file"
		read i2
		cp $i1 $i2
		;;
	2)
		echo "Enter name of file to be removed"
		read i
		rm $i
		;;
	3)
		echo "Enter name of file to be renamed"
		read i1
		echo "Enter new name"
		read i2
		mv $i1 $i2
		;;
esac
