#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
		int rc = fork();
		
		if (rc < 0) {
			fprintf(stderr, "fork failed\n");
			exit(1);
		} else if (rc == 0) {
			printf("hello, I am child (pid:%d)\n", (int) getpid());
			int fc = open("p2file", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);  
			write(fc, "child wins", strlen("child wins"));
			printf("fileInChild return value: %d\n",fc);	
		} else {
			printf("I'm parent, pid:%d\n", (int) getpid());
			int fp = open("p2file", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
			write(fp, "parent wins", strlen("parent wins"));
			printf("file in parent return value: %d\n",fp);	
		}

}
