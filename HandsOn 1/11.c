#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd = open("11.txt", O_APPEND | O_WRONLY);
    write(fd, "test\n", 5);
    
    int fd1 = dup(fd);
    write(fd1, "test-dup\n", 9);
    
    int fd2 = dup2(fd, 5);
    write(fd2, "test-dup2\n", 10);
    
    int fc = fcntl(fd, F_DUPFD);
    write(fc, "test-fcntl\n", 11);
    
    return 0;
}