#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h> 
#include <sys/wait.h> 


int main (int argc, char *argv[]){
    int status;
	int rc1 = fork();
    int rc2 = fork();
	if (rc1 < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc1 == 0) {
		printf("child1 pid: %d\n", (int)getpid());
	}  else if (rc2 == 0) {
		printf("child2 pid: %d\n", (int)getpid());
	}  else {
        printf("parent pid: %d\n", (int)getpid());
        pid_t c_pid = waitpid(-1, &status, 0);
        printf("pid_t: %d\n",c_pid);
    }
        // P5
        // pid_t c_pid = wait(NULL);
        // printf("c_pid: %d, pid: %d\n", c_pid, (int)getpid());

    return 0;
    
}