#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int main()
{
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);

    struct timeval time;
    time.tv_sec = 10;
    time.tv_usec = 0;

    int retval;
    retval = select(1, &fds, NULL, NULL, &time);

    if (retval == 0)
        printf("Data not available\n");
    else if (retval > 0)
        printf("Data available\n");
}