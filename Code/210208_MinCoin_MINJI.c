#include <stdio.h>
#include <stdlib.h>

#define MAX_COINTYPE_LIMIT	10
#define MAX_ASSETS_LIMIT	100000000
#define MAX_COIN_LIMIT		1000000
#define NO_ASSETS			0

int CountCoin(int *cointype, int *assets, int *coin);

int main(void){
	int idx=0, coin_cnt=0;
	int *cointype = (int*)malloc(sizeof(int));
	int *assets = (int*)malloc(sizeof(int));
	
	//INPUT
	fscanf(stdin, "%d %d", cointype, assets);
	int *coin = (int*)malloc(sizeof(int) * *cointype);
	for(idx=0; idx < *cointype; idx++){
		fscanf(stdin, "%d", (coin+idx));
	}
	
	//INPUT CHECK
	if( (*cointype > MAX_COINTYPE_LIMIT) || (*assets > MAX_ASSETS_LIMIT) ){
		exit(0);
	}	
	for(idx=0; idx < *cointype; idx++){
		if( *(coin+idx) > MAX_COIN_LIMIT){
			exit(0);
		}
	}

	while(*assets>0){
		coin_cnt += CountCoin(cointype, assets, coin);
	}
	
	printf("%d", coin_cnt);
	
	free(cointype);
	free(assets);
	free(coin);
}

int CountCoin(int *cointype, int *assets, int *coin){
	int coin_cnt=0, idx=0;
	for(idx= *cointype-1; idx>=0; idx--){
		if( *assets - *(coin+idx) >= 0 ){
			coin_cnt = *assets / *(coin+idx);
			*assets = *assets % *(coin+idx);
			*cointype = idx;
			
			return coin_cnt;
		}
	}
	return NO_ASSETS;
}
