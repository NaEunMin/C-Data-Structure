/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

pow()함수는 math.h에 있는 제곱구해주는 함수로
잘 이용하면 해결하는데 문제가 없었던 문제

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct ListNode {
    int coef;
    int expon;
    struct ListNode *link;
}ListNode;
typedef struct ListType {
    int size;
    ListNode *head;
    ListNode *tail;
}ListType;

//리스트 헤더 생성 함수
ListType *create() {
    ListType *plist = (ListType*)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

//plist는 연결 리스트의 헤더를 가리키는 포인터, coef는 계수, expon는 지수
void insert_last(ListType *plist, int coef, int expon) {
    ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
    if(temp == NULL) {fprintf(stderr,"alloc error\n"); exit(1);}
    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;
    if(plist->tail == NULL) {
        plist->head = plist->tail = temp;
    } else {
        plist->tail->link = temp;
        plist->tail = temp;
    }
    plist->size++;
}

void poly_print(ListType *plist) {
    ListNode *p = plist->head;
    printf("poly: ");
    for(;p;p=p->link)
        printf("%d^%d + ",p->coef,p->expon);
    printf("\n");
}

int poly_eval(ListType *plist, int input){
    int result;
    int sum = 0;
    ListNode *p = plist->head;
    while(p!=NULL){
        result = (p->coef)*pow(input, p->expon); //pow()함수는 math.h에 있는 제곱구해주는 함수
        sum = sum+result;
        p = p->link;
    }
    return sum;
}
int main() {
    ListType *list1;
    list1 = create();

//다항식 1 생성
    insert_last(list1, 3,6);
    insert_last(list1,7,3);
    insert_last(list1,-2,2);
    insert_last(list1,-9,0);
    
    poly_print(list1);
    printf("%d", poly_eval(list1, 2));


    return 0;
}
