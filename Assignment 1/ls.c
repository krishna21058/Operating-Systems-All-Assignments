#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
void swap_str(char str1[], char str2[])
{

    char temp[500];

    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}
void printArr(char *arr[], int len, char *del)
{
    int k = 0;
    while (k < len)
    {
        if (k == (len - 1))
        {
            printf("%s", arr[k]);
        }
        else
        {
            printf("%s%s", arr[k], del);
        }
        k++;
    }
    printf("\n");
}

void sort(char *str[], int len, int order_type, char *del)
{

    int i = 0;
    while (i < len)
    {

        int j = 0;
        while (j < len)
        {

            if ((order_type == 0) &&
                (strcmp(str[i], str[j]) < 0))
            {

                swap_str(str[i], str[j]);
            }
            else if ((order_type == 1) &&
                     (strcmp(str[i], str[j]) > 0))
            {

                swap_str(str[i], str[j]);
            }

            j++;
        }

        i++;
    }

    printArr(str, len, del);
}
void ls(char **argv, int argc, char *dirpath)
{
    char *files[500];

    DIR *dir;
    dir = opendir(dirpath); // For current directory.

    if (dir == NULL)
    {
        return;
    }

    struct dirent *object;
    int k = 0;
    while ((object = readdir(dir)) != NULL)
    {
        if (((object->d_name)[0] == '.'))
        {
            continue;
        }
        files[k] = object->d_name;
        k++;
    }

    if (argc == 1)
    {
        printArr(files, k, " ");
    }
    else if (argc == 2)
    {
        if ((!strcmp(argv[1], "-r")))
        {
            sort(files, k, 1, " ");
        }
        else if ((!strcmp(argv[1], "-m")))
        {

            printArr(files, k, ", ");
        }

        else
        {
            sort(files, k, 0, " ");
        }
    }
    else if (argc == 3)
    {

        if ((!strcmp(argv[1], "-m")) && (!strcmp(argv[2], "-r")))
        {
            sort(files, k, 1, ", ");
        }
        else if ((!strcmp(argv[1], "-r")) && (!strcmp(argv[2], "-m")))
        {

            sort(files, k, 1, ", ");
        }
        else if ((!strcmp(argv[1], "-r")))
        {
            sort(files, k, 1, "\n");
        }
        else if ((!strcmp(argv[1], "-m")))
        {
            printArr(files, k, ", ");
        }
    }
    else
    {
        printArr(files, k, ", ");
    }

    closedir(dir);
}

int main(int argc, char *argv[])
{
    if (argv[1] == NULL)
    {
        ls(argv, argc, ".");
    }
    else
    {
        // printf("%s", argv[2]);
        if ((argv[2] == NULL) && strcmp(argv[1], "-r") && strcmp(argv[1], "-m"))
        {
            ls(argv, argc, argv[1]);
        }

        else if ((!strcmp(argv[1], "-r")) || (!strcmp(argv[1], "-m")))
        {
            if (argv[2] == NULL)
            { // case ls -r/-m
                ls(argv, argc, ".");
            }
            else if ((!strcmp(argv[2], "-m")) || (!strcmp(argv[2], "-r")))
            { // case ls -r -m <path>
                if (argv[3] == NULL)
                {
                    ls(argv, argc, ".");
                }
                else
                {
                    // printf("case ls -r -m <path>");
                    ls(argv, argc, argv[3]);
                }
            }

            else if ((!strcmp(argv[1], "-m")) || (!strcmp(argv[1], "-r"))) // case ls -r/-m <path>
            {
                if (argv[3] == NULL)
                {
                    ls(argv, argc, argv[2]);
                }
            }
            else{
                printf("Wrong command line option entered for ls.");
            }
        }
    }
    return 0;
}
