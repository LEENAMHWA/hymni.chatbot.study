#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

char* solution(int a, int b);

int main(void) {
	int month, day = 0;
	char* jeongDAP;

	printf("월과 일을 입력하세요\n");
	scanf("%d %d", &month, &day);

	jeongDAP = solution(month, day);

	printf("%s", jeongDAP);

	return 0;

}

char* solution(int a, int b) {
    // a는 월을 입력, b는 일을 입력
	char* answer = (char*)malloc(4); 
    // 1월 1일은 금요일, 1월 8일도 금요일
    char* dayName[] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    
    // 각 월에 해당하는 일수를 입력해놓음
    int day[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int daySum, i = 0;
    int check = 0;
    
	//인자로 넘겨받는 월에 해당하는 위치 지정 
    for(i = 0; i < a - 1; i++) {
        daySum += day[i];
    }
    
    if(a == 1) {
        daySum += b;
        check = daySum % 7;
    }
    else if(a == 2) {
        daySum += b;
        check = daySum % 7;
    }
    else if(a == 3) {
        daySum += b;
        check = daySum % 7;
    }
    else if(a == 4) {
        daySum += b;
        check = daySum % 7;
    }
    else if(a == 5) {
        daySum += b;
        check = daySum % 7;
    }
    else if(a == 6) {
        daySum += b;
        check = daySum % 7;
    }
    else if(a == 7) {
        daySum += b;
        check = daySum % 7;
    }
    else if(a == 8) {
        daySum += b;
        check = daySum % 7;
    }
    else if(a == 9) {
        daySum += b;
        check = daySum % 7;
    }
    else if(a == 10) {
        daySum += b;
        check = daySum % 7;
    }
    else if(a == 11) {
        daySum += b;
        check = daySum % 7;
    }
    else if(a == 12) {
        daySum += b;
        check = daySum % 7;
    }
        
    // 리턴할 값은 메모리를 동적 할당해주세요.
    answer = dayName[check];
    return answer;
}
