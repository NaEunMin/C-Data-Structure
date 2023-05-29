#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

/*

*** 문제조건 ***
1. 스페이스는 무시한다 ===> 즉, 공백을 포함한 문자열 입력이 가능해야한다.
 gets(문자열) : 공백을 포함한 문자열 입력 가능 함수
2. 구두점, 대소문자는 무시한다 ===> 즉, 알파벳만 스택에 들여오되 대소문자는 무시한다.
strlwr(문자열) : 문자열을 소문자로 바꾼다.
if('a'<= input[i] && 'z'>= input[i]) 알파벳만 취급하는 조건문

*/
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

void strlwr(char str[]){ //웹 컴파일러는 지원을 안해서 웹서핑해서 가져옴
    int i=0;
    while(str[i]){
        if(str[i]>='A' && str[i]<='Z'){
            str[i]=str[i]+32;
        }       
        i++;
    }
}
int main(){
    StackType s1;
    int check; //문자가 같은지 다른지 검사하기 위한 장치
    char input[MAX_STACK_SIZE] = {};
    init_stack(&s1);
    
    printf("문자열을 입력하시오: ");
    gets(input); //공백을 포함한 문자열 입력 함수
    strlwr(input);// 문자열을 소문자로 변환해주는 함수
    for(int i=0; i<strlen(input); i++){ //input길이 만큼 반복문 실행
        if('a'<= input[i] && 'z'>= input[i]){ //소문자알파벳만 다루는 조건문
        push(&s1, input[i]);// 위 조건 맞으면 push
        }
    }
    
    int i = 0;
    while(input[i]!=NULL){ //input이 끝에 다다르기 까지
        if('a'<= input[i] && 'z'>= input[i]){ //input은 공백, 구두점이 남아 있기 때문에 필요한 조건문
        if(pop(&s1)==input[i]){ //선입후출의 특성 이용, s1의 뒤에 input의 앞을 비교
            check = 1; //문자가 같음
        }
        else{
            check = 0; //문자가 다름
        }
        if(check == 0){ //문자가 다르다면 더 이상 검사를 진행하지 않아도 되므로 break;
            printf("회문이 아닙니다.\n");
            break;
        }
    }
    i++; //다음 input과 비교
}
    if(check ==1 ){ //위 반복문 실행의 check = 1이라면 회문이라는 뜻
        printf("회문입니다.\n");
    }
    return 0;
}
