#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{


char* test ;
test = (char*)malloc(sizeof(char)*50);
strcpy(test, command);

int testlen = strlen(test)-1;



int commandlen;    
int i=0;
int j=0;
int k=0;
*argv = (char**)malloc(sizeof(char*)*50);


char* del1 = " ";
char* del2 = "\t";
char* del3 = "\n";
char* del4 = "\0";
int check=0;


commandlen = strlen(test)-1;


for(i=j ; i< commandlen ; i++)
{



	if(test[i]==*del1 ||test[i]==*del2 || test[i]==*del3 ||test[i]==*del4)
	{
	 if(!check)
        {
                j++;
                continue;
        }



			
 	       	 test[i] = '\0';
	
 		(*argv)[k]=(char*)malloc(sizeof(char)*50);

	         strcpy((*argv)[k], &test[j]);
		 j= i+1;
	 	 k++;
                 if(test[i-1]=='\0')
			k--;
		



	}
	check=1;

	if(i == (commandlen)-1){
		if(test[i+1]=='\n')
		{
			test[i+1]='\0';
		}
	
		(*argv)[k]=(char*)malloc(sizeof(char)*50);
		
		strcpy((*argv)[k],&test[j]);
	}

}
if(!check)
{

  (*argv)[k]=(char*)malloc(sizeof(char)*50);
                strcpy((*argv)[k],"\0");


}





*argc=k+1;



}
