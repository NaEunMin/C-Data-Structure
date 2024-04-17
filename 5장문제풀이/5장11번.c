/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


/*

*** 4장 스택 16번문제와 유사한 문제 ***
알고리즘은 알고있으니 "스택->원형 덱" 전환이 핵심

*** 새로운 알고리즘 ***
스택 : 삽입과 삭제의 장소가 1개이다. // input으로 부터 전달받은 스택의 크기에 상관이 없다.
원형 덱 : 삽입과 삭제의 장소가 2개이다. // input으로 부터 전달받은 덱의 크기에 상관이 있다.
--> 짝수, 홀수에 연관이 있다.
짝수 : 비교를 할때 2개씩 비교를 하므로 마지막에 남는 문자가 없다.
홀수 : 비교를 할때 2개씩 비교를 하므로 마지막에 남는 문자가 있다. // 하지만 1개만 남으므로 비교할 의미가 없다. 2개씩 다 같은 문자였다면 어차피 회문이다.

*** 위 문제를 해결하기 위해 작성한 코드 ***
  while(!(length==0 || length==1)){ //length는 input으로부터 전달받은 덱의 크기임.
        if(delete_front(&q)==delete_rear(&q)){
            check = 1;
            length-=2; //2개씩 비교하므로 -2
        }

*** 실수한 부분 ***
삭제함수 구현이 스택,큐,덱 모두 "반환 후 삭제" 알고리즘이다.
delete_rear구현 시
        int temp = q->rear;
        q->rear = ((q->rear-1)+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
        return q->data[temp];
위 코드처럼 가야하는데 temp안하고 return q->data[q->rear]이렇게 작성하면 삭제 후 그 다음 문자를 리턴하기 때문이다.

*/
//strlwr 오류를 무시하기 위해 #define _CRT_NONSTDC_NO_WARNINGS를 적어주었다.
//이전에 적은 코드보다 더 이해하기 쉬운 코드로 풀어서 다시 코드를 업로드하였다.
//이전의 코드
/* 
      int length=0; //옮긴 문자열의 크기
    int check;
    for(int i=0; i<strlen(input); i++){ //input길이 만큼 반복문 실행
        if('a'<= input[i] && 'z'>= input[i]){ //소문자알파벳만 다루는 조건문
        add_rear(&q, input[i]);// 위 조건 맞으면 삽입
        length++;
        }
    }
    
    while(!(length==0 || length==1)){
        if(delete_front(&q)==delete_rear(&q)){
            check = 1;
            length-=2;
        }
        else{
            printf("회문이 아닙니다.");
            return 0;
        }
    }
    if(check==1){
        printf("회문입니다.");
    }
    return 0;
*/
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 10
typedef char element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front;
	int rear;
}QueueType;
void error(char* s) {
	fprintf(stderr, "%s", s);
	exit(1);
}
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}
int is_empty(QueueType* q) {
	return q->front == q->rear;
}
int is_full(QueueType* q) {
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}
void add_rear(QueueType* q, element item) {
	if (is_full(q)) {
		error("큐 포화 에러");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
void add_front(QueueType* q,  element item) {
	if (is_full(q)) {
		error("큐 포화 에러");
	}
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}
element delete_rear(QueueType* q) {
	if (is_empty(q)) {
		error("큐 공백 에러");
	}
	int index = q->rear;
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[index];
}
element delete_front(QueueType* q) {
	if (is_empty(q)) {
		error("큐 공백 에러");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
element get_rear(QueueType* q) {
	if (is_empty(q)) {
		error("큐 공백 에러");
	}
	return q->data[q->rear];
}
element get_front(QueueType* q) {
	if(is_empty(q)) {
		error("큐 공백 에러");
	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
int main() {
	QueueType q;
	init_queue(&q);
	int check;
	char input[MAX_QUEUE_SIZE];
	printf("검사할 문자열을 입력하시오>>");
	scanf("%s", &input);
	strlwr(input); //문자열을 소문자로 변경시키는 함수
	int size = strlen(input);
	for (int i = 0; i < size; i++) {
		add_rear(&q, input[i]);
	}
	for (int i = 0; i < size / 2; i++) {
		if (delete_front(&q) == delete_rear(&q)) {
			check = 1;
		}
		else {
			printf("회문이 아닙니다.");
			return;
		}
	}
	printf("회문입니다.");
}
