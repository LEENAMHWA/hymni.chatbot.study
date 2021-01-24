#include<stdio.h>
#include<stdlib.h>
#define ARR_COUNT 2

int main(void) {

	int number = 0;

	//printf("N 값을 입력하세요\n");
	scanf("%d", &number);

	if(number < 0 || number > 99) {
		printf("범위안의 N 값을 입력하세요");
		exit(0);
	}	
	
	int arr[ARR_COUNT];
	int tmp = 0;
	int count = 0;
	int solution = 0;
	if(number < 10) {
		tmp = number;
		while(1) {
			if(tmp < 10) {

				arr[0] = 0;
				arr[1] = tmp % 10;
			}
			else {
				arr[0] = tmp / 10;
				arr[1] = tmp % 10;
			}
			solution = arr[0] + arr[1];
			if(solution >= 10) {
				solution = solution % 10;
			}
			tmp = (arr[1] * 10) + solution;
			count++;
			if(number == tmp) {
				break;
			}
		}
		printf("%d ", count);	
	}
	else {
		
		tmp = number;
		
		count = 0;

		while(1) {
			arr[0] = tmp / 10;
			arr[1] = tmp % 10;
			
			solution = arr[0] + arr[1];
			if(solution >= 10) {
				solution = solution % 10;
			}
			tmp = (arr[1] * 10) + solution;
		   	count++;

			if(number == tmp) {
				break;
			}			
		}

		printf("%d", count);

	}

	return 0;

}	
