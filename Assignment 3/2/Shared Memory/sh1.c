#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>
#include <semaphore.h>

char arr[50][6];
void genRandom(int n)
{
    
    char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; // ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789/,.-+=~`<>:
    int i;
    for (i = 0; i < 50; i++)
    {
        char word[6];
        // printf(" %s\n", word);
        int j;
        for (j = 0; j < 5; j++)
        {
            word[j] = alpha[rand() % 26];
        }
        word[j] = '\0';
        strcpy(arr[i], word);
    }
}



void shmem()
{
    int fd;
    int k = -1;
    char *a;
    int maximum;
    if ((fd = shm_open("krishna1903", O_CREAT | O_EXCL | O_RDWR, 0666)) < 0)
    {
        printf("Error");
    }
    ftruncate(fd, 1024);
    sem_t *s1 = sem_open("S1", O_CREAT, 0666, 1);
    sem_t *s2 = sem_open("S2", O_CREAT, 0666, 0);
    sem_t *s3 = sem_open("S3", O_CREAT, 0666, 0);
    sem_t *s4 = sem_open("S4", O_CREAT, 0666, 0);
    sem_t *s5 = sem_open("S5", O_CREAT, 0666, 0);
    sem_t *s6 = sem_open("S6", O_CREAT, 0666, 0);

    a = mmap(0, 1024, PROT_WRITE, MAP_SHARED, fd, 0);
    for (int i = 0; i < 10; i++)
    {
        for (int j = (i * 5); j < (i * 5) + 5; j++)
        {
            // sleep(2);

            // sem_wait(s1);
            // sem_wait(s5);
            int b = sprintf(a, "%s", arr[j]);
            // printf("%d", b);
            printf("%s\n",arr[j]);
            sem_post(s2);
            // sem_post(s2);
            // sem_wait(s3);
            // sem_wait(s3);
            // exit(0);
        }
        k = k + 5;
        maximum = k;

        printf("\n%d\n", maximum);
    }
    for (int i = 0; i < 10; i++)
    {
        // sem_wait(s1);
        // // sem_wait(s5);
        // // printf(a, "%s", arr[i]);
        // sem_post(s2);
        // // sem_post(s2);
        // // sem_wait(s3);
        // sem_wait(s3);
    }
    // printf("%p", a);
    // munmap(a, 1024);
    // memset("krishna19", 0, 1024);
    // printf("hi");
    // sem_wait(s5);
    close(fd);
}

int main(int argc, char const *argv[])
{
    genRandom(5);
    shmem();

    return 0;
}