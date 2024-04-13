#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct {
	element* data;
	int capacity; //현재 저장할 수 있는 스택의 크기
	int top; //가장 꼭대기 스택의 인덱스
} Stacktype;
void init_stack(Stacktype* s) {
	s->top = -1; //처음 스택 생성시 아무 요소가 존재하지 않으므로 -1
	s->capacity = 1; //현재 저장할 수 있는 스택의 크기가 1
	s->data = (element*)malloc(s->capacity * sizeof(element)); // 스택을 저장할 장소를 동적으로 할당
}
int is_empty(Stacktype* s) { //스택 공백 검출 함수
	return (s->top == -1); //스택이 존재하지 않는다
}
int is_full(Stacktype* s) { //스택 포화 검출 함수
	return (s->top == (s->capacity - 1));  //top은 인덱스 capacity는 크기이므로 -1을 빼주면서 검사
}
void push(Stacktype* s, element item) {
	if (is_full(s)) { //스택이 가득 차있다면
		s->capacity *= 2; //공간을 2배로 확장
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element)); //realloc함수는 이미 할당된 메모리의 크기를 변경할 때 사용한다.
	}
	s->data[++(s->top)] = item; //top은 꼭대기층의 인덱스를 나타내므로 증가 후 요소 저장
}
element pop(Stacktype* s) {
	if (is_empty(s)) { //스택이 비어있다면
		fprintf(stderr, "스택 공백 에러\n"); //에러 메시지 출력후
		exit(1); //프로그램 종료
	}
	else return s->data[(s->top)--]; //꼭대기 요소를 리턴하고 top을 감소시킨다.
}
element peek(Stacktype* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)]; //맨 꼭대기요소를 top를 감소시키지 않고 리턴만 한다.
}
int prex(char op) {
	switch (op) {//리턴값이 높을수록 우선순위권을 가진다
	case '(':case ')':return 0; 
	case '+':case '-':return 1;
	case '*':case '/':return 2;
	}
	return -1;
}
void infix_to_postfix(element *data) {
	Stacktype s;
	init_stack(&s); //스택을 초기화
	int size = strlen(data);
	char ch, top_op; //검사할 문자 ch, 괄호를 만났을때 스택에서 pop한 문자를 저장할 top_op
	for (int i = 0; i < size; i++) {
		ch = data[i];
		switch (ch) {
		case '+': case '-': case '*': case '/': //사칙연산자를 만났을때는 우선순위를 비교한다
			while (!is_empty(&s) && prex(ch) <= prex(peek(&s))) { //비교할 문자ch와 스택에 있는 문자를 비교 스택에 있는 문자가 우선순위가 있다면
				printf("%c", pop(&s)); //스택에서 pop하여 출력
			}
			push(&s, ch); //스택이 비워져있거나 스택에 있는 문자가 우선순위가 없다면 ch를 스택에 저장한다.
			break;
		case '(': //왼쪽 괄호인 경우
			push(&s, ch); //왼쪽 괄호는 무조건 스택에 저장한다.
			break;
		case ')': //우측 괄호인 경우
			top_op = pop(&s); //스택에 있는 연산자를 비워야 하니 저장
			while (top_op != '(') { //스택에 왼쪽 괄호 만날때 까지 계속 루프 진행
				printf("%c", top_op); //저장해둔 연산자를 출력
				top_op = pop(&s); //다음 연산자를 저장
			}
			break;
		default: //숫자인 경우
			printf("%c", ch);
			break;
		}
	}
	while (!is_empty(&s)) { //마지막에 남은 연산자들을 모두 출력한다.
		printf("%c", pop(&s));
	}
}
int main() {
	element *data = "4*3+8/2-2*2+((2+4)*6/3)-1";
	printf("중위표시수식 %s\n", data);
	printf("후위표시수식");
	infix_to_postfix(data);
}