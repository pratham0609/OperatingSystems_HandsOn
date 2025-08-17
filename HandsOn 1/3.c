#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
	int fd ;
	fd = creat("3",O_CREAT);
	printf("File descriptor: %d",fd);
	return 0;
}
