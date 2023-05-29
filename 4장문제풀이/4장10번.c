/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

C++공부할때 스택을 다루었는데 그렇게 간단하게 말고 스택에 필요한 여러 전역함수들을 작성해보았다.

typedef int element; 이 코드의 필요성을 처음엔 몰랐는데 나중에 생각해보니 데이터타입만 바꾸어주면 element로만 작성할 수 있다는 장점이 있는 것 같다.

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 6
typedef int element;
int stack[MAX_STACK_SIZE];
int top=-1;

int is_empty() {
    return (top==-1);
}
int is_full() {
    return (top==MAX_STACK_SIZE-1);
}
void push(element item){
    if(is_full()){
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else stack[++top] = item;
}

element pop(){
    if(is_empty()){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top--];
}

element peek(){
    if(is_empty()){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top];
}

int main()
{
    element item;
    printf("정수 배열의 크기: %d\n", MAX_STACK_SIZE);
    printf("정수를 입력하시오: ");
    for(int i=0; i<MAX_STACK_SIZE; i++){
        scanf("%d", &item);
        push(item);
    }
    printf("반전된 정수 배열: ");
    for(int i=0; i<MAX_STACK_SIZE; i++){
        printf("%d ", pop());
    }

    return 0;
}
