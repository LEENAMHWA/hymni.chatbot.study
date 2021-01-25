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
	
	// 리턴할 값은 동적메모리로 할당해주세요.
	char* answer = (char*)malloc(7); 
    /*1월 1일은 금요일, 1월 8일도 금요일
	  % 7로 연산시 1이 남으면 금요일이기 때문에 배열 index설정 편의를 위해
	  dayName[] index 1번에 금요일을 배치.
	*/
    char* dayName[] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    
    // 각 월에 해당하는 일수를 입력해놓음
    int day[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int daySum = 0;
	int i = 0;
    int check = 0;
    
	/*인자로 넘겨받는 월에 해당하는 위치 지정
	 및 해당 월까지의 모든 일의 합.
	*/ 
    for(i = 0; i < a - 1; i++) {
        daySum = daySum +  day[i];
    }
	
	// 해당 월 전월까지의 모든일 합 + 해당 월의 일 합
	daySum = daySum + b;
	check = daySum % 7;     

    answer = dayName[check];
    return answer;
	free(answer);
}
