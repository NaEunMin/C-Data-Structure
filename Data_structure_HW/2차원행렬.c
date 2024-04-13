#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows; 
    int cols; 
    int value; 
}element;

typedef struct {
    element* data;
    int rows;//0을 제외한 값의 행 위치를 저장하는 변수
    int cols;//0을 제외한 값의 열 위치를 저장하는 변수
    int index; //항의 개수
}SparseMatrix;


int** make2DMatrix(int rows, int cols) { //2차원배열 동적할당 함수
    int** arr = (int**)malloc(sizeof(int*) * rows); //행
    for (int i = 0; i < rows; i++) { //열
        arr[i] = (int*)malloc(sizeof(int) * cols);
    }
    return arr;
}
void sparse2DMatrix(int** arr, SparseMatrix *matrix, int rows, int cols) { //0이 아닌 값만 저장하는 2차원 배열
    int index = 0;//값을 얼마나 저장했는지 알아낼 장치j
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (arr[i][j] != 0) { //저장한 2차원 행렬에서 값이 0이 아니라면 행,열,값을 저장함
                matrix->data[index].rows = i;
                matrix->data[index].cols = j;
                matrix->data[index].value = arr[i][j];
                matrix->index++;
                matrix->rows++;
                matrix->cols++;
                index++;
            }
        }
    }
}
void input2DMatrixValue(int** arr, int rows, int cols) { // 사용자로부터 값 입력받는 함수
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("행%d, 열%d에 들어갈 값>>", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}
void print_sparseMatrix(SparseMatrix *matrix) { //0이 아닌 값만 저장한 2차원 행렬을 출력하는 함수
    for (int i = 0; i < matrix->index; i++) {
        printf("matrix[%d][%d] = %d", matrix->data[i].rows, matrix->data[i].cols, matrix->data[i].value);
        printf("\n");
    }
    printf("\n");
}
void print2DMatrix(int** arr, int rows, int cols) { //행렬 전체를 저장한 행렬을 출력하는 함수
    for (int i = 0; i < rows; i++) {
        printf("\n");
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n");
}
void printMemoryUsage(int rows, int cols, SparseMatrix *matrix) {
    int size_2DMatrix = sizeof(int) * rows * cols; // 2차원 배열의 메모리 크기 계산
    int size_elementMatrix = sizeof(element) * (matrix->index);//sizeof(int) *(matrix.rows) * (matrix.cols); // 0을 제외한 항만 저장한 구조체 배열의 메모리 크기 계산
    printf("2차원 배열이 사용한 메모리 크기: %d 바이트\n", size_2DMatrix);
    printf("0이 아닌 요소만 저장한 배열이 사용한 메모리 크기: %d 바이트\n", size_elementMatrix);
}
void printMatrixMemoryAddress(int **arr, int rows, int cols) {
    int count = 0;
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (count == 6) {
                return;
            }
            printf("matrix[%d][%d] = %d (%u)\n", i, j, arr[i][j], &arr[i][j]);
            count++;
        }
    }
}
void run2DMatrixSystem() { //행렬을 다루는 시스템을 시작하는 함수
    int rows;
    int cols;
    int choice;
    while (1) {
        printf("1: 행렬프로그램 시작, 2: 종료 >>");
        scanf("%d", &choice);
        if (choice == 2) break;
        printf("저장할 2차원 행렬의 행과 열의 수를 입력하시오>>");
        scanf("%d %d", &rows, &cols);
        if (choice == 1) { //행렬 전체를 저장, 0이 아닌 항만 저장후 행렬 출력과 함께 메모리 사용량 출력
            int** arr = make2DMatrix(rows, cols);
            input2DMatrixValue(arr, rows, cols);
            print2DMatrix(arr, rows, cols);
            SparseMatrix sparsematrix;
            sparsematrix.data = (element*)malloc(sizeof(element) * (rows * cols));
            sparsematrix.rows = 0;
            sparsematrix.cols = 0;
            sparsematrix.index = 0;
            sparse2DMatrix(arr, &sparsematrix, rows, cols);
            print_sparseMatrix(&sparsematrix);
            printMemoryUsage(rows, cols, &sparsematrix);
            printMatrixMemoryAddress(arr, rows, cols);
            for (int i = 0; i < rows; i++) {
                free(arr[i]);
            }
            free(arr);
            free(sparsematrix.data);
        }
    }
}

int main() {
    run2DMatrixSystem();

    return 0;
}
