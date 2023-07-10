#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int P2()
{
    char arr[50];
    int ind[50];
    for (int i = 0; i < 10; i++)
    {

        char *myfifo = "fifo";
        int fd = open(myfifo, O_RDONLY);
        for (int j = i * 5; j < (i * 5 + 5); j++)
        {

            if (read(fd, &arr[j], 6) == -1)
            {
                printf("error");
                return 1;
            }
            printf("%s\n", &arr[j]);
        }
        for (int j = (5 * i); j < (5 * i + 5); j++)
        {
            read(fd, &ind[j], sizeof(j));
            printf("%d\n", ind[j]);
        }
        close(fd);

        // finding maximum.
        int max = ind[0];
        for (int i = 0; i < 5; i++)
        {
            // Compare elements of array with max
            if (ind[i] > max)
                max = ind[i];
        }

        fd = open(myfifo, O_WRONLY);
        if (write(fd, &max, sizeof(int)) == -1)
        {
            printf("error");
        }
        close(fd);
    }
}

int main(int argc, char const *argv[])
{

    P2();

    return 0;
}
