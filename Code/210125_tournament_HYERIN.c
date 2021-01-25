#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    int jimin, hansu;
    int cnt=0;

    scanf("%d %d %d", &number, &jimin, &hansu);

    if (number < jimin || number < hansu){
        cnt = -1;
    }
    else{
        while (jimin != hansu){
            jimin = (jimin + 1) / 2;
            hansu = (hansu + 1) / 2;
            cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}