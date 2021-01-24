#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DAYLENGTH 3
#define WEEKLEGNTH 7
#define MONTHS 12

char* solution(int a, int b) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char *answer = (char *)malloc(sizeof(char) * DAYLENGTH);
    
    char *dayIndex[WEEKLEGNTH] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int days[MONTHS] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    //  Init
    int mon = 1, day = 1, dayIdx = 4;
    
    while(1){
        // 조건에 맞는 상황
        if(mon == a && day == b){
            answer = dayIndex[dayIdx % 7];
            break;
        }
        
        if(days[mon-1] == day){
            day = 1;
            mon++;
        }else{
           day++; 
        }
        
        dayIdx++;
        
    }
    
    return answer;
}