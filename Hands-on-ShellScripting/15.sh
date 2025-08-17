#!/bin/bash

echo "1: Enter search pattern" 
read input
sed -n "/$input/p" example.txt
echo -e "\n"

echo "2: Enter the word : " 
read input
sed "/$input/d" example.txt
echo -e "\n"

echo "3: Enter the starting word : "
read input
echo " Enter the end word : "
read input2
sed -n "/^$input.*$input2.$/p" example.txt
echo -e "\n"

echo "Enter the starting line number: "
read input
sed -n "$input,$"p example.txt
echo -e "\n"

echo "Enter the initial  pattern : "
read input
echo "Enter the new pattern : "
read input2
sed "s/$input/$input2/g" example.txt
echo -e "\n"

echo "Enter the string to be added at the beginning of every line : "
read input
sed "s/^/$input/" example.txt
echo -e "\n"

echo "Type in the string to be added at the end of every line : "
read input
sed "s/$/$input/" example.txt
echo -e "\n"

