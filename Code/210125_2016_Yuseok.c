#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

char* solution(int date, int day);
void leapyear(int a);

char* solution(int date, int day){
   
   char *days[] = {"SUN", "MON", "TUE", "WEN", "THU", "FRI", "SAR"};
   int total_day=0;
   
   for(int i=1; i<date; i++)
		total_day += month[i-1];
	
   total_day += day;
   
   char* answer = (char*)malloc(sizeof(days)); 
   answer = days[total_day % 7];
   return answer;
}

void leapyear(int year){
	
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		month[1] = 29;
}

int main(void){
	
	//char days[][10] = {"SUN", "MON", "TUE", "WEN", "THU", "FRI", "SAR"};
	int date,day,year;
	
	scanf("%d %d %d", &date,&day,&year);
	leapyear(year);
	//solution(date,day);
	printf("%s", solution(date,day));
	//printf("%s", days[day % 7]); 
	return 0;
}