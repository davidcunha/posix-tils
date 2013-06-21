
/* POSIX shared-memory IPC */

#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main()
{
/* the id for the shared memory segment */
int segment_id;
/* pointer to the shared memory segment */
char *shared_memory;
/* the size (bytes) of the shared memory segment */
const int size = 4096;

  /* allocate memory segment for further sharing */
  segment_id = shmget(IPC_PRIVATE, size, S_IRUSR | S_IWUSR);
  /* attach to the shared memory segment */
  shared_memory = (char *) shmat(segment_id, NULL, 0);
  /* write message to memory */
  sprintf(shared_memory, "Hi there!");
  /* print message from memory */
  printf("*%s\n", shared_memory);
  /* detach from the shared memory segment */
  shmdt(shared_memory);
  /* remove the shared memory segment */ 
  shmctl(segment_id, IPC_RMID, NULL);
  
  return 0;
}
