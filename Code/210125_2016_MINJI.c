#include <stdio.h>
#include <stdlib.h> 

char* day_name[] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
const int monthDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

char* solution(int month, int day) {   
	char* answer = (char*)malloc(sizeof(char) * 3);
    int total_days = 0;

    for(int m_idx=0; m_idx<month-1; m_idx++)
        total_days += monthDays[m_idx];
    total_days += day;

    answer = day_name[total_days%7];
	return answer;
}

int main(void){
	int month, day;
	scanf("%d %d", &month, &day);
	
	char *day_choice = solution(month, day);
	printf("%s", day_choice);
	
	free(day_choice);
	return 0;
}