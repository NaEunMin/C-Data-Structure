/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode* link;
}ListNode;

ListNode* add_node(ListNode *head, int value){
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

void print_node(ListNode* head){
    for(ListNode* p = head; p!=NULL; p = p->link){
        printf("%d->",p->data);
    }
    printf("\n");
}

ListNode* merge(ListNode *head1, ListNode *head2, ListNode *head){
    while(head1){
        head = add_node(head, head1->data);
        head1 = head1->link;
    }
    while(head2){
        head = add_node(head, head2->data);
        head2 = head2->link;
    }
    print_node(head);
    int temp; //정수를 임시보관하는 변수
    int min; //for문 1회 검사할때 가장작은 정수를 보관하는 변수
    ListNode *q = head; //for문 내부에서 앞에서부터 리스트 검사할때 필요한 변수
    ListNode *tmp = NULL; //q는 한번 검사완료하면 검사시작리스트에서 한칸 전진후 다시 끝까지 검사함. 이때 검사시작리스트를 저장하는 변수
    ListNode *target = head; //최소값이 저장되어있는 리스트를 저장하는 변수
    for(ListNode *p = head; p!=NULL; p = p->link){
        tmp = q; //q의 시작지점 저장
        target = q; //검사를 아직 시작하지않았으므로 시작지점이 최소값이므로 최소값 리스트 저장
        min = p->data; //검사를 아직 시작하지않았으므로 min은 첫번째 리스트
        while(q != NULL){
            if(min > q->data){ //리스트에서 최소값 검사하는 조건문
                min = q->data;
                target = q; //최소값리스트 저장
            }
            q = q->link; //for문 1회마다 리스트를 1번씩 검사함
        }
        temp = p->data; //최소값과 검사대상의 자리를 바꾸기위해 temp에 검사대상 저장
        if(min == temp){ //최소값과 검사대상이 같을 수도 있음.
            p->data = target->data; //최소값지점의 데이터를 저장
            q = tmp->link; //검사시작지점에서 한칸 전진
        }
        else{ //최소값과 검사대상의 자리가 다른경우
            p->data = target->data; //최소값지점의 데이터를 저장
            target->data = temp; //검사대상정수를 최소값지점의 데이터에 저장
            q = tmp->link; //검사시작지점에서 한칸 전진
        }

    }
    return head;
}
int main()
{
    ListNode *head1, *head2, *head;
    head1 = add_node(head1, 1);
    head1 = add_node(head1, 2);
    head1 = add_node(head1, 8);
    head1 = add_node(head1, 3);
    
    head2 = add_node(head2, 4);
    head2 = add_node(head2, 6);
    head2 = add_node(head2, 5);
    head2 = add_node(head2, 7);
    
    print_node(head1);
    print_node(head2);

    head = merge(head1, head2, head);
    print_node(head);
    return 0;
}