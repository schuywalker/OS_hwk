#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include "stat.h"

// if using option and path, it's currently only working with option before path.

int main(int argc, char *argv[]) {
    const char option[] = "-l";
    int opt;
    int listOptionBool = 0;
    DIR* dir; // directory which we'll be reading from
    struct dirent *entry; // pointer to a given directory entry (file or directory)
    assert(argc <= 3); // program name, directory, and optional -l
    char *pathName = NULL;


    if (argc == 1) { // no directory and no option
        dir = opendir(".");
        assert(dir != NULL);
        while ((entry = readdir(dir)) != NULL) {
            printf("%s\n", entry->d_name);
        }   
        return 0;     
    }

    


    // if (strcmp(argv[2], option) == 0 || argc == 3) {
    //     listOptionBool = 1;
    //     printf("listOption: %d", listOptionBool);
    // }

     // establish if -l option is present
    while ((opt = getopt(argc, argv, ":if:l")) != -1) {
        switch(opt) {
            case 'l':
                printf("opt %d",opt);
                listOptionBool = 1;
                break;
        }
        // printf("\nlistOptionBool\n: %d", listOptionBool);
    }


    if (listOptionBool == 0) { // directory given but no option
        assert(argc == 2);
        dir = opendir(pathName = argv[1]);
        assert(dir != NULL);
        ;
        while ((entry = readdir(dir)) != NULL) // each call of readdir moves the pointer to the next entry
        { 
            printf("%s\n", entry->d_name);
        }
    } else if (listOptionBool == 1 && argc == 2) { // option but no directory
        
        dir = opendir(".");
        assert(dir != NULL);
        while ((entry = readdir(dir)) != NULL) {
            printf("%s\n", entry->d_name);
            printFileStats(entry->d_name, pathName);
        }   
    } else { // directory and option
        assert(argc == 3);
        char *option = "-l";
        pathName = (strcmp(argv[2], option) != 0) ? argv[2] : argv[1]; // if 2nd arg not -l, then it must be path
        dir = opendir(pathName);
        assert(dir != NULL);
        while ((entry = readdir(dir)) != NULL) {
            printf(" stat stat stat from OVER THEREEEE %s\n", entry->d_name);
        }    
    } 


    printf("\n\npathName: %s", (dir != NULL) ? pathName : ".");

    return 0;
    

    int i = 1;
    assert(i == 1);
    

    if (argc == 1) {
        // printing cwd
    }

    printf("\n argc = %d\n",argc);
    
    if (listOptionBool > 0) {
        printf("-l");
    }
    else {
        printf("no option right...");
    }




    return 0;
}

// List Files: Write a program that lists files in the given directory.
// When called without any arguments, the program should just print
// the file names. When invoked with the -l flag, the program should
// print out information about each file, such as the owner, group, permissions, and other information obtained from the stat() system
// call. The program should take one additional argument, which is
// the directory to read, e.g., myls -l directory. If no directory is
// given, the program should just use the current working directory.
// Useful interfaces: stat(), opendir(), readdir(), getcwd().


