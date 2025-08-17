#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat buff;
    int fd;
    fd = open(argv[1], O_RDONLY);

    if(fd == -1)
        printf("Failed to open file\n");
    
    else if(fd > -1)
        printf("File successfully opened\n");
    
    stat(argv[1], &buff);
    int i = buff.st_mode;

    if(S_ISLNK(i))
        printf("Link file\n");
    
    else if(S_ISREG(i))
        printf("Regular file\n");
    
    else if(S_ISBLK(i))
        printf("Block file\n");
    
    else if(S_ISDIR(i))
        printf("Directory\n");
    
    else if(S_ISCHR(i))
        printf("Character file\n");
    
    else if(S_ISFIFO(i))
        printf("FIFO\n");
    
    else
        printf("Unknown file type\n");
}