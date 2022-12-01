#ifndef HEADER_FILE
#define HEADER_FILE

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int printFileStats(char *fileName, char *filePath){

    struct stat fileStat;

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
    printf("Last Modified: %lld\n", (long long)&fileStat.st_mtimespec.tv_sec);
    printf("Last Changed: %lld\n", (long long) &fileStat.st_ctimespec.tv_sec);
    printf("Birth: %lld\n", (long long) &fileStat.st_birthtimespec.tv_sec);

    return 0;
}

#endif