#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd = open("fifo", O_WRONLY);
    const int msg_size = 100;
    char msg[100] = "hello. FIFO first in first out\n";
    write(fd, msg, msg_size);
    return 0;
}
