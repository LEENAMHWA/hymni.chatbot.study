#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static char seps[] = "-+";
static char minus[] = "-";

int transforInt(char *arr);

int transforInt(char *arr){

	int cal=0;
	
	char *token1;
	token1 = strtok(arr,seps);
	
	while(token1 !=NULL){
		cal += atoi(token1);
		token1 = strtok(NULL, seps);
	}
	
	return cal;
}
int main(void){

   char number[51] = {0,};   
   scanf("%s", number);
   
   char *token;
   token = strtok(number, minus);
   
   char copy[51] = {0,};
   strcpy(copy,token);  
  
   
   token = strtok(NULL,"");

   int output =0;
   output=transforInt(copy);

   if(token != NULL)
	   output = output - transforInt(token);
   
   printf("%d", output);
   return 0;
   
   //  char *token1;
 //  token1 = strtok(copy,seps);
 
  /*  while(token1 !=NULL){
	   output = ouput + atoi(token1);
	   token1 = strtok(NULL,seps);
   }
   */
 /*  int output1 = 0;
  
   while(token !=NULL)){
	   
		output1 = output1 + atoi(token)
   }
   int result;
   result = ouput - ouput1;
   
   printf("%d", result);
   */
}