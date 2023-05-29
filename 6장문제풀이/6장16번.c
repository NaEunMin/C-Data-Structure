/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

*** 내가 처음 생각한 방식 ***
' /2 != 0'을 사용하여 각 노드마다 번호를 부여하고 그 번호를 연산하여 홀수만 삭제하는 방식을 생각했다.

*** 다른 해결 방식 ***
코드에 있는 방식으로 link만 옮겨주는 방식으로 처음에 p에 removed를 복사함으로 시작하는 방식

*/

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

ListNode* delete_node(ListNode *head) { //free()함수로 삭제하는 것이 아닌 link만 옮겨주는 방식. 출력을 위함이므로 굳이 free()를 사용하지 않아도됨.
    head = head->link; //첫 번째 노드를 삭제하는 코드
    ListNode *p = NULL;
    ListNode *removed = head; //앞에서부터 탐색하기 위한 코드
    while(removed->link != NULL) {
        p = removed; //removed를 p에 복사
        removed = removed->link; //노드를 건너뛰기위한 준비단계 코드. removed다음노드를 삭제대상으로 지정
        p->link = removed->link; //핵심코드. p가 필요한 이유가 나오는 코드. removed다음노드와 p를 이어줌으로 removed를 리스트에서 제외시킴.
        if(removed->link !=NULL) //노드가 끝이 아닌 경우
            removed = removed->link; //계속해서 탐색
        else break;
    }
    return head;
}

void print_node(ListNode* head){
    for(ListNode* p = head; p!=NULL; p = p->link){
        printf("%d->",p->data);
    }
}
int main()
{
    ListNode *head = NULL;
    
    head = add_node(head, 1);
    head = add_node(head, 2);
    head = add_node(head, 3);
    head = add_node(head, 4);
    head = add_node(head, 5);
    print_node(head);
    
    head = delete_node(head);
    printf("\n");
    print_node(head);

    return 0;
}
