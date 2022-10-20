#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

 void sig_handler(int signum){
        printf("Inside handler function\n");
    }

int main (int argc, char *argv[]){

    int parentPID = (int)getpid();
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("hello\n");
		// signal(SIGCONT,sig_handler);        
        // kill (parents pid, SIGCONT)
        // man 2 kill, man 2 pause
        kill(parentPID, SIGCONT);
        // sleep is not correct answer because you haven't 
        // made causal relationship between parent and child, 
        // you're just hoping timing works out. this can cause bugs when you 
        // run a program in a different environment or a vm, etc.
    } else {
        pause(); // reason this works alone is because when child dies is sends SIGCHLD to parent.
        printf("goodbye\n");
	}

	return 0;
}
