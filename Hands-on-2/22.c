#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    struct timeval timer;
    fd_set readfds;
    int fd = open("fifo", O_WRONLY);

    const int msg_size = 100;
    char msg[msg_size];
    printf("Enter msg:");
    fflush(stdout);

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);
    timer.tv_sec = 10;
    timer.tv_usec = 0;

    if (!select(fd + 1, &readfds, NULL, NULL, &timer))
        printf("No msg entered\n");
    else
    {
        fgets(msg, msg_size, stdin);
        write(fd, msg, msg_size);
    }
    return (0);
}
