#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    struct flock lock;

    int fd;
    fd = open("16.txt", O_WRONLY);

    if (fd == -1)
        printf("failed to open file\n");
    
    else if (fd > -1)
    {
        lock.l_type = F_RDLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len = 0;
        lock.l_pid = getpid();

        fcntl(fd, F_SETLKW, &lock);
        printf("Read lock implemented.\n Press any key to unlock\n");
        getchar();

        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
        printf("File unlocked\n");
    }
}
