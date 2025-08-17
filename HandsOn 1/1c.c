#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int r;
    r = mkfifo("FIFOfile",0777);
    printf("mkFIFO returns %d\n",r); 

    r = mknod("FIFOmknod",S_IFIFO,0);
    printf("mknod returns %d\n",r);
}