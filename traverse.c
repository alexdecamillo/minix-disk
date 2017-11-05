#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>

 
void traverse(char *);
main  (){
	//if (argc==1)
		traverse(".");
	/*else
		while (--argc){
			printf("%s:\n", *++argv);
			traverse( *argv );
		}*/
	return 0;
}
 
void traverse( int fd ){

  char *buf = (char *)  calloc(1024,1);
  struct minix_dir_entry *direntp;


  //fd=open(fd, O_RDONLY);
 
  lseek(fd, 1024*4, SEEK_SET); //pointed to root dir
  read(fd, buf, 32);
    struct minix_inode *rootInode=(struct minix_inode *) buf;
  free(buf);
  buf=(char*) calloc(16,1);
  char *name= (char *) calloc(100,1);
  int i, j;
  for (i=0; i<7 ; i++){//loop through the first 7 zones (all zones)
    for(j=0 ; j<1024 ; j=j+16){ //loop through every two bytes
      if ((rootInode->i_zone[i]) == '\0')
        //goto Label;
      else;
        lseek(fd, (rootInode->i_zone[i] * 1024) + j, SEEK_SET); 
      read(fd, buf, 16);
      if(strlen(buf)>0){
        direntp = (struct minix_dir_entry *) buf;
        if (strcmp(direntp->name, ".") !=0 && strcmp(direntp->name, "..") !=0){
          
          name=direntp->name;
          write(1, name, strlen(name));
          write(1, "\n", 1);
          //printf("%s\n", name);
        //}
      }
    }   
  }
  
  close(fd);
}
LongList(char *fname, struct stat *buf, char array[]){
  DIR *dir_ptr;
  struct dirent *direntp;

  if ( (dir_ptr=opendir(dirname))==NULL){
    printf("Cannot open %s\n", dirname);
  }else{
    int i =0;
    while( (direntp=readdir(dir_ptr)) != NULL){
      array[i]= direntp->d_name; //to store file names
			permissionBits(buf->st_mode);
        prinf("  %s    %d     %d     %X     %s", buf->st_mode, buf->st_uid ,buf->st_size, buf->mtime, array[i]);
      i++;
    }
    closedir(dir_ptr);
  }
}
void permissionBits(int bits){
	char binaryString[16];
	char permissionSrting[16]; //array to store translated permissionBits
	int i=0;
	for(i=0; i<=15 ; i++){
		binaryString[i] = (bits&1)+'0';//read every byte into an array
		bits>>=1;
	}
	//checks the file types
	if (binaryString[0] == '1'){ //it's regular file
		permissionSrting[0] = "-" ;
	}else{ if (binaryString[1] == '1'){//it's a directory
		permissionSrting[0] = "d" ;
	}
  }
	//checks the 9 permission bits (rwx)
	for (i=0; i<9 ; i++){
		if (binaryString[(i+3)+"0"] == '1') //r__
			permissionSrting[(i+3)+"0"]="r";
		else
			permissionSrting[(i+3)+"0"]="-";
		if (binaryString[(i+3)+"1"] == '1') //-w-
			permissionSrting[(i+3)+"1"]="w";
	 	else
			permissionSrting[(i+3)+"1"]="-";
		if (binaryString[(i+3)+"2"] == '1') //--x
			permissionSrting[(i+3)+"2"]="x";
		else
			permissionSrting[(i+3)+"2"]="-";
	}
	printPermBits(permissionString);
}
void printPermBits(char a[]){
	for (i=0; i<a.Length ; i++){
		printf("%s\n", a[i]);
	}
}

