#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>

void *use_thread(void *argv)
{
	system((char *)(argv));
}

void thread_execution(char **list, char wd[])
{

	char final[100] = {0};
	pthread_t t1;

	if (!strcmp(list[0], "rm"))
	{
		strcat(final, "./rm ");
		int ele = 1;
		while (list[ele] != NULL)
		{
			strcat(final, list[ele]);
			ele++;
			if (list[ele] != NULL)
			{

				strcat(final, " ");
			}
		}
		if (!pthread_create(&t1, NULL, use_thread, final))
		{
		}
		pthread_join(t1, NULL);
	}
	else if (!strcmp(list[0], "date"))
	{

		strcat(final, "./date ");
		int ele = 1;
		while (list[ele] != NULL)
		{
			strcat(final, list[ele]);
			ele++;
			if (list[ele] != NULL)
			{

				strcat(final, " ");
			}
		}
		if (!pthread_create(&t1, NULL, use_thread, final))
		{
		}
		pthread_join(t1, NULL);
	}
	else if (!strcmp(list[0], "ls"))
	{

		strcat(final, "./ls ");

		int ele = 1;
		while (list[ele] != NULL)
		{
			strcat(final, list[ele]);
			ele++;
			if (list[ele] != NULL)
			{

				strcat(final, " ");
			}
		}
		if (!pthread_create(&t1, NULL, use_thread, final))
		{
		}
		pthread_join(t1, NULL);
	}
	else if (!strcmp(list[0], "mkdir"))
	{

		strcat(final, "./mkdir ");
		int ele = 1;
		while (list[ele] != NULL)
		{
			strcat(final, list[ele]);
			ele++;
			if (list[ele] != NULL)
			{

				strcat(final, " ");
			}
		}
		// printf("%s", final);
		if (!pthread_create(&t1, NULL, use_thread, final))
		{
		}
		pthread_join(t1, NULL);
	}
	else if (!strcmp(list[0], "cat"))
	{

		strcat(final, "./cat ");

		int ele = 1;

		while (list[ele] != NULL)
		{
			strcat(final, list[ele]);
			ele++;
			if (list[ele] != NULL)
			{

				strcat(final, " ");
			}
		}
		// strcat(final, list[1]);
		if (!pthread_create(&t1, NULL, use_thread, final))
		{
		}
		pthread_join(t1, NULL);
	}
	if (!strcmp(list[0], "pwd"))
	{
		char s[100];
		if (list[1] == NULL)
		{
			printf("%s\n", getcwd(s, 100));
		}
		else if (!strcmp(list[1], "-l"))
		{
			printf("%s\n", getcwd(s, 100));
		}
		else if (!strcmp(list[1], "-p"))
		{
			printf("%s\n", getcwd(s, 100));
		}
		else
		{
			printf("Wrong command line option entered for pwd.");
		}
	}
	else if (!strcmp(list[0], "cd"))
	{
		if (!strcmp(list[1], "~"))
		{
			chdir(wd);
		}
		else if (!strcmp(list[1], ".."))
		{
			chdir("..");
		}
		else
		{
			if (chdir(list[1]))
			{
				printf("No such file or directory\n");
			}
		}
	}
	else if (!strcmp(list[0], "echo"))
	{
		if (!strcmp(list[1], "--help"))
		{

			system("/bin/echo --help");
		}
		else if (!strcmp(list[1], "-n"))
		{
			int m = 2;
			while (list[m] != NULL)
			{
				printf("%s ", list[m]);
				m++;
			}
		}
		else
		{
			int m = 1;
			while (list[m] != NULL)
			{
				printf("%s ", list[m]);
				m++;
			}
			printf("\n");
		}
	}
	else if (!strcmp(list[0], "exit"))
	{
		exit(0);
	}
}

int checkCommands(char **list, char wd[])
{
	if (!strcmp(list[0], "cd\n"))
	{
		if (list[1] == NULL)
		{
			chdir(wd);
		}
		return 1;
	}
	else if (!strcmp(list[0], "cat\n"))
	{
		if (list[1] == NULL)
		{
			printf("cat: missing operand.\n");
		}
		return 1;
	}
	else if (!strcmp(list[0], "mkdir\n"))
	{
		if (list[1] == NULL)
		{
			printf("mkdir: missing operand.\n");
		}
		return 1;
	}

	else if (!strcmp(list[0], "rm") || !strcmp(list[0], "rm\n"))
	{
		if (list[1] == NULL)
		{
			printf("rm: missing operand.\n");
			return 1;
		}
		if (!strcmp(list[1], "-i") || !strcmp(list[1], "-v"))
		{
			if (list[2] == NULL)
			{
				printf("rm: missing operand.\n");
				return 1;
			}
		}
	}

	return 0;
}

