/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int sum(int n){
    if(n==1) return 1;
    else return n+sum(n-1);
}

int main()
{
    int suum = sum(5);
    printf("합은 %d", suum);

    return 0;
}
/*
sum(5) = 5 + sum(4) = 15
sum(4) = 4 + sum(3) =10
sum(3) = 3 + sum(2) = 6
sum(2) = 2 + sum(1) = 3
sum(1) = 1
*/
