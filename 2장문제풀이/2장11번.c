/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void asterisk(int i){
    if(i>1){
        asterisk(i/2);
        asterisk(i/2);
    }
    printf("*");
    printf("%d",i);
}
int main()
{
    asterisk(5);
    
    return 0;
}
/*
*** i>1일 경우 ***
if문을 실행하고나서 그 다음 printf를 실행하므로 asterisk()함수가 몇번 실행되었는지 알아보면 *이 몇개 출력되는지 알 수 있다.*/
