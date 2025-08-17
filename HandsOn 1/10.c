#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;
    fd = open("16.txt", O_RDWR);

    char buf[20] = "characters";
    write(fd, buf, 20);

    int seekvalue;
    seekvalue = lseek(fd, 0, SEEK_END);
    printf("lseek value: %d\n", seekvalue);
    write(fd, buf, 20);

    system("od -c 16.txt");

    return 0;
}