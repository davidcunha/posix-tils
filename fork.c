
/* POSIX fork/exec process */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
  pid_t pid;

	/* fork a child process */
	pid = fork();

	if (pid < 0) { /* error */
		fprintf(stderr, "Fork Failed\n");
	}
	else if (pid == 0) { /* child process */
		printf("I am the child with pid:%d\n",pid);
		printf("exec system call:\n");
		execlp("/bin/ls","ls",NULL);
	}
	else { /* parent process */
		/* parent will wait for the child to complete */
		printf("I am the parent with pid:%d\n",pid);
		wait(NULL);
		
		printf("end\n");
	}
}
