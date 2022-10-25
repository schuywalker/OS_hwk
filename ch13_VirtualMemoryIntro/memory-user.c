#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("please rerun with:\nfirst argument as bytes to be allocated and\nthe second arg as the number of times to loop through the allocated memory.\n");
        exit(-1);
    }

    int number_of_bytes = atoi(argv[0]);
    int loops = atoi(argv[1]);

    fprintf("%d",loops);
    exit(0);



    fprintf("%d   %d\n",number_of_bytes,loops);
    
    char *bytes = malloc(sizeof(char*) * (number_of_bytes));

    int i = 0;
    // int j = 0;
    
while (i < loops) {
    for (int j = 0; j < number_of_bytes; j++) {
            if (i == 0) {
                bytes[i] = 'a';
                fprintf("%c  ",bytes[i]);
            }
            else {
                bytes[i] = 'b';
                fprintf("%c  ",bytes[i]);
            }
        }
        printf("\n");
        i++;
}
    // for (int i = 0; i < loops; i++) {
        
    // }

    printf("%d",bytes);

    return 0;
}