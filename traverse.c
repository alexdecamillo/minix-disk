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
