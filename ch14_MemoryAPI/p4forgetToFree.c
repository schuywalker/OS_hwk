#include <stdlib.h>
#include <stdio.h>

char *p;

int main (int argc, int *argv[]) {

    p = (char*)malloc(3); 
    p[0] = 'a'; p[1] = 'b'; p[2] = 'c';
    printf("%c %c %c\n",p[0],p[1],p[2]);
    p = (char*)malloc(2);
    p[0] = 'd'; p[1] = 'e';
    printf("%c %c\n",p[0],p[1]);
    return 0;
}