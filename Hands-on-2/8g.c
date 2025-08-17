#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

void signal_handler(int signum)
{
    if (signum == SIGPROF)
    {
        printf("Received SIGPROF\n");
        exit(0);
    }
}

int main(void)
{
    if (signal(SIGPROF, signal_handler) == SIG_ERR)
        printf("\nCan't catch SIGPROF\n");

    struct itimerval timer;
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;

    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);
    printf("Going to sleep\n");
    sleep(6);
    printf("No SIGPROF received\n");
    return 0;
}
