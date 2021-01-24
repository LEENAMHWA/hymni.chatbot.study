#include<stdio.h>
#include<stdlib.h>

int main(void) {
	//변수 초기화
	int personNumber, numberKim, numberLim = 0;
	
	printf("참가자 수, kim과 lim의 번호를 순서대로 할당하세요\n");
	scanf("%d %d %d", &personNumber, &numberKim, &numberLim);

	//예외처리	
	if(personNumber <= 0 || personNumber > 100000) {
		printf("10만보다 작거나 같은 자연수를 입력하세요");
		exit(0);
	}
	//personNumber의 조건을 만족할 때, 다른 변수들의 예외처리.
	else {
		if(numberKim <= 0 || numberKim > personNumber || numberLim <= 0 || numberLim > personNumber) {
			printf("참가번호는 참가자 수보다 작거나 자연수여야 합니다.");
			exit(0);
		}
		else if(numberKim == numberLim) {
			printf("참가자들의 참가번호는 같을 수 없습니다.");
			exit(0);
		}

		//토너먼트 첫 경부터 마주칠 수 있기 때문에 1로 초기화
		int count = 1;

		while(1) {
			if(numberKim % 2 == 1) {
				numberKim = (numberKim/2) + 1;
			}
			else { 
				numberKim = (numberKim/2);
			}
			if(numberLim % 2 == 1) {
				numberLim = (numberLim/2) + 1;
			}
			else {
				numberLim = (numberLim/2);
			}
			//printf("ssibal2\n");			
			if(numberKim == numberLim) {
				break;
			}
			count++;
		}
		printf("%d", count);
	}

	
}
