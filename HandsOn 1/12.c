#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd;
	char *fname = "11.c";
	fd = open(fname,O_WRONLY);
	int mode = fcntl(fd,F_GETFL);
	printf("Opening mode: %d\n",mode & O_ACCMODE);
	return 0;
}

