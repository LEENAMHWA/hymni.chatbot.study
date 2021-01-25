#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int a, int b) {
    int month[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *day[7] =  { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    
    for(int i=0;i<a-1;i++)
    {
        b += month[i];
    }
    
    return day[b%7];
}