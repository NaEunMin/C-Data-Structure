/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int recursive(int n){
    printf("%d\n",n);
    if(n<1) return 2;
    else return ( 2*recursive(n-1)+1);
}
int main()
{
    int sum = recursive(5);
    printf("반환값 >> %d",sum);
    
    return 0;
}
/*출력값
5
4
3
2
1
0

반환값 >> 95*/
