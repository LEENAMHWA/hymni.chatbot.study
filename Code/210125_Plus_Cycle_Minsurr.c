//싸이클!

#include<stdio.h>
#include<stdlib.h>
#define ARR_COUNT 2

int calculate(int a);

int main(void) {

	int number = 0;
	printf("N 값을 입력하세요\n");
	scanf("%d", &number);
	
	//문제에서의 요구사항
	if(number < 0 || number > 99) {
		printf("범위안의 N 값을 입력하세요");
		exit(0);
	}	
	
	int result = 0;
	//입력된 number의 10의자리, 1의자리를 각각 저장하기위한 배열	
	if(number < 10) {
		result = calculate(number);
	}
	else {
		result = calculate(number);
	}

	printf("%d ", result);
	
	return 0;

}

int calculate(int a) {

	int tmp = 0;
	int array[ARR_COUNT];
	int count = 0; 
	int solution = 0;

	tmp = a;
	while(1) {             
		if(tmp < 10) {
			array[0] = 0;
			array[1] = tmp % 10;
        }
        else {
			array[0] = tmp / 10;
			array[1] = tmp % 10;
        }
        //10의 자리수와 1의 자리수를 각각 더했을 때 10이 넘는경우
        solution = array[0] + array[1];
        if(solution >= 10) {
			solution = solution % 10;
        }
        tmp = (array[1] * 10) + solution;
        count++;
        if(a == tmp) {
			break;
        }
    }
	return count;
}	
