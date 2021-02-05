#include<stdio.h>
#include<stdlib.h>

int main(void){
	int maxCoins = 0, targetTotal = 0, totalCoins = 0;
	scanf("%d %d", &maxCoins, &targetTotal);

	int *coinArr = (int*)malloc(sizeof(int) * maxCoins);

	for(int coinIdx = 0; coinIdx < maxCoins; coinIdx++){
		scanf("%d", coinArr+coinIdx);
	}

	for(int coinIdx = maxCoins - 1; coinIdx >= 0; coinIdx--){
		
		if((targetTotal / *(coinArr+coinIdx)) >= 0){
			totalCoins += (targetTotal / *(coinArr+coinIdx));
			targetTotal %= *(coinArr+coinIdx);
		}
	}
	printf("%d", totalCoins);
	free(coinArr);

	return 0;
}
