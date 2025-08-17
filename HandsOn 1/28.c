#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sched.h>

int main()
{
    int min = sched_get_priority_min(SCHED_RR);
    int max = sched_get_priority_max(SCHED_RR);
    printf("Minimum priority: %d \nMaximum priority %d \n", min, max);
}