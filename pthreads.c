
/* POSIX pthreads summation */

#include <pthread.h>
#include <stdio.h>

int sum; /* sum total shared by the threads */
void *runner(void *param); /* thread */

int main(int argc, char *argv[])
{
  pthread_t tid; /* thread identifier */
  pthread_attr_t attr; /* thread attributes */

  if (argc != 2) {
    fprintf(stderr, "usage: a.out <integer value>\n");
    return -1;
  }
  if(atoi(argv[1] < 0)) {
    fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
    return -1;
  }

  /* get the default attributes */
  pthread_attr_init(&attr);
  /* create the thread */
  pthread_create(&tid,&attr,runner,argv[1]);
  /* wait for the thread to exit */
  pthread_join(tid,NULL);

  printf("total = %d\n", sum);
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