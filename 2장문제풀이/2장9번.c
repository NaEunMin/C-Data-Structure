/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int recursive(int n){
    printf("%d\n",n);
    if(n<1) return -1;
    else return ( recursive(n-3)+1);
}
int main()
{
    int sum = recursive(10);
    printf("반환값 >> %d",sum);
    
    /*
    recursive(10) = recursive(7) + 1 = 3
    recursive(7) = recursive(4) + 1 =2
    recursive(4) = recursive(1) + 1= 1
    recursive(1) = recursive(-2) + 1= 0
    recursive(-2) = -1
    */
    return 0;
}
