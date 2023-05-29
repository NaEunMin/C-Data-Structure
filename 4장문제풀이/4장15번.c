#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6


/*

추가된 코드는 주석으로 추가된 코드라고 작성해놓음.
int i=0; // 경로를 저장하는 배열의 인덱스를 관리하기 위함
element road[MAX_STACK_SIZE] = {}; //경로를 저장하는 배열(구조체 배열)
road[i].r = r;   road[i++].c = c;  //위 배열에 경로를 저장함. 오른쪽 코드만 i++인 이유는 열,행 모두 저장한 후 다음인덱스에 좌표를 저장하기 위함.
for (int k = 0; k < i; k++)  //저장한 경로를 출력함.
printf("경로 : %d %d \n", road[k].r, road[k].c);

*/
typedef struct {
	short r;
	short c;
} element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;


void init_stack(StackType *s)
{
	s->top = -1;
}


int is_empty(StackType *s)
{
	return (s->top == -1);
}

int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}



element here = { 1,0 }, entry = { 1,0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{ '1', '1', '1', '1', '1', '1' },
{ 'e', '0', '1', '0', '0', '1' },
{ '1', '0', '0', '0', '1', '1' },
{ '1', '0', '1', '0', '1', '1' },
{ '1', '0', '1', '0', '0', 'x' },
{ '1', '1', '1', '1', '1', '1' },
};

void push_loc(StackType *s, int r, int c)
{
	if (r < 0 || c < 0) return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}

int main(void)
{
	int r, c;
	int i=0;//추가된 코드
	StackType s;
	element road[MAX_STACK_SIZE] = {};//추가된 코드


	init_stack(&s);
	here = entry;
	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		road[i].r = r; //추가된 코드
		road[i++].c = c;//추가된 코드
		maze_print(maze);
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);
		if (is_empty(&s)) {
			printf("실패\n");
			return 0;
		}
		else
			here = pop(&s);
	}
	printf("성공\n");
		for (int k = 0; k < i; k++) //추가된 코드
		printf("경로 : %d %d \n", road[k].r, road[k].c);//추가된 코드
	return 0;
}
