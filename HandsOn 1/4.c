#include<stdio.h>
#include<fcntl.h>
int main()
{
	int fd;
	char *fname = "3.c";
	fd = open(fname,O_RDWR | O_EXCL);
	printf("file descriptor : %d",fd);

	return 0;	
}
