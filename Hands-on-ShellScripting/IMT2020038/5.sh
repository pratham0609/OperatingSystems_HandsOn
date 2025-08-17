#!/bin/bash
i=`find / -name $1 2>/dev/null | wc -l`
if [ $i = 0 ]
then
	echo "File doesn't exist"

fi
