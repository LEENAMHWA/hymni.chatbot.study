#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_BIN_CNT     1000000
#define CH_TO_NUM(X)    (X) - '0'
#define POW_2(X)        (int) pow(2.0,(float)(X))

int main(void){
    // Input (Binary Array)
    char *binArr = (char*)malloc(sizeof(char) * MAX_BIN_CNT);
    scanf("%s", binArr);
    int binLen = strlen(binArr);

    // Array Length(total) 8 = 2^3 
    int octSize = ((float)binLen / 3.0) > (binLen/3)? (binLen/3) + 1: binLen/ 3;

    // Oct Array
    int *octArr = (int*)malloc(sizeof(int) * octSize);
    
    // Initiallize for count
    memset(octArr,0,sizeof(int)*octSize);

    // Calculate
    for(int binIdx = 0; binIdx < binLen; binIdx++){
        octArr[(binIdx)/3] += (CH_TO_NUM(binArr[binLen - binIdx - 1])) * POW_2(binIdx % 3);
    }

    // Print oct Array
    for(int octIdx = octSize - 1; octIdx >= 0; octIdx--){
        printf("%d", octArr[octIdx]);
    }

    free(binArr);
    free(octArr);

    return 0;

}