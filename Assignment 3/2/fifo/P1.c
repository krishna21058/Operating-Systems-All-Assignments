#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int P1(char arr[][6])
{

    char *myfifo = "fifo";
    int k = -1;
    if (mkfifo(myfifo, 0777) == -1)
    {
        printf("Cannot create fifo\n");
    }

    for (int i = 0; i < 10; i++)
    {

        int fd = open(myfifo, O_WRONLY);
        for (int j = (5 * i); j < (5 * i + 5); j++)
        {
            write(fd, arr[j], sizeof(arr[j]));
            printf("%s\n", arr[j]);

            // write(fd, &j, sizeof(int));
            // printf("%d\n", j);
        }
        for (int j = (5 * i); j < (5 * i + 5); j++)
        {
            write(fd, &j, sizeof(j));
            printf("%d\n", j);

            // write(fd, &j, sizeof(int));
            // printf("%d\n", j);
        }

        printf("Written. (from P1)");

        close(fd);
        fd = open(myfifo, O_RDONLY);
        int maximum;
        if (read(fd, &maximum, sizeof(int)) == -1)
        {
            printf("error");
        }

        maximum = k;

        printf("\n%d\n", maximum);
        k = k + 5;
        close(fd);
    }
}

void genRandom(int n, char arr[][6])
{
    srand(time(NULL));
    // char alpha[][26] = {'a', 'b', 'c', "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"}; // ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789/,.-+=~`<>:
    char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; // ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789/,.-+=~`<>:

    // char arr[50] = {};

    // char arr[50][50];
    int i;
    for (i = 0; i < 50; i++)
    {
        char word[6];
        // printf(" %s\n", word);
        int j = 0;
        for (j = 0; j < 5; j++)
        {
            word[j] = alpha[rand() % 26];
        }
        word[j] = '\0';
        strcpy(arr[i], word);
    }
}

int main(int argc, char const *argv[])
{
    char arr[50][6];
    genRandom(5, arr);
    // for (int i = 0; i < 50; i++)
    // {
    //     // printf("%d %s\n", i, arr[i]);
    // }
    P1(arr);
    printf("Done!");
    return 0;
}
