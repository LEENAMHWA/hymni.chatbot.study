#include<stdio.h>
#include<stdlib.h>

int greedyAlgorithm(int* coinArray, int coinKinds, int coinSum);

int main(void) {
	//coinKinds = 동전 종류, coinSum = 금액의 총 합.
	int coinKinds = 0;
	int coinSum = 0;

	scanf("%d %d", &coinKinds, &coinSum);
	
	if(coinKinds > 10 || coinKinds < 1) {
		exit(0);
	}
	if(coinSum > 100000000 || coinSum < 1) {
		exit(0);
	}

	int i = 0;
	int *coinArray = (int *)malloc(sizeof(int) * coinKinds);
	for(i = 0; i < coinKinds; i++) {
		scanf("%d", &coinArray[i]);
	}

	int result = 0;
	result = greedyAlgorithm(coinArray, coinKinds, coinSum);
	
	printf("%d", result);
	
	free(coinArray);

	return 0;
}

//GREEDY ALGORITHM
int greedyAlgorithm(int* coinArray, int coinKinds, int coinSum) {
	int count = 0;
	int i = 0;
		
	for(i = coinKinds - 1; i >= 0; i--) {
		while(1) {
			if(coinSum < coinArray[i]) {//해당 동전으로 더이상 뺄 수 없을 때 까지
				break;
			}
			else {
				coinSum = coinSum - coinArray[i];
				count++;
			}
		}
		
	} 


	return count;
		
}
