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
        close(fd1[0]); 
        close(1);
        dup(fd1[1]); 
        execl("ls", "ls", "-l", (char *)NULL);
        return 0;
    }
    else
    {
        if (!fork())
        {
            close(fd1[1]); 
            close(fd2[0]); 
            close(0);
            dup(fd1[0]); 
            close(1);
            dup(fd2[1]);
            wait(NULL);
            execl("grep", "grep", "^d", (char *)NULL);
            return 0;
        }
        else
        {
            close(fd2[1]); 
            close(0);
            dup(fd2[0]);
            execlp("wc", "wc", (char *)NULL);
        }
    }
    return 0;
}
