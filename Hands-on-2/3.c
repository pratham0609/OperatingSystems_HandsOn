#include<stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

int main()
{
    struct rlimit r;

    getrlimit(RLIMIT_FSIZE , &r);
    printf("Soft Limit : %lu \nHard Limit : %lu\n\n",r.rlim_cur,r.rlim_max);

    r.rlim_cur = 2;
    r.rlim_max = 5;

    setrlimit(RLIMIT_FSIZE, &r);
    getrlimit(RLIMIT_FSIZE , &r);
    printf("Soft Limit : %lu \nHard Limit : %lu\n\n",r.rlim_cur,r.rlim_max);
}

