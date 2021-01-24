#include<stdio.h>
#include<stdlib.h>

#define GIVE_ME_SHIPJARI(x)     ((int)(x) / 10)
#define GIVE_ME_ILJARI(x)       ((int)(x) % (((x) / 10) * 10))

int main(void){
    int targetNum = 0, tmpSum = 0, cycleNum = 0, cycleIdx = 1;
    scanf("%d", &targetNum);
    cycleNum = targetNum;

    while(1){
        // 한자리인 경우
        if(cycleNum < 10){
            cycleNum = (cycleNum * 10) + cycleNum;
        }else{
            tmpSum = GIVE_ME_SHIPJARI(cycleNum) + GIVE_ME_ILJARI(cycleNum); 
            cycleNum = (tmpSum >= 10)? (GIVE_ME_ILJARI(cycleNum) * 10) + GIVE_ME_ILJARI(tmpSum) : (GIVE_ME_ILJARI(cycleNum) * 10) + tmpSum;
        }

        if(cycleNum == targetNum){
            printf("%d",cycleIdx);
            break;
        }
        cycleIdx++;
    }


    return 0;
}
 