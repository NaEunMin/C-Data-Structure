/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

6-6)부분을 참고

*/

#include<stdio.h>
#include<stdlib.h>

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

//list3 = list1 + list2
void poly_add(ListType *plist1, ListType *plist2, ListType *plist3) {
    ListNode *a = plist1->head;
    ListNode *b = plist2->head;
    int sum;
    while(a&&b) {
        if(a->expon == b->expon) { //a의 차수 > b의 차수
            sum = a->coef + b->coef;
            if(sum!=0) insert_last(plist3,sum,a->expon);
            a = a->link; b = b->link;
        } else if(a->expon > b->expon) { //a의 차수 == b의 차수
            insert_last(plist3,a->coef,a->expon);
            a = a->link;
        } else { //a의 차수 < b의 차수
            insert_last(plist3,b->coef,b->expon);
            b = b->link;
        }
    }
    //a나 b중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두 결과 다항식으로 복사
    for(;a!=NULL;a=a->link)
        insert_last(plist3,a->coef,a->expon);
    for(;b!=NULL;b=b->link)
        insert_last(plist3,b->coef,b->expon);
}


void poly_print(ListType *plist) {
    ListNode *p = plist->head;
    printf("poly: ");
    for(;p;p=p->link)
        printf("%d^%d + ",p->coef,p->expon);
    printf("\n");
}

int main() {
    ListType *list1, *list2,*list3;
    list1 = create();
    list2 = create();
    list3 = create();

//다항식 1 생성
    insert_last(list1, 3,6);
    insert_last(list1,7,3);
    insert_last(list1,-2,2);
    insert_last(list1,-9,0);

//다항식 2 생성
    insert_last(list2, -2,6);
    insert_last(list2,-4,4);
    insert_last(list2,6,2);
    insert_last(list2,6,1);
    insert_last(list2,1,0);

//다항식 3 = 다항식 1 + 다항식 2
    poly_print(list1);
    poly_print(list2);
    poly_add(list1,list2,list3);
    poly_print(list3);
    return 0;
}
