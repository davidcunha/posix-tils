
/* POSIX pipe between processes */

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void)
{
  char write_msg[BUFFER_SIZE] = "Hello Child!";
  char read_msg[BUFFER_SIZE];
  int fd[2];
  pid_t pid;

  /* create pipe */
  if (pipe(fd) == -1) {
    fprintf(stderr, "Pipe failed\n");
    return 1;
  }

  /* fork a child process */
  pid = fork();

	if (pid < 0) { /* error */
		fprintf(stderr, "Fork Failed\n");
	} else if (pid == 0) { /* child process */
		/* close unused end of the pipe */
		close(fd[WRITE_END]);
		
		/* read from the pipe */
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		printf("child reads %s\n", read_msg);
		
		/* close the write end of the pipe */
		close(fd[READ_END]);
		
	} else { /* parent process */
		/* close unused end of the pipe */
		close(fd[READ_END]);
		
		/* write to the pipe */
		write(fd[WRITE_END], write_msg, strlen(write_msg)+1);
		
		/* close the write end of the pipe */
		close(fd[WRITE_END]);
	}

  return 0;
}
