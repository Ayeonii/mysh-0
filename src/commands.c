#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "commands.h"
#include <string.h>
int do_cd(int argc, char** argv) {
char buffer[255];
  if (!validate_cd_argv(argc, argv))
    return -1;

 else{

   return 0;
}

}

int do_pwd(int argc, char** argv) {
char buffer[256];
  if (!validate_pwd_argv(argc, argv))
    return -1;

  else
 {
	getcwd(buffer,256);
	printf("%s\n",buffer);
	

  return 0;
 }
}

int validate_cd_argv(int argc, char** argv) {

if(strcmp(argv[1],".")==0){
     	if(argc>2){
		if(strcmp(argv[2],".")==0)
			return 0;
	
	}
	return 1;
	}

if (chdir(argv[1])!=0)

	return 0;



if(argc==1)
	return 0;

if(strcmp(argv[0],"cd")!=0)
	return 0;
 

  return 1;
}

int validate_pwd_argv(int argc, char** argv) {
  if(argc != 1)
	return 0;

  if(strncmp(argv[0],"pwd",3)==0)
	return 1;
  else 
	return 0;
  
  
return 1;
}
