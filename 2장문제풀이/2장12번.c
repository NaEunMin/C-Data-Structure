/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void unknown(){
    int ch;
    if( (ch=getchar() ) != '\n')
    unknown();
    putchar(ch);
}
int main()
{
    unknown();
    
    return 0;
}
/*
recursive 각 문자에 unknown()함수가 깃들어있다고 생각하자.
Enter키 입력하면 나머지는 putchar()함수만 실행되면 된다.
순환구조이므로 거슬러 올라가므로 e부터 r까지 실행되어 문자가 거꾸로 출력된다.*/
