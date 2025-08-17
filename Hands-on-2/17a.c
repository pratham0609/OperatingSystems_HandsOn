#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <wait.h>

int main()
{
    int fd[2];
    if (pipe(fd) == -1)
    {
        printf("pipe error\n");
        return 1;
    }
    int pid = fork();
    if (pid == 0)
    {
        close(fd[0]); 
        close(1);
        dup(fd[1]); 

        execlp("ls", "ls", "-l", (char *)NULL);
        close(fd[1]);
        return 0;
    }
    else
    {
        close(fd[1]);
        close(0);
        dup(fd[0]); 
        execlp("wc", "wc", (char *)NULL);
        close(fd[0]);
    }
    return 0;
}
