/*
*** 문자,정수 바꾸기 ***
문자가 숫자의 형태일 경우 : 문자 - '0' => 정수 문자 ex) (char)1 - '0' => (int)1
반대도 가능하다. ex) (int)1 + '0' => (char)1

*** 스택 부분***
12번과 유사한 구조
-peek()사용시 : push하자마자 출력
-peek()미사용시 : s1에 push하고 s2에 s1을 pop해서 push //선입후출의 구조를 이용하기 위함

*** 숫자 검사하는데 now가 char형인 이유***
input배열이 char형인 이유가 동일 : int형 배열은 Enter키로 입력을 멈출 수 없음. char형배열 즉, 문자열은 가능함.
위 문자,정수 바꾸기를 사용하여 스택에 push함.

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef struct{
    int stack[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s){
    s->top = -1;
}

int is_full(StackType *s){
    return (s->top == MAX_STACK_SIZE-1);
}

int is_empty(StackType *s){
    return (s->top == -1);
}

void push(StackType *s, int item){
    if(is_full(s)){
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else{
        s->stack[++(s->top)] = item;
    }
}

int pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else{
        return s->stack[(s->top)--];
    }
}

int peek(StackType *s){
    return s->stack[(s->top)];
}
int main(){
    StackType s1, s2;
    init_stack(&s1);
    init_stack(&s2);
    char input[MAX_STACK_SIZE] = {}; //char형인 이유: int형배열은 입력도중 Enter키로 끊을 수 없음. char형배열 즉, 문자열은 가능함.
    printf("정수를 입력하세요: ");
    scanf("%s",input);
    printf("출력: ");
    int i=0;
    push(&s1, input[i]-'0'); // -'0'을 사용하는 이유가 문자열형태로 숫자를 입력받았기 때문에 정수형태로 변환하여 스택에 push하기 위함.
    //printf("%d", peek(&s1)); //peek()함수 사용한다면 필요한 코드
    while(input[i]!=NULL){ //input배열이 끝에 도달하지 않았다면
        char now = input[i]; //input배열은 문자열이므로 검사할 숫자 형태도 char형 변수인 now로 선언함.
        i++; //다음 인덱스와 비교하기 위해 i를 증가
        if(input[i]==NULL){ //다음 인덱스가 끝이라면 반복문 중지.
            break;
        }
        if(now!=input[i]){ //now와 다음 인덱스가 다르다면
            push(&s1, input[i]-'0'); //스택에 푸쉬
            //printf("%d", peek(&s1)); //peek()함수 사용한다면 필요한 코드
        }
    }
    while(!is_empty(&s1)){ //선입후출의 구조를 이용하기 위한 코드. s1스택이 비어있지 않다면
        push(&s2, pop(&s1)); //s2에 s1를 pop하여 push
    }
    while(!is_empty(&s2)){ //s2가 비어있지않다면
        printf("%d", pop(&s2)); //s2를 pop하여 출력
    }
    return 0;
    
}
