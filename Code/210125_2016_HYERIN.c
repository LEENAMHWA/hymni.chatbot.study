#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, i;
    int month[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *day[7] = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};

    scanf("%d %d", &x, &y);
    for(i=0;i<x-1;i++)
    {
        y += month[i];
    }
    printf("%s", day[y%7]);

    return 0;
}