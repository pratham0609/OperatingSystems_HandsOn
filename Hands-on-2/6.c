#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void *thread1(void *vargp)
{
    sleep(1);
    printf("Thread 1 executed\n");
    return NULL;
}
void *thread2(void *vargp)
{
    sleep(1);
    printf("Thread 2 executed\n");
    return NULL;
}
void *thread3(void *vargp)
{
    sleep(1);
    printf("Thread 3 executed\n");
    sleep(1);
    return NULL;
}

int main()
{
    pthread_t id1,id2,id3;
    printf("In calling thread!\n");
    pthread_create(&id1, NULL, thread1, NULL);
    pthread_join(id1, NULL);
    pthread_create(&id2, NULL, thread2, NULL);
    pthread_join(id2, NULL);
    pthread_create(&id3, NULL, thread3, NULL);
    pthread_join(id3, NULL);
    printf("Back to the calling thread!\n");
    return 0;
}

