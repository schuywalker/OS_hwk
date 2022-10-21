#include <stdlib.h>
#include <stdio.h>

int main (int argc, int *argv[]) {

    int *data = (int*)malloc(10);
    // free(data);  
    int *a;
    *a = 4;
    data[6] = *a;
    free(a);  
    
    // *a = 6;

    // for (int i = 0; i < 10; i++) {
    //     printf("%d",data[i]);
    // }
    // data[0] = 10;
    // *data = 10;

    return 0;
}