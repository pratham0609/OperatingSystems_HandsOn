#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int fd[2];

    char msg[] = "STRING";
    char rcvdmsg[100];

    if (pipe(fd) == -1)
        printf("Pipe failed\n");

    write(fd[1], msg, 100);
    read(fd[0], rcvdmsg, 100);
    printf("Message recieved %s \n", rcvdmsg);
    return 0;
}
