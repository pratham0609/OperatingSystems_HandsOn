#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <stdio.h>

int main()
{
    if(mkfifo("myFIFOc", 0) != 0)
        printf("Failed to execute mkfifo\n");
    return 0;
}
