#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define no_forks 5
sem_t forks[no_forks];
void use();

void finish(int i)
{
    printf("Philosopher %d is thinking.\n", i + 1);

    if (i % 2 == 1)
    {
        sem_wait(&forks[(i + 1) % no_forks]);
        sem_wait(&forks[i]);
    }
    else if (i % 2 == 0)
    {
        sem_wait(&forks[i]);
        sem_wait(&forks[(i + 1) % no_forks]);
    }
    else
    {
        return;
    }
    printf("Philosopher %d is eating.\n", i + 1);
    sleep(2);
    use();

    sem_post(&forks[i]);

    sem_post(&forks[(i + 1) % no_forks]);

    printf("Philosopher %d is done with eating.\n", i + 1);
}


void use(int n)
{
    
    int arr[50][5];
    char f[5] = {'a', 'b', 'c', 'd', 'e'}; 
    int i;
    for (i = 0; i < 50; i++)
    {
        char word[6];
        // printf(" %s\n", word);
        int j;
        for (j = 0; j < 5; j++)
        {
            word[j] = f[rand() % 5];
        }
        word[j] = '\0';
        // strcpy(arr[i], word);
    }
}
void *use_thread(int argv)
{
    finish(argv);
}
int createandjoin()
{
    intptr_t i;

    int no_phil = 5;
    pthread_t phil[no_phil];

    for (i = 0; i < no_forks; i++)
    {

        if ((sem_init(&forks[i], 0, 1)) == -1)
        {
            printf("Error\n");
            return 1;
        }
        if ((pthread_create(&phil[i], NULL, (void *)use_thread, (int *)i) == -1))
        {
            printf("Error in thread creation.\n");
            return 1;
        }
    }
    for (int j = 0; j < no_phil; j++)
    {

        if ((pthread_join(phil[j], NULL)) == -1)
        {
            printf("Error in thread join.\n");
            return 1;
        }
    }
}
int main()
{
    createandjoin();
    return 0;
}