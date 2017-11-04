// tries to open filename and assign the file descriptor to fd
void minimount(int *fd, char *filename) {
    // if the file descriptor is at least 3, it has been assigned already
    if (*fd >= 3) {
        char *error = "ERROR: Please unmount the current image before mounting a new one\n";
        write(2, error, strlen(error));
    } else {
        *fd = open(filename, O_RDWR);
        if (*fd < 3) {
            char *error = malloc(100);
            strcat(error, "ERROR: No valid file '");
            strcat(error, filename);
            strcat(error, "' for argument IMAGE_NAME in command 'minimount'\n");
            write(2, error, strlen(error));
        } else {
            char *response = "Image sucessfully mounted\n";
            write(0, response, strlen(response));
        }
    }
}

// closes the passed file descriptor if it is opened
void miniumount(int fd) {
    // if the file descriptor isn't at least 3, there's nothing to unmount
    if (fd >= 3) {
        int umount = close(fd);
        if (umount == 0) {
            fd = -1;
            char *response = "Image sucessfully unmounted\n";
            write(0, response, strlen(response));
        } else {
            char *error = "ERROR: There was a problem unmounting the image\n";
            write(2, error, strlen(error));
        }
    } else {
        char *error = "ERROR: There is no mounted image to unmount\n";
        write(2, error, strlen(error));
    }
}

// prints an error if commands that require a mounted image are called without a
//  mounted image
void noMount() {
    char *error = "ERROR: You must mount a valid image file before using this command\n";
    write(2, error, strlen(error));
}

// prints the contents of the super block
void superblock(int fd) {
    // try to move the offset to the beginning of the super block
    if(lseek(fd, 1024, SEEK_SET) < 0) {
        char *error = "ERROR: There was an problem retrieving the super block\n";
        write(2, error, strlen(error));
    } else {
        struct minix_super_block *sb = malloc(sizeof(SUPER_BLOCK));
        ssize_t pos = read(fd, sb, sizeof(SUPER_BLOCK));
        printf("%s%d\n", "number of inodes:       ", sb->s_ninodes);
        printf("%s%d\n", "number of zones:        ", sb->s_nzones);
        printf("%s%d\n", "number of imap_blocks:  ", sb->s_imap_blocks);
        printf("%s%d\n", "number of zmap_blocks:  ", sb->s_zmap_blocks);
        printf("%s%d\n", "first data zone:        ", sb->s_firstdatazone);
        printf("%s%d\n", "log zone size: 	        ", sb->s_log_zone_size);
        printf("%s%d\n", "max size: 	        ", sb->s_max_size);
        printf("%s%d\n", "magic: 	                ", sb->s_magic);
        printf("%s%d\n", "state:                  ", sb->s_state);
        printf("%s%d\n\n", "zones:                  ", sb->s_zones);
    }
}

void helpInfo() {
  printf("\n-------------- COMMANDS --------------\n\n");

  printf("  minimount\n");
  printf("    DESCRIPTION:     Mount a local minix disk.\n");
  printf("    USAGE:           minimount <imagefile.img>\n");

  printf("  miniumount\n");
  printf("    DESCRIPTION:     Unmounts the mounted minix disk.\n");
  printf("    USAGE:           miniumount\n");

  printf("  showsuper\n");
  printf("    DESCRIPTION:     Lists the information of the super block\n");
  printf("    USAGE:           showsuper\n");

  printf("  traverse\n");
  printf("    DESCRIPTION:     Lists the contents of the root directory, and prints detailed information if [-l] is on.\n");
  printf("    USAGE:           traverse, traverse -l\n");

  printf("  showzone\n");
  printf("    DESCRIPTION:     Show the ASCII content of a specified zone number.\n");
  printf("    USAGE:           showzone <zonenumber>\n");

  printf("  help\n");
  printf("    DESCRIPTION:     Displays all available commands.\n");
  printf("    USGAE:           help\n");

  printf("  showfile\n");
  printf("    DESCRPTION:     Show the contents of a file.\n");
  printf("    USAGE:          showfile <filename>\n");

  printf("  quit\n");
  printf("    DESCRIPTION:     quits minix shell.\n");
  printf("    USAGE:           quit\n");
}

