#include<stdio.h>

int main(void){
   
   int coin;
   int kinds;
   
   scanf("%d%d",&kinds,&coin);
   
   int kind[kinds];
   
   for(int i=0; i<kinds; i++)
      scanf("%d", &kind[i]);
   
   int Minimum_coin=0;
   
   for(int i=kinds-1; i>=0; i--){
      Minimum_coin = Minimum_coin + coin/kind[i];
      coin = coin % kind[i];
   }
      printf("%d", Minimum_coin);
   return 0;
   
}