#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
    struct record
    {
        int train_num;
        int tkt_num;
    }rec;
    
    int fd, tkt_num, train_num;
    struct flock lock;

    fd = open("record.txt", O_RDWR);
    printf("Enter Train number(1,2,3):");
    scanf("%d", &train_num);
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (train_num-1) * sizeof(rec);
    lock.l_len = sizeof(rec);
    lock.l_pid = getpid();
    lseek(fd, lock.l_start, SEEK_SET);

    printf("Before Entering into section...\n");
    fcntl(fd, F_SETLKW, &lock);
    read(fd, &rec, sizeof(rec));
    printf("Ticket number = %d\n", rec.tkt_num);
    rec.tkt_num++;

    printf("Enter to book...\n");
    getchar();
    getchar();
    lseek(fd, lock.l_start, SEEK_SET);
    write(fd, &rec, sizeof(rec));
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Ticket booked \n");
    close(fd);
    
    return 0;
}