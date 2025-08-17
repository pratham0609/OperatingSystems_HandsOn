#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char *buffer = (char *)malloc(100);
    read(0, buffer, 100);
    write(1, buffer, 100);
}
