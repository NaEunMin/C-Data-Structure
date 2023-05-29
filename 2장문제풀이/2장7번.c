/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int sum(int n){
    printf("%d\n", n);
    if(n<1) return 1;
    else return (n+sum(n-1));
}
int main()
{
    sum(5);
    
    /*출력값
    5
    4
    3
    2
    1
    0
    
반환값 = 16
sum(5) = 5+ sum4  = 16

sum(4) = 4 + sum3  = 11 

sum(3) = 3 + sum 2 = 7 

sum(2) = 2 + sum 1 = 4 

sum(1) = 1 + sum 0 = 2

sum(0) = 1   */ 
    return 0;
}
