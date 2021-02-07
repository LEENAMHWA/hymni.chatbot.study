#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define EQUATION_MAX    51
#define NUM_MAX         6
#define IS_OP(X)        ((X) == '-' || (X) == '+')? 1: 0

/*

    반례를 못찾겠습니다......
    반례를 찾아주시는 분께 사례를 드리겠습니다.....

*/

int main(void){
    int totalSum = 0, eqLen = 0, tmpLen = 0, plmaFlag = 1;
    char *equations = (char*) malloc(sizeof(char) * EQUATION_MAX);
    char *opNum = (char*) malloc(sizeof(char) * NUM_MAX);
    fgets(equations, sizeof(char)*EQUATION_MAX, stdin);

    eqLen = strlen(equations);
    for(int strIdx = 0; strIdx < eqLen; strIdx++){
        // Operator or Last data
        if(IS_OP(equations[strIdx]) || (strIdx == eqLen - 1)){
            // Copy to tmp array
            strncpy(opNum, equations + (strIdx - tmpLen) ,tmpLen);

            totalSum += (plmaFlag * atoi(opNum));
            
            if((equations[strIdx] == '-') && (plmaFlag == 1)){
                plmaFlag = -1;
            }

            // Initiallize
            tmpLen = 0;
            memset(opNum,0,sizeof(char) * NUM_MAX);
        }else{
            tmpLen++;
        }
    }

    free(equations);
    free(opNum);

    printf("%d", totalSum);
    
    return 0;
}