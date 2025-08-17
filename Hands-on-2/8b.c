#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum)
{
    if (signum == SIGINT)
    {
        printf("Received SIGINT\n");
    }
}

int main(void)
{
    if (signal(SIGINT, signal_handler) == SIG_ERR)
        printf("\nCan't catch SIGINT\n");
    
    sleep(6);
    return 0;
}

