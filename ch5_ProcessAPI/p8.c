#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>



int main (int argc, char *argv[]){

int fd[2]; // decays to fd[0]
pid_t c1pid;
pid_t c2pid;
// int file = open(stderr, "child1 PID: %d",c1pid);
int rc1 = fork();
int rc2 = fork();

	if (rc1 < 0) {
		exit(1);
	} else if (rc1 == 0) {
        c1pid = (int) getpid();
        close(fd[0]);
        waitpid(c2pid, NULL, 0);
        write(fd[1], &c2pid, sizeof(c2pid));
        printf("hello from child1\n");
    } else if (rc2 == 0) {
        c2pid = (int) getpid();
		close(fd[1]);
        char buf[1000];
        read(STDIN_FILENO, buf, 1000);
        printf("child1 pid: %d, msg: %s\n", c1pid, buf);
	} else {
		printf("parent (pid:%d)\n", (int) getpid());
	}
    
    
    return 0;
}