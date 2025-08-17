#!/bin/bash

tot=`ls -Rl /dev | grep ^b | wc -l`
echo "total no. of block device files in /dev directory is $tot"
