// Compile with 
// gcc -o filename filename.c -lpthread -lrt 
// -pthread instead of -lpthread 
// From http://www.csc.villanova.edu/~mdamian/threads/posixsem.html#init
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define NITER 1000000

int cnt = 0;
sem_t mutex;

void * Count(void * a)
{
    int i, tmp;
	sem_wait (&mutex); // If the value of the semaphore is negative, the calling process blocks; one of the blocked processes wakes up when another process calls sem_post.
    for(i = 0; i < NITER; i++)
    {
        tmp = cnt;      /* copy the global cnt locally */
        tmp = tmp+1;    /* increment the local copy */
        cnt = tmp;      /* store the local value into the global cnt */ 
    }
	sem_post (&mutex); // It increments the value of the semaphore and wakes up a blocked process waiting on the semaphore, if any.

}

int main(int argc, char * argv[])
{
    pthread_t tid1, tid2;
	sem_init(&mutex, 0, 1); //semaphores start with a positive value x, meaning x more threads can run the critical section before waiting
	
    if(pthread_create(&tid1, NULL, Count, NULL))
    {
      printf("\n ERROR creating thread 1");
      exit(1);
    }

    if(pthread_create(&tid2, NULL, Count, NULL))
    {
      printf("\n ERROR creating thread 2");
      exit(1);
    }

    if(pthread_join(tid1, NULL))	/* wait for the thread 1 to finish */
    {
      printf("\n ERROR joining thread");
      exit(1);
    }

    if(pthread_join(tid2, NULL))        /* wait for the thread 2 to finish */
    {
      printf("\n ERROR joining thread");
      exit(1);
    }

    if (cnt < 2 * NITER) 
        printf("\n BOOM! cnt is [%d], should be %d\n", cnt, 2*NITER);
    else
        printf("\n OK! cnt is [%d]\n", cnt);
  
    pthread_exit(NULL);
}


