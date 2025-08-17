#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    int pid;
    printf("Enter pid : ");
    scanf("%d", &pid);
    printf("Sending kill signal\n");
    kill(pid, SIGSTOP);
    return 0;
}
