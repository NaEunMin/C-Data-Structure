/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

큐의 기능을 스택의 기능으로만 구현하려고 시도해보았다 --> 그래서 스택만 구현을 해서 문제를 풀었다.
*** 알고리즘 ***
스택 : 선입후출
큐 : 선입선출
즉, 스택s1에서 스택s2로 pop해서 옮기고 출력시 s2를 pop하면 결과적으로 선입선출이 가능하게 된다.
예시로 코드에 1,2,3을 넣어보았다.
s1 ==> 1, 2, 3 순서로 들어감
s2 ==> 3, 2, 1순서로 들어감
큐의 기능 "선입선출'을 구현하는 것이라면 출력시 1 2 3 이렇게 출력이 되어야함
즉, s2가 3, 2, 1순서로 들어갔으므로 스택의 "선입후출"을 사용하여 pop하면 1,2,3 순서로 값들이 나오게됨

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef struct{
    int data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s){
    s->top = -1;
}
int is_empty(StackType *s){
    return (s->top == -1);
}
int is_full(StackType *s){
    return (s->top == MAX_STACK_SIZE-1);
}
void push(StackType *s, int item){
    if(is_full(s)){
        fprintf(stderr,"스택 포화 에러\n");
        exit(1);
    }
    else{
        s->data[++(s->top)] = item;
    }
}
int pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    else{
        return s->data[(s->top)--];
    }
}
void copy_stack(StackType *s1, StackType *s2){
    while(!is_empty(s1)){
        push(s2, pop(s1));
    }
}

int main(){
    StackType s1, s2;
    init_stack(&s1);
    init_stack(&s2);
    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);
    if(is_empty(&s2)){
        copy_stack(&s1, &s2);
    }
    while(!is_empty(&s2)){
        printf("%d ", pop(&s2));
    }
}
