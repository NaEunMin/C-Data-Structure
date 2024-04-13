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
    int rows;//0�� ������ ���� �� ��ġ�� �����ϴ� ����
    int cols;//0�� ������ ���� �� ��ġ�� �����ϴ� ����
    int index; //���� ����
}SparseMatrix;


int** make2DMatrix(int rows, int cols) { //2�����迭 �����Ҵ� �Լ�
    int** arr = (int**)malloc(sizeof(int*) * rows); //��
    for (int i = 0; i < rows; i++) { //��
        arr[i] = (int*)malloc(sizeof(int) * cols);
    }
    return arr;
}
void sparse2DMatrix(int** arr, SparseMatrix *matrix, int rows, int cols) { //0�� �ƴ� ���� �����ϴ� 2���� �迭
    int index = 0;//���� �󸶳� �����ߴ��� �˾Ƴ� ��ġj
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (arr[i][j] != 0) { //������ 2���� ��Ŀ��� ���� 0�� �ƴ϶�� ��,��,���� ������
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
void input2DMatrixValue(int** arr, int rows, int cols) { // ����ڷκ��� �� �Է¹޴� �Լ�
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("��%d, ��%d�� �� ��>>", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}
void print_sparseMatrix(SparseMatrix *matrix) { //0�� �ƴ� ���� ������ 2���� ����� ����ϴ� �Լ�
    for (int i = 0; i < matrix->index; i++) {
        printf("matrix[%d][%d] = %d", matrix->data[i].rows, matrix->data[i].cols, matrix->data[i].value);
        printf("\n");
    }
    printf("\n");
}
void print2DMatrix(int** arr, int rows, int cols) { //��� ��ü�� ������ ����� ����ϴ� �Լ�
    for (int i = 0; i < rows; i++) {
        printf("\n");
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n");
}
void printMemoryUsage(int rows, int cols, SparseMatrix *matrix) {
    int size_2DMatrix = sizeof(int) * rows * cols; // 2���� �迭�� �޸� ũ�� ���
    int size_elementMatrix = sizeof(element) * (matrix->index);//sizeof(int) *(matrix.rows) * (matrix.cols); // 0�� ������ �׸� ������ ����ü �迭�� �޸� ũ�� ���
    printf("2���� �迭�� ����� �޸� ũ��: %d ����Ʈ\n", size_2DMatrix);
    printf("0�� �ƴ� ��Ҹ� ������ �迭�� ����� �޸� ũ��: %d ����Ʈ\n", size_elementMatrix);
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
void run2DMatrixSystem() { //����� �ٷ�� �ý����� �����ϴ� �Լ�
    int rows;
    int cols;
    int choice;
    while (1) {
        printf("1: ������α׷� ����, 2: ���� >>");
        scanf("%d", &choice);
        if (choice == 2) break;
        printf("������ 2���� ����� ��� ���� ���� �Է��Ͻÿ�>>");
        scanf("%d %d", &rows, &cols);
        if (choice == 1) { //��� ��ü�� ����, 0�� �ƴ� �׸� ������ ��� ��°� �Բ� �޸� ��뷮 ���
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
