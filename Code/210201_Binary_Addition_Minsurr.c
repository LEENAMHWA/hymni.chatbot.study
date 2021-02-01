#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ARRAY_INDEX	81
void reverseArray(char* binaryInput);
void addZero(char* binaryInput1, char* binaryInput2);


int main(void) {

	int testCase = 0;
	scanf("%d", &testCase);
	if(testCase < 1 || testCase > 1000) {
		exit(0);
	}	

	char* binaryInput1 = (char*)malloc(sizeof(char) * ARRAY_INDEX);
	char* binaryInput2 = (char*)malloc(sizeof(char) * ARRAY_INDEX);
	int* binaryOutput = (int*)malloc(sizeof(int) * (ARRAY_INDEX+1));
	memset(binaryOutput, 0, sizeof(int) * (ARRAY_INDEX + 1));
	int i = 0;
	int j = 0;
	

	for(i = 0; i < testCase; i++) {
		scanf("%s %s", binaryInput1, binaryInput2);
		addZero(binaryInput1, binaryInput2);
		reverseArray(binaryInput1);
		reverseArray(binaryInput2);
		printf("reverse binary 1 : %s\n", binaryInput1);
		printf("reverse binary 2 : %s\n", binaryInput2);
		//첫 번째 비트에서 이진수 연산을 할 때는 캐리가 없기에 0으로 초기화
		int carry = 0;
		for(j = 0; j < strlen(binaryInput1); j++) {
			switch(carry) {
				//캐리가 0일경우 case 0의 조건문으로 진행.
				case 0: {
					if(binaryInput1[j] == '1' && binaryInput2[j] == '1') {
						binaryOutput[j] = 0;
						carry = 1;
						if(j == strlen(binaryInput1) - 1 ) {
							binaryOutput[j + 1] = 1;
						}
					}
					else if(binaryInput1[j] == '0' && binaryInput2[j] =='0') {
						binaryOutput[j] = 0;
						carry = 0;
					}
					else {
						binaryOutput[j] = 1;
						carry = 0;
					}
					break;
				}
				//캐리가 1일 경우 case 1의 조건문으로 진행.
				case 1: {
					if(binaryInput1[j] == '1' && binaryInput2[j] == '1') {
						binaryOutput[j] = 1;
						carry = 1;
						if(j == strlen(binaryInput1) - 1) {
							binaryOutput[j + 1] = 1;
						}	
					}
					else if(binaryInput1[j] == '0' && binaryInput2[j] == '0') {
						binaryOutput[j] = 1;
						carry = 0;
					}
					else {
						binaryOutput[j] = 0;
						carry = 1;
					}
					break;
				}
			}	
	
		}
	}
	
	// binaryOutput 역순으로 출력.
	for(i = j; i >= 0; i--) {
		if(i == j && binaryOutput[i] != 1) {
			continue;
		}
		else {
			printf("%d", binaryOutput[i]);
		}
	}
	
	return 0;
	
}
// 입력받은 이진수의 순서를 역순으로 정리하기 위한 함수.

void reverseArray(char* binaryInput) {
	int stringLength = 0;
	char temp;
	stringLength = strlen(binaryInput);

	for(int i = 0; i < stringLength / 2; i++) {
		temp = binaryInput[i];
		binaryInput[i] = binaryInput[stringLength - i - 1];
		binaryInput[stringLength - i - 1] = temp;
	}
		
}

// 입력받은 이진수 A와 B의 길이가 다를 것을 고려해 자리수를 맞춰주기 위한 함수.

void addZero (char* binaryInput1, char* binaryInput2) {
	int stringLength_B1 = 0;
	int stringLength_B2 = 0;
	int stringLength_SUB = 0;
	stringLength_B1 = strlen(binaryInput1);
	stringLength_B2 = strlen(binaryInput2);
	stringLength_SUB = stringLength_B1 - stringLength_B2;
	
//stringLength_SUB가 0보다 크다는 것은 차이가 존재 -> 기존 배열의 위치 조정 및 '0' 추가
	if(stringLength_SUB > 0) {
		int i = 0;
		for(i = 0; i < stringLength_SUB; i++) {
			memmove(binaryInput2+1, binaryInput2, sizeof(char) * ARRAY_INDEX);
			binaryInput2[i] = '0';
		}
			
	}
//그 외의 경우에는 그대로 반환
	else {
		return ;
	}
}
