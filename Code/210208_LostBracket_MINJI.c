#include <stdio.h>
#include <stdlib.h>

#define MAX_EQUATION_LIMIT	50
#define CASTINT(X)	X-'0'
#define FLAG_MINUS	1

int main(void){
	int idx=0;
	char *equation = (char *)malloc(sizeof(char) * MAX_EQUATION_LIMIT);
	int temp_num=0, sum=0, minus_sum=0, flag=0;
	
	fscanf(stdin, "%s", equation);
	
	while(*(equation+idx) != '\0'){
		if( *(equation+idx) != '+' && *(equation+idx) != '-'){	//숫자면
			temp_num = (temp_num*10) + CASTINT( *(equation + (idx)) );
		}
		else	//부호면
		{		
			(flag==FLAG_MINUS) ? (minus_sum+=temp_num) : (sum+=temp_num);
			
			if( *(equation+idx)=='-' ){
				flag = FLAG_MINUS;
			}
			temp_num = 0;
		}
		idx++;
	}
	(flag==FLAG_MINUS) ? (minus_sum+=temp_num) : (sum+=temp_num);
	
	sum -= minus_sum;
	printf("%d", sum);
	
	free(equation);
	
	return 0;
}