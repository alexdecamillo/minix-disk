#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minix.h"
#include "modules.c"

int fd;

void runCommand(char c[]);

int main(int argc, char *argv[]){

    int i;
    char prompt[] = "Minix Console$ ";
    char *input = malloc(50), *token, *delim=" ", *buffer;

    // initialize the command pointers
    char **command = (char**)malloc(2*sizeof(char*));
    for(i = 0; i < 2; i++)
        command[i] = (char *)malloc(50*sizeof(char *));

    // the main loop for the minix console
    while (1) {
        printf("%s", prompt);
        scanf("%s", input);

        buffer = strdup(input);

        while ( (token = strsep(&buffer, delim)) != NULL ) {
            command[i] = token;
            //printf("%s\n", command[i]);
        }
        runCommand(input);
    }

    /*
    int fd = open("./imagefile.img", O_RDWR);
    char *buffer = malloc(sizeof(struct minix_super_block));
    size_t bytesToRead = 1024;
    ssize_t pos = 0;
    SUPER_BLOCK *sb = malloc(sizeof(SUPER_BLOCK));

    if(lseek(fd, 1024, SEEK_SET) < 0) return 1;

    pos = read(fd, sb, sizeof(SUPER_BLOCK));
    printf("%ld\n", pos);
    */
}

// need to get the argument parser working better before this works fully
void runCommand(char c[]){

    if (strcmp(c, "quit") == 0){
        exit(1);
    } else if(strcmp(c, "help")) {
        // display help information
    } else if(strcmp(c, "minimount")) {
        // runs open(filename, O_RDWR) and returns the file descriptor
    } else if(strcmp(c, "miniumount")) {
        // run close(fd) to close the file descriptor
    } else {
        // check if we have a valid file descriptor to use and send
        // and error back if not
    }

    if(strcmp(c, "showsuper")) {
        // read in the block data starting at block 1024 and format/display the
        // appropiate info
    } else if(strcmp(c, "traverse")) {

    } else if(strcmp(c, "showzone")) {

    } else if(strcmp(c, "showfile")) {

    } else {
        // send an error for not passing a vaild command
    }
}
