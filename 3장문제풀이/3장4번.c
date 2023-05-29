/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*#include <math.h>가 필요하다.
따로 제곱을 계산하는 연산자가 없기 때문에 pow()함수를 사용해야한다.*/

#include <stdio.h>
#include <math.h>
int main()
{
    int two[10] = { pow(2,0), pow(2,1), pow(2,2), pow(2,3), pow(2,4), pow(2,5), pow(2,6), pow(2,7), pow(2,8), pow(2,9)};
    for(int i=0; i<10; i++){
        printf("%d ", two[i]);
    }

    return 0;
}
