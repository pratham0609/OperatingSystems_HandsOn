#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

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
        printf("\nCan't catch SIGALRM\n");
    struct itimerval timer;
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;

    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);
    sleep(6);
    printf("No SIGALRM received\n");
    return 0;
}
