/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


/*

insert_last()함수를 잘 이해해두면 좋을 문제.
insert_last(), print_list() 함수로 해결 가능한 문제

insert_last()함수는 주석을 참고

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *link;
}ListNode;

ListNode* insert_last(ListNode* head, int value){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode)); //새로운 노드 동적생성
    p->data = value; //새로운 노드의 데이터필드에 값 삽입
    p->link = NULL; //리스트의 마지막 노드이므로 다음 노드가 없어야 하므로 NULL
    if(head==NULL){ //처음 리스트에 노드를 추가하는 상황
        p->link = head; //p->link를 현재 head값으로 변경, 마지막 노드이므로 사실상 p->link = NULL
        head = p; //head를 p로 변경, head는 첫 번째 노드를 가리킴, 첫 추가이므로 p가 첫 번째 노드
    }
    else { //처음 추가가 아닌 상황
        ListNode *lastNode = head; //마지막노드를 구하려면 앞에서부터 탐색을 해야하므로 lastNode = head
        while(lastNode->link!= NULL) //앞에서부터 탐색하는데 마지막노드가 아니라면
            lastNode = lastNode->link; //앞에서부터 탐색하는 코드 
        lastNode->link = p; //lastNode는 head처럼 알려주는 표식과 같은 것. 추가한 노드p가 마지막 노드임을 알려줌.
    }
    return head;
}


void print_list(ListNode *head) {
    ListNode *p = head;
    while(p!=NULL) {
        printf("%d->",p->data);
        p=p->link;
    }
    printf("\n");
    
}



int main()
{
    ListNode *head = NULL;
    int nodecount;
    int nodedata;
    printf("노드의 개수->");
    scanf("%d", &nodecount);
    for(int i=1; i<=nodecount; i++){
        printf("노드 #%d 데이터 : ",i);
        scanf("%d", &nodedata);
        head = insert_last(head, nodedata);
    }
    
    printf("생성된 연결 리스트");
    print_list(head);

    return 0;
}
