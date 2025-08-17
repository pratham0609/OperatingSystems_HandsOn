#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int pid, pid1, pid2;
    pid = fork();

    if (pid == 0)
    {
        sleep(3);
        printf("First child with pid %d and ppid %d\n", getpid(),getppid());
    }
    else
    {
        pid1 = fork();
        if (pid1 == 0)
        {
            sleep(2);
            printf("Second child with pid %d and ppid %d\n", getpid(),getppid());
        }
        else
        {
            pid2 = fork();
            if (pid2 == 0)
                printf("Third child with pid %d and ppid %d\n", getpid(), getppid());
        }
    }
    waitpid(pid, NULL, 0);

    return 0;
}

