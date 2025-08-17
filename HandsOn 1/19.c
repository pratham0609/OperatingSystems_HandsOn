#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

int main()
{
    clock_t start_time, end_time;
    start_time = clock();
    getpid();
    end_time = clock();
    float time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken to execute getpid function: %f sec\n", time);

    return 0;
}