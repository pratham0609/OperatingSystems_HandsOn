#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buf[1];
    fd = open("./8.txt", O_RDONLY);

    while (read(fd, buf, 1))
        printf("%c", buf[0]);
    
    close(fd);
}