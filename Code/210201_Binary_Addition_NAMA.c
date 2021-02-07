#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CH_TO_NUM(X)    (X) - '0'
#define MAX_BIN_LEN     81

/*

    반례를 못찾겠습니다......
    반례를 찾아주시는 분께 사례를 드리겠습니다.....

*/

int main(void){
    int maxIter, longLen, shortLen, aLen, bLen, carry, zeroFlag;
    char *cursor;
    scanf("%d", &maxIter);

    char *binArr1 = (char *)malloc(sizeof(char) * MAX_BIN_LEN);
    char *binArr2 = (char *)malloc(sizeof(char) * MAX_BIN_LEN);
    int **resultArr = (int **)malloc(sizeof(int*) * maxIter);

    for(int iterIdx = 0; iterIdx < maxIter; iterIdx++ ){
        carry = 0;
        resultArr[iterIdx] = (int *)malloc(sizeof(int) * (MAX_BIN_LEN + 1));
        memset(resultArr[iterIdx], -1, sizeof(int) * (MAX_BIN_LEN + 1));

        scanf("%s %s", binArr1, binArr2);
   
        aLen = strlen(binArr1);
        bLen = strlen(binArr2);
        
        // 자릿수 맞춰주기!
        longLen = (aLen > bLen)? aLen: bLen;
        cursor = (aLen > bLen)? binArr2: binArr1;
        shortLen = strlen(cursor);
        
        memcpy(cursor + (longLen - shortLen),cursor, sizeof(char) * shortLen);
        memset(cursor,'0', sizeof(char) * (longLen-shortLen));

        // 자릿수 맞춰주기 끝

        for(int binIdx = 0; binIdx < longLen; binIdx++){
            resultArr[iterIdx][binIdx] = carry + CH_TO_NUM(binArr1[longLen - binIdx - 1]) + CH_TO_NUM(binArr2[longLen - binIdx - 1]);
            if(resultArr[iterIdx][binIdx] >= 2){
                carry = 1;
                resultArr[iterIdx][binIdx] -= 2;
            }else{
                carry = 0;
            }

            if((binIdx == longLen - 1) && (carry == 1)){
                resultArr[iterIdx][binIdx + 1] = 1;
            }
        }
    }

    
    // 형식에 맞추어 출력하기
    for(int iterIdx = 0; iterIdx < maxIter; iterIdx++){
        zeroFlag = 0;
        for(int prntIdx = MAX_BIN_LEN; prntIdx >= 0; prntIdx--){
            if(resultArr[iterIdx][prntIdx] != -1){
                if((zeroFlag == 0) && (resultArr[iterIdx][prntIdx] == 0)){
                    continue;
                }else{
                    zeroFlag = 1;
                }
                printf("%d",resultArr[iterIdx][prntIdx]);
            }
        }

        if(zeroFlag == 0){
            printf("0");
        }

        printf("\n");
    }

    free(binArr1);
    free(binArr2);
    free(resultArr);
}
