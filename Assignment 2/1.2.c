#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <sys/wait.h>
#include <sys/types.h>


int main()
{
    pid_t pid1, pid2, pid3;
    struct timespec start, end1, end2, end3;
    struct sched_param param1, param2, param3;
    clock_gettime(CLOCK_REALTIME, &start);
    pid1 = fork();
    if (pid1 == 0)
    {
        param1.sched_priority = 0;
        sched_setscheduler(pid1, SCHED_OTHER, &param1);
        // char* arr[]={"/home/krishna/OS/Assignment2/./bash.sh",NULL};
        execlp("sh", "sh", "bash.sh", NULL);
    }
    pid2 = fork();
    if (pid2 == 0)
    {
        param2.sched_priority = 20;
        sched_setscheduler(pid2, SCHED_RR, &param2);
        // char* arr[]={"/home/krishna/OS/Assignment2/./bash.sh",NULL};
        execlp("sh", "sh", "bash.sh", NULL);


    }
    pid3 = fork();
    if (pid3 == 0)
    {
        param3.sched_priority = 20;
        sched_setscheduler(pid3, SCHED_FIFO, &param3);
        // char* arr[]={"/home/krishna/OS/Assignment2/./bash.sh",NULL};
        execlp("sh", "sh", "bash.sh", NULL);


    }
    int a = wait(NULL);
    if (a == pid1)
    {
        clock_gettime(CLOCK_REALTIME, &end1);
    }
    else if (a == pid2)
    {

        clock_gettime(CLOCK_REALTIME, &end2);
    }
    else if (a == pid3)
    {
        clock_gettime(CLOCK_REALTIME, &end3);
    }
    int b = wait(NULL);
    if (b == pid1)
    {
        clock_gettime(CLOCK_REALTIME, &end1);
    }
    else if (b == pid2)
    {

        clock_gettime(CLOCK_REALTIME, &end2);
    }
    else if (b == pid3)
    {
        clock_gettime(CLOCK_REALTIME, &end3);
    }
    int c = wait(NULL);
    if (c == pid1)
    {
        clock_gettime(CLOCK_REALTIME, &end1);
    }
    else if (c == pid2)
    {

        clock_gettime(CLOCK_REALTIME, &end2);
    }
    else if (c == pid3)
    {
        clock_gettime(CLOCK_REALTIME, &end3);
    }
    double total_time1 = (end1.tv_sec + ((double)end1.tv_nsec / (pow(10, 9)))) - (start.tv_sec + ((double)start.tv_nsec / (pow(10, 9))));
    double total_time2 = (end2.tv_sec + ((double)end2.tv_nsec / (pow(10, 9)))) - (start.tv_sec + ((double)start.tv_nsec / (pow(10, 9))));
    double total_time3 = (end3.tv_sec + ((double)end3.tv_nsec / (pow(10, 9)))) - (start.tv_sec + ((double)start.tv_nsec / (pow(10, 9))));

    printf("%f\n", total_time1);
    printf("%f\n", total_time2);
    printf("%f\n", total_time3);

    return 0;
}
