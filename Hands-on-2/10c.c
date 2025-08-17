#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handler(int signum)
{
    if (signum == SIGFPE)
    {
        printf("SIGFPE received \n");
        exit(0);
    }
}

int main(void)
{
    struct sigaction action;
    action.sa_handler = &signal_handler;
    if (sigaction(SIGFPE, &action, NULL) < 0)
    { 
        perror("sigaction");
        return 1;
    }
    float n = 1 / 0;
    printf("no SIGFPE received\n");
    return 0;
}
