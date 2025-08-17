#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handler(int signo)
{
    if (signo == SIGSEGV)
    {
        printf("SIGSEGV received\n");
        exit(0);
    }
}

int main(void)
{
    struct sigaction action;
    action.sa_handler = &signal_handler;
    if (sigaction(SIGSEGV, &action, NULL) < 0)
    {
        perror("sigaction");
        return 1;
    }
    int *p = NULL;
    printf("%d\n", *p);
    printf("no SIGSEGV received\n");
    return 0;
}
