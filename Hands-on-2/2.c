#include<stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

int main()
{
    struct rlimit r;

    getrlimit(RLIMIT_AS , &r);
    printf("Soft Limit : %lu \nHard Limit : %lu\n",r.rlim_cur,r.rlim_max);

    getrlimit(RLIMIT_CORE , &r);
    printf("Soft Limit : %lu \nHard Limit : %lu\n",r.rlim_cur,r.rlim_max);

    getrlimit(RLIMIT_CPU , &r);
    printf("Soft Limit : %lu \nHard Limit : %lu\n",r.rlim_cur,r.rlim_max);

    getrlimit(RLIMIT_FSIZE , &r);
    printf("Soft Limit : %lu \nHard Limit : %lu\n",r.rlim_cur,r.rlim_max);

}
