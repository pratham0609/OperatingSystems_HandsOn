#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handler(int signum)
{
    if (signum == SIGINT)
    {
        printf("\n SIGINT received\n");
        exit(0);
    }
}

int main(void)
{
    struct sigaction action;
    action.sa_handler = &signal_handler;
    if (sigaction(SIGINT, &action, NULL) < 0)
    { 
        perror("sigaction");
        return 1;
    }
    sleep(6);
    printf("SIGINT not received\n");
    return 0;
}
