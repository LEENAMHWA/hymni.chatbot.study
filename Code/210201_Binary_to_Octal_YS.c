#include <stdio.h>
static char BinaryNumber[10000000];
#define SQUARE 1
#define POW_SQUARE 2
#define DOUBLE_POW_SQUARE 4
int main(void){
   
   scanf("%s", &BinaryNumber);
   
   int length = sizeof(BinaryNumber)/sizeof(BinaryNumber[0]);
   
   if(length % 3 ==1){
      printf("%d", BinaryNumber[0] - '0');
   }else if(length % 3 ==2){
      printf("%d", (BinaryNumber[0] - '0') * POW_SQUARE + (BinaryNumber[1] - '0'));
   }
   
   int budle_of_three;
   
   budle_of_three = length % 3 ;
   
   for(int i = budle_of_three; i < length; i+=3){
      printf("%d", (BinaryNumber[i] - '0') * DOUBLE_POW_SQUARE + (BinaryNumber[i+1] - '0') *POW_SQUARE + (BinaryNumber[i+2] -'0'));
   }
   
   return 0;
}