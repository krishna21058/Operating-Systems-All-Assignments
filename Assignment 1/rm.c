#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>

int rm(char **argv,int i)
{
    if (remove(argv[i]) == 0)
    {
        return 0;
    }
    else
    {
        printf("Error: File doesn't exist or it is a directory!\n");
        return 1;
    }
}

int main(int argc, char *argv[])

{
    int i = 1;
    while (argv[i] != NULL)
    {
        // printf("%d",i);
        if(!strcmp(argv[1],"-v")){
            int check=rm(argv,++i);
            if(check==0){
                printf("removed %s\n",argv[i]);
            }
            i++;
        }
        else if (!strcmp(argv[1],"-i"))
        {
            printf("rm: remove regular empty file %s ?", argv[++i]);
            char choice;
            scanf("%c", &choice);
            if (choice == 'Y' || choice == 'y')
            {
                rm(argv,i);
                i++;
            }
            else
            {
                continue;
            }
        }
        else if(argv[2]==NULL)
        {
            rm(argv,i);
            i++;
        }
        else{
            printf("Wrong command line option entered for rm.");
        }
    }
    return 0;
}
