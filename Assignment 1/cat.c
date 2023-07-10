#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        return -1;
    }


    if (!strcmp(argv[1], "-E"))
    {

        FILE *fptr;

        if ((fptr = fopen(argv[2], "r")))
        {
            if (!fptr)
            {
                printf("Error in opening the file.\n");
                return 1;
            }
            char c;
            while ((c = fgetc(fptr)) != EOF)
            {
                if (c == '\n')
                {
                    printf("$%c", c);
                }
                else
                {
                    printf("%c", c);
                }
            }
        }
        else
        {
            printf("File doesn't exist!\n");
            return 1;
        }
        fclose(fptr);
    }

    else if (!strcmp(argv[1], "-n"))
    {

        FILE *fptr;

        if ((fptr = fopen(argv[2], "r")))
        {
            if (!fptr)
            {
                printf("Error in opening the file.\n");
                return 1;
            }
            char c;
            int flag = 0;
            int line = 1;
            printf("%d ", line);
            char lastchar = 'a';
            while ((c = fgetc(fptr)) != EOF)
            {
                if (c == '\n')
                {
                    if (lastchar == '\n')
                    {
                        printf("%d %c", line, c);
                        line++;
                        flag = 1;
                    }
                    else
                    {
                        printf("%c", c);
                        line++;
                        flag = 1;
                    }
                }
                else
                {
                    if (flag)
                    {
                        printf("%d %c", line, c);
                        flag = 0;
                    }
                    else
                    {
                        printf("%c", c);
                    }
                }
                lastchar = c;
            }
            fclose(fptr);
        }
        else
        {
            printf("File doesn't exist!\n");
            return 1;
        }
    }

    else if(argv[2]==NULL)
    {
        FILE *fptr;

        if ((fptr = fopen(argv[1], "r")))
        {
            if (!fptr)
            {
                printf("Error in opening the file.\n");
                return 1;
            }
            char c;
            while ((c = fgetc(fptr)) != EOF)
            {
                printf("%c", c);
            }
        }

        else
        {
            printf("File doesn't exist!\n");
        }
        fclose(fptr);
    }
    else{
            printf("Wrong command line option entered for cat.");
    }
    return 0;
}
