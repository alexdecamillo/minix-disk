int minimount(char *filename){
    return open(filename, O_RDWR);
}
