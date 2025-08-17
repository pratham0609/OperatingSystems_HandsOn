#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handler(int signum)
{
    if (signum == SIGSEGV)
    {
        printf("Received SIGSEGV\n");
        exit(0);
    }
}

int main()
{
    if (signal(SIGSEGV, signal_handler) == SIG_ERR)
        printf("\nCan't catch SIGSEGV\n");

    int *p = NULL;
    printf("%d\n", *p);
    printf("No SIGSEGV received\n");
    return 0;
}
