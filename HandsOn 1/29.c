#include <stdio.h>
#include <unistd.h>
#include <sched.h>

int main()
{
    int pid = getpid();
    int p1 = sched_getscheduler(pid);
    printf("Current scheduling policy: %d \n", p1);

    struct sched_param sched_param;
    sched_param.sched_priority = 17;

    sched_setscheduler(pid, SCHED_FIFO, &sched_param);
    int p2 = sched_getscheduler(pid);
    printf("New scheduling policy: %d\n", sched_getscheduler(getpid()));
}

