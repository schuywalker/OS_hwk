#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>



int main (int argc, char *argv[]){
// https://linux.die.net/man/3/execvpe
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("child\n");
	} else {
        printf("parent\n");

        // EXECLE
        // char *binaryPath = "/bin/bash";
        // char *arg1 = "-c";
        // char *arg2 = "echo \"Visit $HOSTNAMEXYZ:$PORT from your browser.\"\nenv";
        // char *const env[] = {"HOSTNAMEXYZ=www.soundcloud.com", "PORT=8080", NULL}; 
        // execle(binaryPath, binaryPath, arg1, arg2, NULL, env);
        char *args[]={"/bin/ls",NULL};
        execv(args[0],args); // good
    }

    

    
    // char *args[]={"/bin/ls",NULL};
    // execl(args[0],args); // good
    
    
    char *args[]={"/ls",NULL};
    // execlp(args[0],args[0],"-lh","/home",args); // doesnt work yet
    // execv(args[0],args); // good
     
    // execvpe(args[0],args);
    // execvp(args[0],args);
    
    
	return 0;
}
