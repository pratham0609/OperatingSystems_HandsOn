#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int returns;
    returns = creat("5a", O_CREAT);
    printf("File discriptor %d\n", returns);
    returns = creat("5b", O_CREAT);
    printf("File discriptor %d\n", returns);
    returns = creat("5c", O_CREAT);
    printf("File discriptor %d\n", returns);
    returns = creat("5d", O_CREAT);
    printf("File discriptor %d\n", returns);
    returns = creat("5e", O_CREAT);
    printf("File discriptor %d\n", returns);
    while (1){};
}