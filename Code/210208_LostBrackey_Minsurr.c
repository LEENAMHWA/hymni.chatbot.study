#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EXPRESSION_LENGTH			51
int greedyAlgorithm(char *expressionArray);

int main(void) {
	
	char *expressionArray;
	expressionArray = (char *)malloc(sizeof(char) * MAX_EXPRESSION_LENGTH);
	scanf("%s", expressionArray);

	int geongdap = 0;
	geongdap = greedyAlgorithm(expressionArray);

	printf("%d", geongdap);
	free(expressionArray);
		
	return 0;
}

int greedyAlgorithm(char *expressionArray) {
	
	int *expressionArray2 = (int *)malloc(sizeof(int) * MAX_EXPRESSION_LENGTH);
	int i = 0;
	int stringLength = 0;
	stringLength = strlen(expressionArray);
	int count = 0;
	int temporary = 0;
	int sum = 0;
	for(i = 0; i < stringLength; i++) {
		if(expressionArray[i] >= '0' && expressionArray[i] <= '9') {
			temporary = temporary * 10;
			temporary = temporary + (expressionArray[i] - '0');
		}
			
		if(expressionArray[i] == '+') {
			sum = sum + temporary;
			temporary = 0;
		}
		if(expressionArray[i] == '-') {
			sum = sum + temporary;
			expressionArray2[count] = sum;
			count++;
			sum = 0;
			temporary = 0;
		}
	}
	sum = sum + temporary;
	expressionArray2[count] = sum;

	int result = 0;

	result = expressionArray2[0];
	for(i = 1; i <= count; i++) {
		result = result - expressionArray2[i];
	}

	free(expressionArray2);

	return result;
}

