//토너먼트

#include<stdio.h>
#include<stdlib.h>

int main(void) {
	//참가자 전체, 김지민, 임한수 참가 번호 변수 초기화
	int personNumber, numberKim, numberLim = 0;
	
	printf("참가자 수, kim과 lim의 번호를 순서대로 할당하세요\n");
	scanf("%d %d %d", &personNumber, &numberKim, &numberLim);

	//참가자는 최대 10만명을 초과할 수 없는 자연수.	
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
			//참가자의 참가번호가 홀수 일 때
			if(numberKim % 2 == 1) {
				numberKim = (numberKim/2) + 1;
			}
			//짝수 일 때
			else { 
				numberKim = (numberKim/2);
			}
			if(numberLim % 2 == 1) {
				numberLim = (numberLim/2) + 1;
			}
			else {
				numberLim = (numberLim/2);
			}
	
			//참가자 KIM과 LIM이 만날 때까지 반복.(둘이 번호가 같아진다는 것은 경리를 치뤘다는 것을 의미.)
			if(numberKim == numberLim) {
				break;
			}
			count++;
		}
		printf("%d", count);
	}

	
}
