#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

void read_shm(char *ptr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%c ", *(ptr + i));
    printf("\n");
    return;
}

int main()
{
    //Creating shm
    key_t key;
    int rand;
    key = ftok(".", 'a');
    int size = 1024;
    int shmid = shmget(key, size, 0666 | IPC_CREAT);
    printf("Id for the shm is: %d\n", shmid);
    char *ptr = (char *)shmat(shmid, (void *)0, 0);


    //Writing to shm
    printf("Reading the data before writing anything!\n");
    read_shm(ptr, size);
    sleep(2);
    for (int i = 0; i < 10; i++)
        *(ptr + i) = 'a';
    printf("Reading the data after writing!\n");
    read_shm(ptr, size);
    

    //Attaching shm to ptr
    char *read_ptr = (char *)shmat(shmid, (void *)0, 0 | SHM_RDONLY);
    printf("Attached with a readonly ptr!\n");
    
    sleep(2);
    int a;
    printf("Enter 1 if you want to overwrite ");
    scanf("%d",&a);
    if(a==1){
        printf("Attempting to overwrite\n");
        for(int i = 0; i < 10; i++)
            *(read_ptr + i) = 'b';
    }

    read_shm(read_ptr, size);


    //Detaching shm
    printf("Detaching the memory segments\n");
    int val = shmdt(ptr);
    if (val != 0)
        printf("Detach failed\n");
    val = shmdt(read_ptr);
    if (val != 0)
        printf("Detach failed\n");


    //Removing shm
    printf("Removing the shared memory\n");
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}