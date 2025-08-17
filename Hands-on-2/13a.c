#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler()
{
    printf("SIGSTOP received \n");
}

int main()
{
    int pid = getpid();
    printf("%d Waiting for SIGSTOP\n", pid);
    if (signal(SIGSTOP, signal_handler) == SIG_ERR)
    {
        perror("signal ");
        printf("Can't catch SIGSTOP\n");
    }
    while (1);
    return 0;
}
