#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int fd1[2];
    int fd2[2];

    if (pipe(fd1) == -1)
    {
        printf("Pipe error\n");
        return 0;
    }
    if (pipe(fd2) == -1)
    {
        printf("Pipe error\n");
        return 0;
    }

    int pid = fork();

    if (pid == 0)
    {
        // child proc
        char a[100];
        char concatStr[100] = "EFGH";
        close(fd1[1]); 
        read(fd1[0], a, 100);
   
        close(fd1[0]);
        close(fd2[0]); 

        strcat(a, concatStr);

        write(fd2[1], a, 100);
        return 0;
    }
    else
    {
        char a[100] = "ABCD";
        close(fd1[0]); 
        write(fd1[1], a, 100);

        wait(NULL);
        close(fd1[1]);
        close(fd2[1]);

        read(fd2[0], a, 100);

        printf("%s \n", a);
    }
    return 0;
}
