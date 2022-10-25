#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

;

int main(int argc, char *argv[]) {

    int infinite = 0; // false

    if (argc < 2) {
        printf("please rerun with:\nfirst argument as bytes to be allocated and\nthe second arg is optional, and functions as the number of times to loop through the allocated memory.\n");
        exit(-1);
    } else if (argc == 2) {
        printf("ctrl to stop program\n");
        infinite = 1; // true
    }

    int number_of_bytes = atoi(argv[1]);
    char *bytes = malloc(sizeof(char) * (number_of_bytes));
    
    if (infinite) {
        printf("number of bytes: %d  loops: infinite\n",number_of_bytes);
        int i = 0;
        while (1) {
        for (int j = 0; j < number_of_bytes; j++) {
            bytes[i] = ((i+65)%122); // A = 65, z = 122
            printf("%c  ",bytes[i]);
        }
        i++;
        printf("\n");
    }
    } else {    
        int loops = atoi(argv[2]); 
        printf("number of bytes: %d  loops: %d\n",number_of_bytes,loops);
        int i = 0;  
        while (i < loops) {
            for (int j = 0; j < number_of_bytes; j++) {
            bytes[i] = ((i+65)%122); // A = 65, z = 122
            printf("%c  ",bytes[i]);
                printf("%c  ",bytes[i]);
            
            }
            printf("\n");
            i++;
        }   
    }
    return 0;
}