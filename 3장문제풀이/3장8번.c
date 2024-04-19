/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void insert(int array[],int value, int loc, int size) {
	for (int i = size - 2; i >= loc; i--) {
		array[i + 1] = array[i];
	}
	array[loc] = value;
}
int main() {
	int* array;
	int size;
	printf("배열의 크기를 입력>>");
	scanf("%d", &size);
	array = (int*)malloc(sizeof(int) * size);
	printf("배열의 요소를 입력>>");
	for (int i = 0; i < size; i++) {
		scanf("%d", &array[i]);
	}
	insert(array, 10, 2, size);
	for (int i = 0; i < 5; i++) {
		printf("%d ", array[i]);
	}
}
