#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
    int roundNum = 0, bigNum = 0;
    float numKim = 0, numLim = 0;
    scanf("%d %f %f", &roundNum, &numKim, &numLim);

    int roundIdx = 1;
    while(roundIdx <= roundNum){
        bigNum = (numKim > numLim)?numKim:numLim;
        if((abs((int)(numLim-numKim)) == 1) && ((int)bigNum % 2 == 0))   {
            printf("%d", roundIdx);
            break;
        }
        numKim = ceil(numKim / 2.0);
        numLim = ceil(numLim / 2.0);
        roundIdx++;

    }

    return 0;

}