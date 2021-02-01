#include <stdio.h>
#include <stdlib.h>

#define UPPER_LIMIT   	1000
#define LOWER_LIMIT   	1
#define BITUP 			10
#define BITDOWN(X)		((X)/(10))
#define REMAINDER(X)	((X)%(10))

int BitUp(int zegop);

int main(void){
	int testcase=0;
	int idx=0;
   
	//INPUT
	scanf("%d", &testcase);

	int num1[testcase];
	int num2[testcase];
	int sum[testcase];
	
	for(idx=0; idx<testcase; idx++){
		scanf("%d %d", &num1[idx], &num2[idx]);
		sum[idx] = 0;
	}

	if(testcase<LOWER_LIMIT || testcase>UPPER_LIMIT){
		exit(-1);
	}
	
	//PLUS
	for(idx=0; idx<testcase; idx++){
		num1[idx] += num2[idx];
		
		int count = 0;
		while ( !(BITDOWN(num1[idx])== 0 && REMAINDER(num1[idx])==1 ) ){	//num1이 더이상 BITDOWN 안되면서 1이 남을 때까지 반복
			switch(REMAINDER(num1[idx])){
				case 0:
					count++;
					break;
				case 1:
					sum[idx] += BitUp(count++);
					break;
				case 2:
					count++;
					num1[idx] += BITUP;
					break;
				case 3:
					sum[idx] += BitUp(count++);
					num1[idx] += BITUP;
					break;
			}
			num1[idx] = BITDOWN(num1[idx]);
		}	
		sum[idx] += BitUp(count++);
   }
   
   for(idx=0; idx<testcase; idx++){
	   printf("%d\n", sum[idx]);
   }
}

int BitUp(int zegop){
   if(zegop==0){
      return 1;
   }else{
      return 10 * BitUp(zegop-1);
   }
}   

//시간초과
   
   