void showZone(int fd, int zone) {
    // try to move the offset to the beginning of the zone
    if (lseek(fd, 1024*zone, SEEK_SET) < 0) {
        char *error = "ERROR: There was an problem retrieving zone information\n";
        write(2, error, strlen(error));
    } else {
        printf("%s\n","      0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f");
        char *buf = malloc(sizeof(char*));
        int hex = 0;
        while (read(fd, buf, 1) > 0 && hex < 1024) {
            // print the hex number for this row every 16 bytes
            if(hex%16 == 0) {
                // conditional formatting of spaces before hex number
                if (hex < 16)
                    printf("\n   %x  ", hex);
                else if (hex < 256)
                    printf("\n  %x  ", hex);
                else
                    printf("\n %x  ", hex);
            }

            // only print the readable ASCII data
            if (isprint(*buf))
                printf("%s  ", buf);
            else
                printf("   ");

            hex++;
        }
        printf("\n");
    }
}

void showFile(int fd, char* filename) {
    int iNum = 0;
    int found = 0;
    int bytesRead = 0;
    // move offset to root directory
    if(lseek(fd, 1024*5, SEEK_SET) < 0) {
        char *error = "ERROR: There was an issue finding the root directory\n";
        write(2, error, strlen(error));
    } else {
        struct minix_inode *rootNode = malloc(sizeof(INODE));
        struct minix_dir_entry *entry = malloc(sizeof(DIR_ENTRY));
        read(fd, rootNode, sizeof(INODE));

        for (short i=0; i < 6; i++) {
            bytesRead = 0;
            if (rootNode->i_zone[i] == '\0') {
                char *error = malloc(20);
                continue;
            }

            lseek(fd, rootNode->i_zone[i]*1024, SEEK_SET);

            // loop through each directory entry by reading in data as a DIR_ENTRY struct
            while ((bytesRead += read(fd, entry, 16)) <= 1024 ) {
                // check the name in the DIR_ENTRY against the filename passed in
                if (strcmp(entry->name, filename) == 0) {
                    // if it matches, note the inode number
                    iNum = entry->inode;
                    found = 1;
                    break;
                }
            }
            if(found) break;
        }

        // check if we found the file
        if (!found) {
            char *error = "ERROR: The requested file could not be found in the root directory\n";
            write(2, error, strlen(error));
        } else {

            // move to the inode block with the file data
            if (lseek(fd, ((1024*5)+((iNum-1)*sizeof(INODE))), SEEK_SET) < 0) {
                char *error = "ERROR: There was an issue finding the requested file\n";
                write(2, error, strlen(error));
            } else {
                // read in the inode
                struct minix_inode *inode = malloc(sizeof(INODE));
                if (read(fd, inode, sizeof(INODE)) != sizeof(INODE)) {
                    char *error = "ERROR: There was an issue reading the requested file\n";
                    write(2, error, strlen(error));
                } else {
                    // Cycle through data zones 1-7 (inode->i_zone[0] - inode->i_zone[6])
                    // and print of the data as a hexadecimal number
                    char *data = malloc(3);
                    bytesRead = 0;

                    for (int i=0; i < 7; i++) {
                        if (inode->i_zone[i] == '\0')
                            break;
                        lseek(fd, inode->i_zone[i]*1024, SEEK_SET);
                        printf("\n");
                        while ( (bytesRead += read(fd, data, 1)) <= 1024) {
                            // prints an empty space before hex num if only one
                            if (data[0] < 16)
                                printf("    %x", (unsigned int)data[0]);
                            else
                                printf("   %x", (unsigned int)data[0]);

                            // print a new line every 16 bytes
                            if (bytesRead%16 == 0)
                                printf("\n");
                        }
                    }
                }

            }
        }
    }

}
