#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct {
	element* data;
	int capacity; //���� ������ �� �ִ� ������ ũ��
	int top; //���� ����� ������ �ε���
} Stacktype;
void init_stack(Stacktype* s) {
	s->top = -1; //ó�� ���� ������ �ƹ� ��Ұ� �������� �����Ƿ� -1
	s->capacity = 1; //���� ������ �� �ִ� ������ ũ�Ⱑ 1
	s->data = (element*)malloc(s->capacity * sizeof(element)); // ������ ������ ��Ҹ� �������� �Ҵ�
}
int is_empty(Stacktype* s) { //���� ���� ���� �Լ�
	return (s->top == -1); //������ �������� �ʴ´�
}
int is_full(Stacktype* s) { //���� ��ȭ ���� �Լ�
	return (s->top == (s->capacity - 1));  //top�� �ε��� capacity�� ũ���̹Ƿ� -1�� ���ָ鼭 �˻�
}
void push(Stacktype* s, element item) {
	if (is_full(s)) { //������ ���� ���ִٸ�
		s->capacity *= 2; //������ 2��� Ȯ��
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element)); //realloc�Լ��� �̹� �Ҵ�� �޸��� ũ�⸦ ������ �� ����Ѵ�.
	}
	s->data[++(s->top)] = item; //top�� ��������� �ε����� ��Ÿ���Ƿ� ���� �� ��� ����
}
element pop(Stacktype* s) {
	if (is_empty(s)) { //������ ����ִٸ�
		fprintf(stderr, "���� ���� ����\n"); //���� �޽��� �����
		exit(1); //���α׷� ����
	}
	else return s->data[(s->top)--]; //����� ��Ҹ� �����ϰ� top�� ���ҽ�Ų��.
}
element peek(Stacktype* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)]; //�� ������Ҹ� top�� ���ҽ�Ű�� �ʰ� ���ϸ� �Ѵ�.
}
int prex(char op) {
	switch (op) {//���ϰ��� �������� �켱�������� ������
	case '(':case ')':return 0; 
	case '+':case '-':return 1;
	case '*':case '/':return 2;
	}
	return -1;
}
void infix_to_postfix(element *data) {
	Stacktype s;
	init_stack(&s); //������ �ʱ�ȭ
	int size = strlen(data);
	char ch, top_op; //�˻��� ���� ch, ��ȣ�� �������� ���ÿ��� pop�� ���ڸ� ������ top_op
	for (int i = 0; i < size; i++) {
		ch = data[i];
		switch (ch) {
		case '+': case '-': case '*': case '/': //��Ģ�����ڸ� ���������� �켱������ ���Ѵ�
			while (!is_empty(&s) && prex(ch) <= prex(peek(&s))) { //���� ����ch�� ���ÿ� �ִ� ���ڸ� �� ���ÿ� �ִ� ���ڰ� �켱������ �ִٸ�
				printf("%c", pop(&s)); //���ÿ��� pop�Ͽ� ���
			}
			push(&s, ch); //������ ������ְų� ���ÿ� �ִ� ���ڰ� �켱������ ���ٸ� ch�� ���ÿ� �����Ѵ�.
			break;
		case '(': //���� ��ȣ�� ���
			push(&s, ch); //���� ��ȣ�� ������ ���ÿ� �����Ѵ�.
			break;
		case ')': //���� ��ȣ�� ���
			top_op = pop(&s); //���ÿ� �ִ� �����ڸ� ����� �ϴ� ����
			while (top_op != '(') { //���ÿ� ���� ��ȣ ������ ���� ��� ���� ����
				printf("%c", top_op); //�����ص� �����ڸ� ���
				top_op = pop(&s); //���� �����ڸ� ����
			}
			break;
		default: //������ ���
			printf("%c", ch);
			break;
		}
	}
	while (!is_empty(&s)) { //�������� ���� �����ڵ��� ��� ����Ѵ�.
		printf("%c", pop(&s));
	}
}
int main() {
	element *data = "4*3+8/2-2*2+((2+4)*6/3)-1";
	printf("����ǥ�ü��� %s\n", data);
	printf("����ǥ�ü���");
	infix_to_postfix(data);
}