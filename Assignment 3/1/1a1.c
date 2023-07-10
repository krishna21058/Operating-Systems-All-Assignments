#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define no_forks 5
#define no_phil 5

int forks[no_forks] = {0};

void dine5(int i)
{

    while (forks[4] != 0)
    {
        sleep(2);
        printf("\nPhilosopher % d is thinking ", i + 1);
    }
    forks[4] = 1;
    while (forks[0] != 0)
    {
        sleep(2);
        printf("\nPhilosopher % d is thinking ", i + 1);
    }
    forks[0] = 1;

    printf("\nPhilosopher % d is eating ", i + 1);

    printf("\nPhilosopher % d Finished eating ", i + 1);
    forks[4] = 0;
    forks[0] = 0;
}
void dine4(int i)
{

    while (forks[3] != 0)
    {
        sleep(2);
        printf("\nPhilosopher % d is thinking ", i + 1);
    }
    forks[3] = 1;
    while (forks[4] != 0)
    {
        sleep(2);
        printf("\nPhilosopher % d is thinking ", i + 1);
    }
    forks[4] = 1;

    printf("\nPhilosopher % d is eating ", i + 1);

    printf("\nPhilosopher % d Finished eating ", i + 1);
    forks[4] = 0;
    forks[3] = 0;
}
void dine3(int i)
{

    while (forks[2] != 0)
    {
        sleep(2);
        printf("\nPhilosopher % d is thinking ", i + 1);
    }
    forks[2] = 1;
    while (forks[3] != 0)
    {
        sleep(2);
        printf("\nPhilosopher % d is thinking ", i + 1);
    }
    forks[3] = 1;

    printf("\nPhilosopher % d is eating ", i + 1);

    printf("\nPhilosopher % d Finished eating ", i + 1);
    forks[2] = 0;
    forks[3] = 0;
}
void dine1(int i)
{

    while (forks[0] != 0)
    {
        sleep(2);
        printf("\nPhilosopher % d is thinking ", i + 1);
    }
    forks[0] = 1;
    while (forks[1] != 0)
    {
        sleep(2);
        printf("\nPhilosopher % d is thinking ", i + 1);
    }
    forks[1] = 1;

    printf("\nPhilosopher % d is eating ", i + 1);

    printf("\nPhilosopher % d Finished eating ", i + 1);
    forks[0] = 0;
    forks[1] = 0;
}
void dine2(int i)
{

    while (forks[1] != 0)
    {
        sleep(2);
        printf("\nPhilosopher % d is thinking ", i + 1);
    }
    forks[1] = 1;
    while (forks[2] != 0)
    {
        sleep(2);
        printf("\nPhilosopher % d is thinking ", i + 1);
    }
    forks[2] = 1;

    printf("\nPhilosopher % d is eating ", i + 1);

    printf("\nPhilosopher % d Finished eating ", i + 1);
    forks[1] = 0;
    forks[2] = 0;
}



int main(void)
{
    pthread_t phil[no_phil];
    for (int i = 0; i < no_phil; i++)
    {
        forks[i] = 0;
    }

    // for (long i = 0; i < no_phil; i++)
    // {
    //     pthread_create(&phil[i], NULL, philosopher, (void *)i);
    // }
    forks[0] = 0;
    forks[1] = 0;
    pthread_create(&phil[0], NULL, (void *)dine1, (void *)0);
    pthread_create(&phil[1], NULL, (void *)dine2, (void *)1);
    pthread_create(&phil[2], NULL, (void *)dine3, (void *)2);
    pthread_create(&phil[3], NULL, (void *)dine4, (void *)3);
    pthread_create(&phil[4], NULL, (void *)dine5, (void *)4);

    for (int i = 0; i < no_phil; i++)
    {
        pthread_join(phil[i], NULL);
    }
    printf("\n");
    return 0;
}
