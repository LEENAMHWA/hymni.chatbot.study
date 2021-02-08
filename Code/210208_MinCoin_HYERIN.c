#include <stdio.h>

int main(void){
	
	int num, won;
	int i, j, tmp = 0, count = 0;
	int coin[10]={ 0, };

	scanf("%d %d", &num, &won);
	for(i=0;i<num;i++){
		scanf("%d", &coin[i]);
	}
	
	//내림차순
	for(i=0;i<num;i++){
		for(j=0;j<(num-1)-i;j++){
			if(coin[j]<coin[j+1]){
				tmp = coin[j];
				coin[j] = coin[j+1];
				coin[j+1] = tmp;
			}
		}
	}
	
	for(i=0;i<num;i++){
		if(coin[i] / won == 0){            
			count += won / coin[i];
			won = won % coin[i];
		}
		if(coin[i] == won ){
			count ++;
			break;
		}
		if(won == 0){
			break;
		}
	}			
	printf("%d", count); 
	return 0;
}