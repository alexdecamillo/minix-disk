#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "minix.h"
#include "modules.c"

int *fd;

void runCommand(char *c[], int len);

int main(int argc, char *argv[]){

    int commandLength;
    fd = malloc(sizeof(int));
    char prompt[] = "Minix Console$ ";
    char *input = malloc(50), *token, *delim=" ", *buffer;

    // initialize the command pointers
    char **command = (char**)malloc(2*sizeof(char*));
    for(int i = 0; i < 2; i++)
        command[i] = (char *)malloc(50*sizeof(char *));

    // the main loop for the minix console
    while (1) {
        // prompt and get input
        printf("%s", prompt);
        fgets(input, 50, stdin);

        // use buffer string and reset commandLength
        buffer = strdup(input);
        commandLength = 0;

        // parse the input by ' ' into an array
        while ( (token = strsep(&buffer, delim)) != NULL ) {
            if (token[strlen(token)-1] == '\n')
                token[strlen(token)-1] = '\0';
            command[commandLength] = token;
            commandLength++;
        }

        runCommand(command, commandLength);
    }

}

// takes the command array and the length of the array and calls the
//  appropiate module from modules.c
void runCommand(char *c[], int len){

    if (strcmp(c[0], "quit") == 0) {
        exit(1);
    } else if(strcmp(c[0], "help") == 0) {
        helpInfo();

    } else if(strcmp(c[0], "minimount") == 0) {
        if(len >= 2)
            minimount(fd, c[1]);
        else {
            char *error = "ERROR: You must specify an image to mount\n";
            write(2, error, strlen(error));
        }

    } else if(strcmp(c[0], "miniumount") == 0) {
        miniumount(*fd);

    } else if(strcmp(c[0], "showsuper") == 0) {
        if (*fd < 3) { noMount(); return; }
        superblock(*fd);

    } else if(strcmp(c[0], "traverse") == 0) {
        if (*fd < 3) { noMount(); return; }
        traverse(^fd);

    } else if(strcmp(c[0], "showzone") == 0) {
        if (*fd < 3) { noMount(); return; }
        if(len >= 2) {
            int zone = (int) strtol(c[1], (char **)NULL, 10);
            showZone(*fd, zone);
        } else {
            char *error = "ERROR: You must specify a zone to show\n";
            write(2, error, strlen(error));
        }

    } else if(strcmp(c[0], "showfile") == 0) {
        if (*fd < 3) { noMount(); return; }
        showFile(*fd, c[1]);

    } else {
        char *error = malloc(100);
        strcat(error, c[0]);
        strcat(error, ": command not found. Use the command 'help' for a list of valid commands\n");
        write(2, error, strlen(error));
    }
}
