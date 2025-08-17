#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum)
{
    if (signum == SIGKILL)
        printf("received SIGKILL\n");
}

int main()
{
    if (!fork())
    {
        printf("In child process, sending kill signal\n");
        kill(getppid(), SIGKILL); 
    }
    else
    {
        sleep(5);
        printf("In parent process\n");
        if (signal(SIGKILL, signal_handler) == SIG_ERR)
            printf("Can't catch SIGKILL\n");
    }
    return 0;
}
