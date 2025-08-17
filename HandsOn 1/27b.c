#include <stdio.h>
#include <unistd.h>

int main()
{
    execlp("/bin/ls", "-R", "-l", NULL);
}