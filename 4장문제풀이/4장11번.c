/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

C문법에 대한 이해가 부족하여 꽤나 고전했던문제 C를 충분히 다시 복습하자. 오랫동안안하면 까먹는다.
*** scanf()***
문자열입력받기: scanf("%s", 문자열); 
처음엔 반복문으로 엔터키 입력받으면 종료시킬려는 생각을 했는데 문법이해도가 부족하여 나온 생각이였다.
위 방법을 사용하면 되었기 때문이다.

*** 스택 ***
스택엔 괄호를 저장하는 것이 아닌 "괄호 번호를 저장하는 것"이다.
'('을 만나면 count를 push하고 count++을 해주고 ')'를 만나면 pop을 한다음 i++을 해서 다음 괄호를 검사하도록 하는 구조이다.

*/

#include <stdio.h>

#define MAX_STACK_SIZE 100

typedef struct{
    int stack[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType *s){
    s->top = -1;
}
int is_full(StackType *s){
    return (s->top == MAX_STACK_SIZE-1);
}
int is_empty(StackType *s){
    return (s->top==-1);
}
void push(StackType *s, int item){
        s->stack[++(s->top)] = item;
}
int pop(StackType *s){
    return s->stack[(s->top)--];
}
int main()
{
    StackType s;
    init_stack(&s);
    char input[MAX_STACK_SIZE] = {};
    printf("수식 : ");
    scanf("%s", input);
    printf("괄호 수: ");
    int i=0;
    int count=1;
    while(input[i]!=NULL){
        if(input[i]=='('){
           push(&s, count);
           printf("%d ", count);
           count++;
        }
        else{
            printf("%d ", pop(&s));
        }
        i++;
    }

    return 0;
}
