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

    // Array Length(total) 8 = 2^3 
    int octSize = ((float)strlen(binArr) / 3.0) > (strlen(binArr)/3)? (strlen(binArr)/3) + 1: strlen(binArr) / 3;

    // Oct Array
    int *octArr = (int*)malloc(sizeof(int) * octSize);
    
    // Initiallize for count
    memset(octArr,0,sizeof(int)*octSize);

    for(int binIdx = 0; binIdx < strlen(binArr); binIdx++){
        octArr[(binIdx)/3] += (CH_TO_NUM(binArr[strlen(binArr) - binIdx - 1])) * (POW_2(binIdx % 3));
    }

    for(int octIdx = octSize - 1; octIdx >= 0; octIdx--){
        printf("%d", octArr[octIdx]);
    }

    return 0;

}