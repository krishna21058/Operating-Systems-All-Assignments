#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <sys/wait.h>
#include <sys/types.h>

double timming_A[50];
double timming_B[50];
double timming_C[50];
int i_A = 0;
int i_B = 0;
int i_C = 0;
FILE *fptr;
fptr=fopen("timming.c","w");

void *countA()
{
    int counter = 0;
    struct timespec start, end;
    struct sched_param param1;
    clock_gettime(CLOCK_REALTIME, &start);
    param1.sched_priority = 0;
    int a = pthread_setschedparam(pthread_self(), SCHED_OTHER, &param1);
    for (long i = 0; i <= pow(2, 32); i++)
    {
        counter++;
    }
    clock_gettime(CLOCK_REALTIME, &end);
    double total_time = (end.tv_sec + ((double)end.tv_nsec / (pow(10, 9)))) - (start.tv_sec + ((double)start.tv_nsec / (pow(10, 9))));
    timming_A[i_A] = total_time;
    printf("%f\n", total_time);
    fprintf(fptr,timming_A[i_A]);

    i_A++;
}
void *countB()
{
    int counter = 0;
    struct timespec start, end;
    struct sched_param param2;
    clock_gettime(CLOCK_REALTIME, &start);
    // pthread_setschedprio(i_B+1);
    param2.sched_priority = i_B+1;
    int b = pthread_setschedparam(pthread_self(), SCHED_RR, &param2);
    for (long i = 0; i <= pow(2, 32); i++)
    {
        counter++;
    }
    clock_gettime(CLOCK_REALTIME, &end);
    double total_time = (end.tv_sec + ((double)end.tv_nsec / (pow(10, 9)))) - (start.tv_sec + ((double)start.tv_nsec / (pow(10, 9))));
    timming_B[i_B] = total_time;
    printf("%f\n", total_time);
    i_B++;
}
void *countC()
{
    int counter = 0;
    struct timespec start, end;
    struct sched_param param3;
    clock_gettime(CLOCK_REALTIME, &start);
    param3.sched_priority = i_C+1;
    // pthread_setschedprio(i_C+1);
    int c = pthread_setschedparam(pthread_self(), SCHED_FIFO, &param3);
    for (long i = 0; i <= pow(2, 32); i++)
    {
        counter++;
    }
    clock_gettime(CLOCK_REALTIME, &end);
    double total_time = (end.tv_sec + ((double)end.tv_nsec / (pow(10, 9)))) - (start.tv_sec + ((double)start.tv_nsec / (pow(10, 9))));
    printf("%f\n", total_time);
    timming_C[i_C] = total_time;
    
    i_C++;
}

int main()
{
    pthread_t t1, t2, t3;

    for (int i = 0; i < 10; i++)
    {
        // fwrite(&timming_A[i_A],fptr);
        // fwrite(&timming_B[i_B],fptr);

        pthread_create(&t1, NULL, countA, NULL);
        pthread_create(&t2, NULL, countB, NULL);
        pthread_create(&t3, NULL, countC, NULL);

        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
        pthread_join(t3, NULL);
        printf("\n");

    }

    for (int i = 0; i < 10; i++)
    {
        printf("%f, ",timming_A[i]);
    }
        printf("\n");
    
    for (int i = 0; i < 10; i++)
    {
        printf("%f, ",timming_B[i]);
    }
        printf("\n");
    
    for (int i = 0; i < 10; i++)
    {
        printf("%f, ",timming_C[i]);
    }
        printf("\n");
    


    return 0;
}