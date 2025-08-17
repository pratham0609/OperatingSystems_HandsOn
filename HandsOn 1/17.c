#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

struct ticket
{
    int ticketno;
};

int main()
{
    int fd = open("Ticket reservation", O_RDWR | O_CREAT);

    struct ticket tk;
    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    fcntl(fd, F_SETLKW, &lock);
    lseek(fd, -1 * sizeof(struct ticket), SEEK_END);
    read(fd, &tk, sizeof(struct ticket));
    tk.ticketno++;
    printf("Ticket no.: %d\n", tk.ticketno);
    write(fd, &tk, sizeof(struct ticket));

    printf("Press any char to unlock file");
    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    close(fd);
}