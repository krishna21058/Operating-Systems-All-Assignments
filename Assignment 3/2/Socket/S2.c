
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#define PORT 8051

char arr[50][6];
int recieve()
{

	int socket_c = 0;
	int fd;
	struct sockaddr_in serv_addr;
	char *hello = "Hello from client"; 
	char buffer[1024] = {0};

	if ((socket_c = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_UNIX;
	serv_addr.sin_port = htons(PORT);

	if ((fd = connect(socket_c, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = (i * 5); j < (i * 5) + 5; j++)
		{
			recv(socket_c, arr[j], 1024 , 0);

			printf("%s\n", arr[j]); 
			// printf("%d\n",j);
		}

		for (int j = (i * 5); j < (i * 5) + 5; j++)
		{
			send(socket_c, arr[j], strlen(arr[j]),0);

			printf("%s\n", arr[j]); 
		}

	}

	// closing the connected socket
	close(fd);
}

int main(int argc, char const *argv[])
{
	recieve();

	return 0;
}
