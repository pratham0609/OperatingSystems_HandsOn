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
    fgets(mq.message, 100, stdin);
    msgsnd(msgid, &mq, sizeof(mq), 0);

    execlp("ipcs", "ipcs", "-q", NULL);
    
    return 0;
}
