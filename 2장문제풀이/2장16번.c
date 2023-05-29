/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/* 더하는 알고리즘을 for문으로 작성하기만 하면 된다.*/
#include <stdio.h>

int sum(int n){
    int sum=0;
    for(int i=1; i<=n; i++){
        sum += i;
    }
    return sum;
}
int main()
{
    printf("%d", sum(5));
    return 0;
}

