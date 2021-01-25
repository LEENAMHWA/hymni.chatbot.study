#include <stdio.h>
#include <math.h>

#define LOG2(X) log(X)/log(2.0)
#define NOT_FIGHT -1

int Power(int x);

int main(){
	int participant, num1, num2;
	
	scanf("%d %d %d", &participant, &num1, &num2);
	if(participant<1 && participant>100000)
		return -1;
	if(num1>participant || num2>participant || num1==num2)
		return -1;	
	
	if(participant == 1){
		printf("%d", NOT_FIGHT);
		return 0;
	}
	
	int num1_round = (int) ceil( LOG2(num1) );
	int num2_round = (int) ceil( LOG2(num2) );
	
	while(num1_round == num2_round){
		num1 -= Power(num1_round-1);
		num2 -= Power(num2_round-1);		
		num1_round = (int) ceil( LOG2(num1) );
		num2_round = (int) ceil( LOG2(num2) );
	}

	if(num1_round > num2_round)
		printf("%d", num1_round);
	else
		printf("%d", num2_round);
	
    return 0;
}


int Power(int x){
	if(x == 0)
		return 1;
	
	return Power(x-1)*2;
}