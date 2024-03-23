#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
int top = -1;

element stack[MAX_STACK_SIZE];

int is_empty() {
	return (top == -1);
}
int is_full() {
	return (top == MAX_STACK_SIZE - 1);
}

void push(element item) {
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		stack[++top] = item;
}

int pop() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return stack[top--];
}

int peek() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return stack[top];
}

int main() {
	element item;
	char str[MAX_STACK_SIZE];
	int count = 1;
	printf("수식 : ");
	scanf("%s", str);

	printf("괄호 수 : ");
	for (int i = 0; i < MAX_STACK_SIZE; i++) {
		if (str[i] == '(') {
			push(count);
			printf("%d ", count);
			count++;
		}
		else if (str[i] == ')') {
			printf("%d ", pop());
		}
		if (str[i] == NULL)
			break;
	}
}
