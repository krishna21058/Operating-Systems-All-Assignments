#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc, char *argv[])
{

    char arr[100];
    if (argv[1] == NULL)
    {
        time_t t;
        struct tm *tpt;
        time(&t);
        tpt = localtime(&t);
        strftime(arr, 100, "%c", tpt);
        printf("%s\n", arr);
    }
    else if(!strcmp(argv[1], "+%d-%m-%y")){
        // printf("here");
        time_t t;
        struct tm *tpt;
        time(&t);
        tpt = localtime(&t);
        strftime(arr, 100,"%d-%m-%y", tpt);
        printf("%s\n", arr);

    }
    else if (!strcmp(argv[1], "-u"))
    {
        // printf("here");
        time_t t;
        struct tm *tpt;
        time(&t);
        tpt = gmtime(&t);
        strftime(arr, 100, "%c", tpt);
        printf("%s\n", arr);
    }
    else
    {
        // printf("here");
        struct tm *ptr;
        time_t t;
        t = time(NULL);
        ptr = localtime(&t);
        // printf("%s", asctime(ptr));
        printf("Wrong command line option entered for date.");

    }
    return 0;
}