int main(int argc, char const *argv[])
{
	char wd[100];
	getcwd(wd, 100);
	char prompt[] = ">> ";
	while (1)
	{

		printf("%s", prompt);
		char inp[100];
		char *strinp = (char *)malloc(100 * sizeof(char));

		fgets(strinp, 100, stdin);
		int i = 0;

		int size = strlen(strinp);
		char secondlast = strinp[size - 3];
		char last = strinp[size - 2];

		if (!strcmp(strinp, "\n"))
		{
			continue;
		}

		else
		{
			char *list[100];
			char *str = " ";
			int k = 0;
			while ((str = strsep(&strinp, " ")) != NULL)
			{
				if (!strcmp(str, "&t\n"))
				{
					continue;
				}
				list[k] = str;
				k += 1;
			}
			int i = 1;
			list[k] = NULL;

			if (checkCommands(list, wd))
			{
				continue;
			}

			else if (secondlast == '&' && last == 't')
			{

				thread_execution(list, wd);

				continue;
			}

			for (int i = 0; i < k; i++)
			{
				int size_ele = strlen(list[i]);
				if (list[i][size_ele - 1] == '\n')
				{
					list[i][size_ele - 1] = '\0';
				}
			}

			// Internal commands
			if (!strcmp(list[0], "pwd"))
			{
				char s[100];
				if (list[1] == NULL)
				{
					printf("%s\n", getcwd(s, 100));
				}
				else if (!strcmp(list[1], "-l"))
				{
					printf("%s\n", getcwd(s, 100));
				}
				else if (!strcmp(list[1], "-p"))
				{
					printf("%s\n", getcwd(s, 100));
				}
				else
				{
					printf("Wrong command line option entered for pwd.");
				}
			}
			else if (!strcmp(list[0], "cd"))
			{
				if (!strcmp(list[1], "~"))
				{
					chdir(wd);
				}
				else if (!strcmp(list[1], ".."))
				{
					chdir("..");
				}
				else
				{
					if (chdir(list[1]))
					{
						printf("No such file or directory\n");
					}
				}
			}
			else if (!strcmp(list[0], "echo"))
			{
				if (!strcmp(list[1], "--help"))
				{

					system("/bin/echo --help");
					continue;
				}
				else if (!strcmp(list[1], "-n"))
				{
					int m = 2;
					while (list[m] != NULL)
					{
						printf("%s ", list[m]);
						m++;
					}
					continue;
				}
				else
				{
					int m = 1;
					while (list[m] != NULL)
					{
						printf("%s ", list[m]);
						m++;
					}
					printf("\n");
				}
			}

			// External Commands
			else if (!strcmp(list[0], "rm"))
			{
				// printf("here");
				if (list[2] == NULL)
				{
					char *argv[] = {"./rm", list[1], NULL};
					int pid = fork();
					if (pid == 0)
					{
						execv(argv[0], argv);
					}
					else
					{
						wait(NULL);
					}
				}
				else if (list[3] == NULL)
				{
					char *argv[] = {"./rm", list[1], list[2], NULL};
					int pid = fork();
					if (pid == 0)
					{
						execv(argv[0], argv);
					}
					else
					{
						wait(NULL);
					}
				}
			}
			else if (!strcmp(list[0], "ls"))
			{
				if (list[1] == NULL)
				{
					char *argv[] = {"./ls", NULL};
					int pid = fork();
					if (pid == 0)
					{
						execv(argv[0], argv);
					}
					else
					{
						wait(NULL);
					}
				}
				else if (list[2] == NULL)
				{
					char *argv[] = {"./ls", list[1], NULL};

					int pid = fork();
					if (pid == 0)
					{
						execv(argv[0], argv);
					}
					else
					{
						wait(NULL);
					}
				}
				else if (list[3] == NULL)
				{
					char *argv[] = {"./ls", list[1], list[2], NULL};

					int pid = fork();
					if (pid == 0)
					{
						execv(argv[0], argv);
					}
					else
					{
						wait(NULL);
					}
				}
				else
				{
					char *argv[] = {"./ls", list[1], list[2], list[3], NULL};

					int pid = fork();
					if (pid == 0)
					{
						execv(argv[0], argv);
					}
					else
					{
						wait(NULL);
					}
				}
			}

			else if (!strcmp(list[0], "date"))
			{

				if (list[1] == NULL)
				{
					char *argv[] = {"./date", NULL};
					int pid = fork();

					if (pid == 0)
					{
						execv(argv[0], argv);
					}
					else
					{
						wait(NULL);
					}
				}
				else
				{
					char *argv[] = {"./date", list[1], NULL};

					int pid = fork();
					if (pid == 0)
					{
						execv(argv[0], argv);
					}
					else
					{
						wait(NULL);
					}
				}
			}
			else if (!strcmp(list[0], "cat"))
			{
				if (list[2] == NULL)
				{
					char *argv[] = {"./cat", list[1], NULL};

					int pid = fork();
					if (pid == 0)
					{
						execv(argv[0], argv);
					}
					else
					{
						wait(NULL);
					}
				}
				else
				{
					char *argv[] = {"./cat", list[1], list[2], NULL};

					int pid = fork();
					if (pid == 0)
					{
						execv(argv[0], argv);
					}
					else
					{
						wait(NULL);
					}
				}
			}
			else if (!strcmp(list[0], "mkdir"))
			{
				int nodir = 1;
				while (list[nodir] != NULL)
				{
					if (!strcmp(list[1], "-v"))
					{
						char *argv[] = {"./mkdir", list[1], list[++nodir], NULL};
						int pid = fork();
						if (pid == 0)
						{
							execv(argv[0], argv);
						}
						else
						{
							wait(NULL);
						}
						// nodir++;
					}
					else if (!strcmp(list[1], "-p"))
					{
						char *argv[] = {"./mkdir", list[1], list[++nodir], NULL};
						int pid = fork();
						if (pid == 0)
						{
							execv(argv[0], argv);
						}
						else
						{
							wait(NULL);
						}
						// nodir++;
					}

					else
					{

						char *argv[] = {"./mkdir", list[nodir], NULL};
						int pid = fork();
						if (pid == 0)
						{
							execv(argv[0], argv);
						}
						else
						{
							wait(NULL);
						}
						nodir++;
					}
				}
			}

			// Exit command
			else if (!strcmp(list[0], "exit"))
			{
				exit(0);
			}
			else
			{
				printf("Command %s not found!\n", list[0]);
			}
		}
		free(strinp);
	}

	return 0;
}
