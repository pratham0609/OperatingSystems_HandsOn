#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *printID(void *id) 
{
   sleep(1);
   long tid; 
   tid = (long)id;
   printf("Thread ID: %ld\n", tid);
   return NULL;
}

int main()
{
    pthread_t thread[3]; 
    for(int i = 0; i < 3; i++)
    {
        printf("Creating thread: %ld\n", thread[i]);
        pthread_create(&thread[i],NULL,printID, (void *)(thread[i]));
        pthread_join(thread[i],NULL);
    }
    return 0;
}
