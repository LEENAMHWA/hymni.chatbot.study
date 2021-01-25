#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number,tmp, count = 0;
    int ten, one, sumTen, sumOne;

    scanf("%d", &number);
    tmp = number;
    do {
        ten = number/10;
        one = number%10;
        sumTen = (ten+one)/10;
        sumOne = (ten+one)%10;
        number = (one*10) + sumOne;
        count++;
    }while(number != tmp);

    printf("%d", count);

    return 0;
}