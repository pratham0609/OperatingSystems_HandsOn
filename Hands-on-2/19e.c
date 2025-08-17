
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    if(mknod("myfifoc",S_IFIFO,0) != 0)
        printf("Failed to execute mknod\n");
    return 0;
}
