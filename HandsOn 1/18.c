#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct record
{
    int train_num;
    int tkt_num;
};

int main()
{
    int fd;
    struct record rec_array[3];
    fd = open("record.txt", O_CREAT | O_WRONLY, 0777);
    for (int i = 0; i < 3; i++)
    {
        rec_array[i].train_num = i+1;
        rec_array[i].tkt_num = 1;
    }

    if (write(fd, rec_array, sizeof(rec_array)) != -1)
        printf("WRITE success\n");
    else
        printf("WRITE ERROR\n");

    close(fd);
    return 0;
}