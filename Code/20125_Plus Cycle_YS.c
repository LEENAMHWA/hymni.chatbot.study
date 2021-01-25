#include <stdio.h>
void Cycle (int a);

void Cycle (int a){
	
	int samenumber;
	samenumber = a;
	
	int sum;
	int count=0;
	int ten_digit, one_digit, New_one_digit;
	
	while(1){
		
		ten_digit = samenumber/10;
		one_digit = samenumber%10;
		sum = ten_digit + one_digit;
		New_one_digit = sum % 10;
		samenumber = one_digit*10 + New_one_digit;
		count ++;
		if(a == samenumber)
			break;
	}
	
	printf("%d", count);
}

int main(void){
int n;

	while(1){
		
		scanf("%d",&n);
		if(n>0 || n<100){
			break;
		}else
		{
		 printf("0보다크고 100보다 아래인 수를 입력해주세요!");
		 scanf("%d",&n);	
		}
	}

	if(n<10)
		n * 10;	
	
	Cycle(n);
return 0;
}
