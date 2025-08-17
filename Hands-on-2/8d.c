#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handler(int signum)
{
    if (signum == SIGALRM)
    {
        printf("Received SIGALRM\n");
        exit(0);
    }
}

int main(void)
{
    if (signal(SIGALRM, signal_handler) == SIG_ERR)
        printf("\nCant catch SIGALRM\n");
    alarm(3);
    sleep(6);
    printf("No SIGALRM received\n");
    return 0;
}
