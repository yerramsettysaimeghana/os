#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t room; //Declaration of semaphore
sem_t chopstick[5];

void *philosopher(void *);
void eat(int);
int main()
{
      int i, a[5];
      pthread_t tid[5]; // Declaration of thread 

      sem_init(&room, 0, 4);// Initialization
            /*sem       address of the declared semaphore
            pshared   should be 0 (not shared with threads in other processes)
            value     the desired initial value of the semaphore	*/

      for (i = 0; i < 5; i++)
            sem_init(&chopstick[i], 0, 1); // Initialization
            /*sem       address of the declared semaphore
            pshared   should be 0 (not shared with threads in other processes)
            value     the desired initial value of the semaphore	*/

      for (i = 0; i < 5; i++)
      {
            a[i] = i;
            pthread_create(&tid[i], NULL, philosopher, (void *)&a[i]); //creation of thread

         /*thread    Pointer to the location where the created thread's ID
		     is to be returned.

	   attr	     Pointer to the thread attributes object describing the
		     characteristics of the created thread. If the value is
		     NULL, default attributes will be used.

	   start_routine
		     Function to be executed by the newly created thread.

	   arg	     Parameter to be passed to the created thread's  start_routine.*/
      }


      for (i = 0; i < 5; i++)
            pthread_join(tid[i], NULL);
}

void *philosopher(void *num)
{
      int phil = *(int *)num; // to type cast to get value

      sem_wait(&room);
      printf("\nPhilosopher %d has entered room", phil);
      sem_wait(&chopstick[phil]);
      sem_wait(&chopstick[(phil + 1) % 5]);

      eat(phil);  
      sleep(2);
      printf("\nPhilosopher %d has finished eating", phil);

      sem_post(&chopstick[(phil + 1) % 5]);
      sem_post(&chopstick[phil]);
      sem_post(&room);
}

void eat(int phil)
{
      printf("\nPhilosopher %d is eating", phil);
}