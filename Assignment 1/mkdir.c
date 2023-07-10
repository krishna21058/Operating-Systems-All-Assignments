#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if (argv[1] == NULL)
    {
        return 0;
    }

    if (!strcmp(argv[1], "-v"))
    {

        if (!mkdir(argv[2], 0777))
        {
            printf("mkdir: created directory '%s'\n", argv[2]);
        }
        else
        {
            int m = mkdir(argv[1], 0777);
            if (m == -1)
            {
                printf("Unable to create directory %s. Directory already exists.\n", argv[1]);
            }
            else
            {

                printf("Unable to create directory %s\n", argv[1]);
            }
        }
    }
    else if (!strcmp(argv[1], "-p"))
    {
        int size = strlen(argv[1]);
        int first = 0;
        char *listdir[100];
        char *str = " ";
        int k = 0;
        while ((str = strsep(&argv[2], "/")) != NULL)
        {
            listdir[k] = str;

            k += 1;
        }

        for (int i = 0; i < k; i++)
        {
            if (!mkdir(listdir[i], 0777))
            {
                chdir(listdir[i]);
            }
            else
            {
                int m = mkdir(argv[1], 0777);
                if (m == -1)
                {
                    printf("Unable to create directory %s. Directory already exists. \n", argv[1]);
                }
                else
                {

                    printf("Unable to create directory %s\n", argv[1]);
                }
            }
        }
    }
    else
    {
        // printf("%s", argv[1]);

        if (!mkdir(argv[1], 0777))
        {
            return 0;
        }
        else
        {
            int m = mkdir(argv[1], 0777);
            if (m == -1)
            {
                printf("Unable to create directory %s. Directory already exists.\n", argv[1]);
            }
            else
            {

                printf("Unable to create directory %s\n", argv[1]);
            }
            return 1;
        }
    }

    return 0;
}