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
 
void traverse( char *dirname ){
  DIR *dir_ptr;
  struct dirent *direntp;
 
  if ( (dir_ptr=opendir(dirname))==NULL){
    printf("Cannot open %s\n", dirname);
  }else{
    while( (direntp=readdir(dir_ptr)) != NULL)
      printf("%s\n", direntp->d_name);
    
    closedir(dir_ptr);
  }
 
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

