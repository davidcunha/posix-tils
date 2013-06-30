
/* POSIX pthreads summation */

#include <pthread.h>
#include <stdio.h>

int sum; /* sum total shared by the threads */
void *runner(void *param); /* thread */

int main(int argc, char *argv[])
{
}