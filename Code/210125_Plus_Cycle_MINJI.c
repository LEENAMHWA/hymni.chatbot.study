#include <stdio.h>
#include <math.h>

#define TRANSFORM_NUM(X) (X%10)*10 + (X/10 + X%10)%10

int main(){
	int num, compare_num, count=1;
	scanf("%d", &num);
	
	if(num<0 && num>99)
		return -1;
		
	if(num < 10)
		num = num*10 + num;
	
	compare_num = TRANSFORM_NUM(num);
	
	while(num!=compare_num){	
		compare_num = TRANSFORM_NUM(compare_num);
		count+=1;
	}
	
	printf("%d", count);
		
    return 0;
}
