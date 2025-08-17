#include<stdio.h>
#include<fcntl.h>
#include<time.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
	int fd;
	struct stat info;
	fd = open(argv[1],O_RDONLY);
	stat(argv[1],&info);

	printf("Inode: %ld\n",info.st_ino);
	printf("No. of hard links: %ld\n",info.st_nlink);
	printf("gid: %d\n",info.st_gid);
	printf("uid: %d\n",info.st_uid);
	printf("size: %ld\n",info.st_size);
	printf("Block size: %ld\n",info.st_blksize);
	printf("No. of blocks: %ld\n",info.st_blocks);
	printf("uid: %d\n",info.st_uid);
	printf("Time of last access: %s \n", ctime(&(info.st_atime)));
    	printf("Time of last modification: %s \n", ctime(&(info.st_mtime)));
	printf("Time of last change: %s \n", ctime(&(info.st_ctime)));




}
