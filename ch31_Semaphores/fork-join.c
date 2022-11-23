#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#include <stdlib.h>
// #include <semaphore.h>
#include "common_threads.h"
#include "common.h"

sem_t s; 

void *child(void *arg) {
    printf("child\n");
    // use semaphore here
    sleep(1);
    sem_post(&s);
    return NULL;
}

int main(int argc, char *argv[]) {
    
    
    pthread_t p;
    printf("parent: begin\n");
    
    // init semaphore here
    sem_init(&s, 0, 0);
    pthread_create(&p, NULL, child, NULL);
    // pthread_join(p, NULL);
    
    // use semaphore here
    sem_wait(&s);
    
    printf("parent: end\n");
    printf("\n%d", sem_getvalue(&s, NULL));
    return 0;
}

