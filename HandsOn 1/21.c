#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() 
{ 
    int pid; 
    pid = fork(); 
    printf("%d\n",pid);
    if (pid == 0) 
    { 
        printf("Child pid: %d\n", getpid());
        printf("Parent pid: %d\n", getppid());
    } 
} 