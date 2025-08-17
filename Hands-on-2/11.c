#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum)
{
    if (signum == SIGINT)
    {
        signal(SIGINT, SIG_DFL);
        printf("\n SIGINT received and set to default\n");
    }
}

int main()
{
    struct sigaction action;
    action.sa_handler = &signal_handler;
    if (sigaction(SIGINT, &action, NULL) < 0)
    {
        perror("sigaction");
        return 1;
    }
    while (1);
    return 0;
}
