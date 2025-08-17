#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
    struct record
    {
        int train_no;
        int ticket_no;
    }rec;
    
    int fd, ticket_no, train_no;
    struct flock lock;

    fd = open("record.txt", O_RDWR);
    printf("Enter Train number(1,2,3): ");
    scanf("%d", &train_no);
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (train_no-1) * sizeof(rec);
    lock.l_len = sizeof(rec);
    lock.l_pid = getpid();
    lseek(fd, lock.l_start, SEEK_SET);

    printf("Before Entering into section...\n");
    fcntl(fd, F_SETLKW, &lock);
    printf("Press any key to finish");
    getchar();
    read(fd, &rec, sizeof(rec));
    printf("Ticket number = %d\n", rec.ticket_no);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    close(fd);

    return 0;
}