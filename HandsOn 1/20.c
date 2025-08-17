#include <stdio.h>
#include<time.h>
#include <sys/types.h>
#include<sys/resource.h>
#include <unistd.h>

int main()
{
    int pid = getpid();
    int priority = getpriority(PRIO_PROCESS,pid);
    printf("Priority : %d\n",priority);
    
    int r = nice(15);
    priority = getpriority(PRIO_PROCESS,pid);
    printf("Priority : %d\n",priority);

}
