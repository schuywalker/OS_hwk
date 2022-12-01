#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

// to do - ask Dan about the mallocing at the start of the program for better performance.

// 1. Stat: Write your own version of the command line program stat,
// which simply calls the stat() system call on a given file or directory. 
// Print out file size, --------
// number of blocks allocated, 
// reference
// (link) count, 
// and so forth. What is the link count of a directory, as
// the number of entries in the directory changes? Useful interfaces:
// stat(), naturally.

struct stat fileStat;

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
            printf("Usage: %s <file name>\nPlease use first arg for fileName and optional second arg for path", argv[0]);
            return -1;
    }

    char *fileName = argv[1];
    // printf("fileName: %s", fileName);
    char *path = NULL;
    if (argc == 3) {
        path = argv[2];
        // printf("path: %s", path);
    }
    int ret = stat(fileName, &fileStat);
    if (ret == -1) {
        printf("Error: stat() failed for file: %s \t return code: %d", fileName, ret);
    }

    printf("\nFile Name: \"%s\"\n", fileName); 
    printf("File Size in bytes:  %lld\n", fileStat.st_size);
    printf("File Mode: %s,  User:\n", (fileStat.st_mode & S_IRUSR) ? "d" : "-"); // u g o
    printf("File Mode: %hu\n", fileStat.st_mode);
    printf("Inode Number: %llu\n", fileStat.st_ino);
    printf("Blocks allocated to this file: %lld\n", fileStat.st_blocks); 
    printf("File Device: %d\n", fileStat.st_dev); 
    printf("Number of Links: %hu\n", fileStat.st_nlink);
    
    
    // time(&fileStat.st_atimespec);
    // char buffer [80];
    // struct tm * time = localtime(&fileStat.st_atimespec);
    // strftime(buffer, 80, "%x - %I:%M%p", time);
    
    printf("Last Accessed: %lld\n", (long long) &fileStat.st_atimespec.tv_sec);
    printf("Last Modified: %ld\n", fileStat.st_mtimespec);
    printf("Last Changed: %ld\n", fileStat.st_ctimespec);
    printf("Birth: %lld\n", fileStat.st_birthtimespec);


    

    return 0;
}

void hello() {
    printf("hello");
}