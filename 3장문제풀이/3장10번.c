/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*
array[n-1] = 0; 맨 뒤에 있었던 요소 앞으로 한칸씩 이동해서 사라질 것이다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int delete(int array[], int loc, int size) {
	for (int i = loc; i < size-1; i++) {
		array[i] = array[i + 1];
	}
	array[size-1] = 0;
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
	delete(array, 2, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
}
