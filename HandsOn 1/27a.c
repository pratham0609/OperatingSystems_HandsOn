#include <unistd.h>
#include<stdio.h>
int main()
{
    execl("/bin/ls", "-R", "-l", NULL);
}