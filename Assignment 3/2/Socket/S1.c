#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORT 8051

char arr[50][6];
void genRandom(int n)
{
 
    char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; // ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789/,.-+=~`<>:

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

int sock_send()
{
    int server_fd, socket_c;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    int k = -1;

    if ((server_fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
    {

        return 1;
    }

    address.sin_family = AF_UNIX;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {

        return 1;
    }
    if (listen(server_fd, 3) < 0)
    {
        return 1;
    }
    if ((socket_c = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        return 1;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = (i * 5); j < (i * 5) + 5; j++)
        {
            send(socket_c, arr[j], strlen(arr[j]), 0);

            printf("%s\n", arr[j]);
            /* code */
        }
        int maximum;
        int *j;
        if ((recv((intptr_t)sock_send, j, 1024, 0)) == -1)
        {
            // printf("error");
        }

        k = k + 5;
        maximum = k;

        printf("\n%d\n", maximum);
    }

    close(socket_c);
}

int main(int argc, char const *argv[])
{
    genRandom(5);
    sock_send();
    return 0;
}
