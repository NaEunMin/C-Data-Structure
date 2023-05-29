/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

add_node()함수 작성시 while(lastnode->link!=NULL) 부분에서 ->link를 빼먹는 실수를 하지 않도록 주의하자.

*/

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

ListNode* add_node(ListNode *head, element value){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    if(head==NULL){
        p->link = head;
        head = p;
    }
    else{
        ListNode* lastnode = head;
        while(lastnode->link!=NULL){
            lastnode = lastnode->link;
        }
        lastnode->link = p;
        return head;
    }
}

void print_node(ListNode *head){
    for(ListNode *p = head; p!=NULL; p=p->link){
        printf("%d->",p->data);
    }
}

void find_MAX_MIN(ListNode *head){
    int max,min;
    ListNode *p = head;
    max = p->data;
    min = p->data;
    for(p=head; p!=NULL; p=p->link){
        if(max < p->data){
            max = p->data;
        }
    }
    for(p=head; p!=NULL; p=p->link){
        if(min > p->data){
            min = p->data;
        }
    }
    
    printf("리스트 내 최대값:%d \n", max);
    printf("리스트 내 최소값:%d \n", min);
}

int main(){
    ListNode *head = NULL;
    head = add_node(head, 5);
    head = add_node(head, 1);
    head = add_node(head, 3);
    head = add_node(head, 2);
    head = add_node(head, 4);
    
    print_node(head);
    printf("\n");
    find_MAX_MIN(head);
    
}
