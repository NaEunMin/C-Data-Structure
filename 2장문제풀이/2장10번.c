/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int recursive(int n){
    if(n!=1) recursive(n-1);
    printf("%d\n", n);
}
int main()
{
    int sum = recursive(5);
    printf("반환값 >> %d",sum);
    
    return 0;
}
