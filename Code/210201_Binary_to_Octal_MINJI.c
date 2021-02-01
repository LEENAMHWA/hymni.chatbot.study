#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INTCAST(X) ((X) - ('0'))
#define LIMIT 1000000
int Power(int num, int zegop);

int main(void){   
	char* two_nums = (char*) malloc( sizeof(char) * LIMIT );
	int ten_num=0, eight_num=0;
   
	scanf("%s", two_nums); 
   
	if( strlen(two_nums) > LIMIT ){
		exit(-1);
	}
   
	//two to ten_num 
	for(int idx=0; idx<strlen(two_nums); idx++){
		if(two_nums[idx] == '1')
			ten_num += ( INTCAST(two_nums[idx]) * Power( 2, strlen(two_nums)-1-idx ) );   
	} 
   
   //ten to eight_num
	int count = 0;
	while(ten_num/8 != 0){
		eight_num += ( (ten_num%8) * Power(10, count++) );
		ten_num = (ten_num/8);
	}
	eight_num += ( (ten_num%8) * Power(10, count) );
   
	printf("%d", eight_num);
	free(two_nums);
	return 0;
}

int Power(int num, int zegop){
	int gop=1;
   
	if(zegop==0){
		return 1;
	}
   
	for(int i=0; i<zegop; i++){
		gop *= num; 
	}
	return gop;
}

//시간초과
//limit 줄이면 런타임 에러 (Segfault)