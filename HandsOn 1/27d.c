#include <unistd.h>
#include<stdio.h>
int main()
{
    static char *argv[] = {"/bin/ls", "-Rl", NULL};
    execv(argv[0], argv);
}