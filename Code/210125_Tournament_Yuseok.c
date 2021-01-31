#include <stdio.h>
int Count(int Jimin, int Hansu);

int Count(int Jimin, int Hansu){

  int k=0;
  
  while(1){		
	Jimin = (Jimin +1) / 2; 
	Hansu = (Hansu +1) / 2;
	k++;
	if(Jimin == Hansu)
		break;			
  }
	return k;
}
int main(void){

	int n;
	int jimin, hansu;
	
	while(1){
		scanf("%d", &n);
	if(n<=100000){
		break;
	}else
		{
	  scanf("%d", &n);
		}
	}
	
	scanf("%d %d", &jimin, &hansu);
	
	int fight;
	fight = Count(jimin, hansu);
	printf("%d", fight);
	return 0;
}