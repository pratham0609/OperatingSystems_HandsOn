#! /bin/bash

awk '{print;}' employee.txt
echo -e "\\n"

echo "Enter the pattern to be searched"
read pattern
awk "{print $"$pattern";}" employee.txt
echo -e "\\n"

echo "Enter the number of the field : "
read num
awk "{print $"$num";}" employee.txt
echo -e "\\n"

awk 'BEGIN {print "Name\tDesignation\tDepartment\tSalary";}
{print $2,"\t",$3,"\t",$4,"\t",$NF; }
END{print "\nReport Generated\n;}' employee.txt
echo -e "\\n"

awk '$1 >200' employee.txt
echo -e "\\n"

awk '$4 ~/Technology/' employee.txt
echo -e "\\n"

awk 'BEGIN { i=0;}
$4 ~ /Technology/ { i++; }
END { print" Technology department has",i,"employees";}' employee.txt
echo -e "\\n"
