/*

*** 대소문자 변경 ***
-아스키코드 : (대문자와 소문자의 아스키코드값차이=32) =====> 대문자+32=소문자, 소문자-32=대문자
-tolower,toupper : #include <ctype.h>
toupper(문자) : 문자가 소문자일때 대문자로 변환
tolower(문자): 문자가 대문자일때 소문자로 변환

*** 스택부분 ***
2개의 스택 필요
s1스택: 처음정보를 저장할 스택
s2스택: 선입후출의 구조로 인해 s1의 스택을 pop하여 저장할 스택
push와 pop만을 사용한다면 위 2개의 스택이 필요함. 주석처리된 코드도 필요함.
peek를 사용한다면 1개의 스택만 있으면됨. 주석처리된 코드 필요없음
s1스택에 저장하자마자 printf("%c", peek(&s1))을 해주면서 출력을 하면됨.

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef struct{
    char stack[MAX_STACK_SIZE];
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

void push(StackType *s, char item){
    if(is_full(s)){
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else{
        s->stack[++(s->top)] = item;
    }
}

char pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else{
        return s->stack[(s->top)--];
    }
}

char peek(StackType *s){
    return s->stack[(s->top)];
}
int main(){
    char input[MAX_STACK_SIZE] = {};
    StackType s1, s2; //peek()함수를 사용하면 스택2개는 필요없다. 1개만 있으면 충분하다
    init_stack(&s1);
    init_stack(&s2);
    printf("문자열을 입력하시오: ");
    scanf("%s", input);
    printf("압축된 문자열: ");
    int i=0; int count;
    while(input[i]!=NULL){
        count=0;//해당 알파벳이 몇번 나왔는지 체크함
        char now = input[i];//검사할 알파벳 저장
        while(now == input[i] || now+32 == input[i] || now-32 == input[i]){ //대문자이든 소문자이든 상관없이 count. 
            count++;
            i++; //다음 인덱스를 now와 검사
        }
        push(&s1, count+'0'); //count를 문자취급해줌
        printf("%c", peek(&s1));
        if(now>='a' && now<='z'){
            push(&s1, now);
        }
        else{
            push(&s1, now-32);
        }
        printf("%c", peek(&s1));
    }
    /*
    while(!is_empty(&s1)){
        push(&s2, pop(&s1));
    }
    while(!is_empty(&s2)){
        printf("%c", pop(&s2));
    }*/
    return 0;
    
}
