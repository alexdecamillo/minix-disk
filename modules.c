// tries to open filename and assign the file descriptor to fd
void minimount(int *fd, char *filename) {
    // if the file descriptor is at least 3, it has been assigned already
    if (*fd >= 3) {
        char *error = "ERROR: Please unmount the current image before mounting a new one\n";
        write(2, error, strlen(error));
        free(error);
    } else {
        *fd = open(filename, O_RDWR);
        if (*fd < 3) {
            char *error = malloc(100);
            strcat(error, "ERROR: No valid file '");
            strcat(error, filename);
            strcat(error, "' for argument IMAGE_NAME in command 'minimount'\n");
            write(2, error, strlen(error));
            free(error);
        } else {
            char *response = "Image sucessfully mounted\n";
            write(0, response, strlen(response));
            free(response);
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
            free(response);
        } else {
            char *error = "ERROR: There was a problem unmounting the image\n";
            write(2, error, strlen(error));
            free(error);
        }
    } else {
        char *error = "ERROR: There is no mounted image to unmount\n";
        write(2, error, strlen(error));
        free(error);
    }
}

// prints an error if commands that require a mounted image are called without a
//  mounted image
void noMount() {
    char *error = "ERROR: You must mount a valid image file before using this command\n";
    write(2, error, strlen(error));
    free(error);
}

// prints the contents of the super block
void superblock(int fd) {
    // try to move the offset to the beginning of the super block
    if(lseek(fd, 1024, SEEK_SET) < 0) {
        char *error = "ERROR: There was an problem retrieving the super block\n";
        write(2, error, strlen(error));
        free(error);
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
        printf("%s%d\n", "zones:                  ", sb->s_zones);
    }
}

void helpInfo() {
    // print the information regarding possible commands
}
