/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

삽입함수와 원형 연결 리스트에서는 do-while문을 사용하는 것을 집중해서 보아야한다.

*/


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

ListNode* Search(ListNode *head, int data, int *check){
    ListNode *p = head->link; //원형 연결 리스트는 마지막 노드를 head로 지정하는 것을 기억하라.
    do{
        if(p->data == data){
            *check = 1; //찾으려는 값을 찾았다는 신호
            return p;
        }
        else{ //못찾았으면 다음 노드
            p = p->link;
        }
    }while(p!=head); //do-while문을 사용하는 이유는 끝이 없기 때문임.
    //마지막 노드 검사하는 부분
    if(p->data == data){ 
        *check = 1;
        return p;
    }
    else{
        printf("찾으려는 값이 존재하지 않음");
        *check = 0;
        return head;
    }
}
int main()
{
    ListNode *head;
    head = insert_last(head, 1);
    head = insert_last(head, 2);
    head = insert_last(head, 3);
    
    print_node(head);
    int check;
    ListNode* node = Search(head, 4, &check);
    if(check == 1){
        printf("\n%d", node->data);
    }
    return 0;
}
