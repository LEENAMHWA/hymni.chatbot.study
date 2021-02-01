#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned long long binaryConversion(char* binaryCopy);

int main(void) {
	//char binaryNumber[1000000] = {0,};
	char *binaryNumber;
	binaryNumber = (char*)malloc(sizeof(char) * 1000000);
	memset(binaryNumber, '0', sizeof(char) * 1000000);
	//printf("이진수를 입력하세요\n");
	scanf("%s", binaryNumber);
	
	unsigned long long result = 0;	
	result = binaryConversion(binaryNumber);
	printf("%llu ", result);

	int i = 0;
	//int octalArray[10000] = {0,};
	unsigned long long *octalArray;
	octalArray = (unsigned long long*)malloc(sizeof(unsigned long long) * 1000000);
	memset(octalArray, 0, sizeof(unsigned long long) * 1000000);
	while(1) {

		if(result / 8 == 0) {
			octalArray[i] = result % 8;	
			break;
		}
		else {
			octalArray[i] = result % 8;
			result = result / 8;
			i++;
		}
	}
	int j;
	for(j = i; j >= 0; j--) {
		//printf("%llu", octalArray[j]);
	}
	free(binaryNumber);
	free(octalArray);	
	return 0;
	
}

unsigned long long binaryConversion(char* binaryCopy) {
	int stringLength = 0;
	unsigned long long decimal = 0;
	int i = 0;
	unsigned long long jegop = 1;

	stringLength = strlen(binaryCopy);

	for(i = stringLength-1; i >= 0; i--) {
		if(binaryCopy[i] == '0') {
			decimal = decimal + 0;
			jegop = jegop * 2;
		}

		if(binaryCopy[i] == '1') {
			decimal = decimal + jegop;
			jegop = jegop * 2;
		}
	}	
	return decimal;
}
