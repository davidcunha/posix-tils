
/* POSIX pthreads scheduling */

#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 5

int sum; /* sum total shared by the threads */
void *runner(void *param); /* thread */

int main(int argc, char *argv[])
{
  int i, policy;
  pthread_t tid[NUM_THREADS]; /* thread identifier */
  pthread_attr_t attr; /* thread attributes */
  
  /* get the default attributes */
  pthread_attr_init(&attr);

  /* get the current scheduling policy */
  if (pthread_attr_getschedpolicy(&attr,&policy) != 0)
    fprintf(stderr, "Unable to get policy.\n");
  else {
    if (policy == SCHED_OTHER)
      printf("SCHED_OTHER\n");
    else if (policy == SCHED_RR)
      printf("SCHED_OTHER\n");
    else if (policy == SCHED_FIFO)
      printf("SCHED_FIFO\n");
  }
  
  /* set the scheduling policy - FIFO, RR, or OTHER */
  if (pthread_attr_setschedpolicy(&attr, SCHED_OTHER) != 0)
    printf("unable to set scheduling policy to SCHED_OTHER \n");

  /* create the threads */
  for(i = 0; i < NUM_THREADS; i++)
    pthread_create(&tid[i],&attr,runner,NULL);

  /* join each thread */
  for(i = 0; i < NUM_THREADS; i++)
    pthread_join(tid[i],NULL);
}

void *runner(void *param)
{
  int i, upper = atoi(param);
  sum = 0;

  if (upper > 0) {
    for (i = 1; i <= upper; i++) {
      sum +=1;
    }
  }

  pthread_exit(0);
}
