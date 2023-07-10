#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>

void shmem(char arr[][6])
{
    int fd;
    char *a;
    if ((fd = shm_open("krishna1903", O_RDONLY, 0666)) < 0)
    {
        printf("Error");
    }
    a = (char *)mmap(0, 1024, PROT_READ, MAP_SHARED, fd, 0);

    for (int i = 0; i < 10; i++)
    {
        for (int j = (i * 5); j < ((i * 5) + 5); j++)
        {
            printf("%s from sh2\n", a);
        }
    }
    printf("%p", a);
    // munmap(a, 1024);
    close(fd);
}

int main(int argc, char const *argv[])
{
    char arr[50][6];
    // genRandom(5, arr);
    shmem(arr);

    return 0;
}