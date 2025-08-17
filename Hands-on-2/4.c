#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#define ll long long

unsigned ll rdtsc()
{
    unsigned ll dst;
    __asm__ __volatile__("rdtsc": "=A"(dst));

    return dst;
}

int main()
{
    ll int start, end;
    start = rdtsc();

    for (int i = 0; i < 100; i++)
        getppid();
    
    end = rdtsc();
    printf("Time (difference) : %llu \n", end - start);
}
