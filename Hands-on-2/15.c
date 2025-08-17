#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int fd1[2];

    if (pipe(fd1) == -1)
    {
        printf("Pipe error\n");
        return 0;
    }

    int pid = fork();
    if (pid == 0)
    {
        // child proccess
        char a[100];
        close(fd1[1]); 
        read(fd1[0], a, 100);

        printf("Child process message recieved : %s \n", a);
    }
    else
    {
        char a[100] = "STRING";
        close(fd1[0]); 
        write(fd1[1], a, 100);
    }

    return 0;
}
