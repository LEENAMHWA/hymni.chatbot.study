#include<stdio.h>

int main(void) {

	//체스판 입력을 위한 배열 선언(Null 문자? 때문에 9/9로 선언)
	char Arr[9][9];

	//for문 동작을 위한 변수 i, j
	int i, j = 0;

	//문자열 입력받기
	for(i = 0; i < 8; i++) {
		scanf("%s", &Arr[i][j]);
	}
	
	printf("\n");

	//흰색 체스판에 위치한 'F'의 개수를 카운팅하기 위한 변수
	int cnt = 0;

	//행의 index가 0과 짝수 일 때 
	for(i = 0; i < 8; i+=2) {
		for(j = 0; j < 8; j++) {
			//행 index와 열 index가 0 또는 짝수 일 때 흰색 체스판
			if(j % 2 == 0 && Arr[i][j] != '.') {
				cnt ++;
			}
		}
	}
	
	//행의 index가 홀수 일 때
	for(i = 1; i < 8; i += 2) {
		for(j = 0; j < 8; j++) {
			//행 index와 열 index가 홀수 일 때 흰색 체스판
			if(j % 2 == 1 && Arr[i][j] !='.') {
				cnt++;
			}
		}
	}

	printf("%d", cnt);

	return 0;

}
