#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

struct msg
{
    long int type;
    char message[100];
} mq;

int main()
{
    int msgid;
    key_t key;

    key = ftok(".", 'a');
    msgid = msgget(key, 0);

    mq.type = 10;

    msgrcv(msgid, &mq, sizeof(mq), 10, 0);

    printf("Message received %s", mq.message);

    execlp("ipcs", "ipcs", "-q", NULL);
    return 0;
}
