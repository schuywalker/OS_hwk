#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main (int argc, char *argv[]){

	int x = 100;

	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("hello, I am child (pid:%d)\n", (int) getpid());
		printf("child: x = %d\n", x);
		x--;
		printf("child: now, x = %d and which should be 99\n",x);
	} else {
		x--;
		printf("parent (pid:%d): x = %d which should be 99\n", (int) getpid(), x);
	}

	return 0;
}
