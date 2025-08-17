#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handler(int signum)
{
    if (signum == SIGFPE)
    {
        printf("Received SIGFPE\n");
        exit(0);
    }
}

int main(void)
{
    if (signal(SIGFPE, signal_handler) == SIG_ERR)
        printf("\nCan't catch SIGFPE\n");
    float n = 1 / 0;
    printf("No SIGFPE received\n");
    return 0;
}
