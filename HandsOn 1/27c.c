#include <unistd.h>
#include <stdio.h>

int main()
{
    execle("/bin/ls", "-R", "-l", NULL, NULL);
}