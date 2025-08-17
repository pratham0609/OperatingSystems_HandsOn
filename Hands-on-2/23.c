#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int p[2];
    pipe(p);
    printf("maximum number of files can be opened within a process = %d\n", FOPEN_MAX);
    printf("Pipe Size: %d\n", pipe_size);
    return 0;
}

