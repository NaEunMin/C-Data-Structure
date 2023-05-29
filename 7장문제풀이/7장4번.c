/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *link;
}ListNode;

void print_node(ListNode *head){
    ListNode *p;
    
    if(head==NULL) return;
    p = head->link;
    do{
        printf("%d->", p->data);
        p = p->link;
    }while( p!= head);
    printf("%d->", p->data);
}

ListNode* insert_last(ListNode *head, int data){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if(head==NULL){
        head = node;
        node->link = head;
    }
    else{
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

int get_size(ListNode *head){
    int size = 0;
    ListNode *p = head->link;
    do{
        if(p!=NULL){
            size++; //검사 대상 노드가 NULL이 아니면 데이터존재
            p = p->link;
        }
    }while(p!=head);
    //마지막 노드 검사
    if(p!=NULL){
        size++;
    }
    return size;
}
int main()
{
    ListNode *head;
    head = insert_last(head, 1);
    head = insert_last(head, 2);
    head = insert_last(head, 3);
    head = insert_last(head, 4);
    
    print_node(head);
    printf("\nsize=%d",get_size(head));
    return 0;
}
