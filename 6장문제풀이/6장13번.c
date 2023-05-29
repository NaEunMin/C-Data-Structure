/******************************************************************************
                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/


/*

연결리스트 : 삭제에 대해 이해를 시켜주는 문제

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

ListNode* delete_node(ListNode *head, int data){
    ListNode *removed = head; //노드를 처음부터 접근하기 위함
    ListNode *p = NULL; //p는 removed의 전 노드를 가리키는 용도로 사용됨
    while(removed->data!=data){ //삭제대상 data를 만나기 전까지
        p = removed; //removed를 p에 복사(삭제대상을 못만난상황임)
        removed = removed->link; //다음 대상과 비교를 위해 removed다음 노드를 removed에 대입
    }
    if(p==NULL) head = head->link; //첫 노드가 삭제 대상인 경우
    else p->link = removed->link; //위의 경우가 아닌 경우
    free(removed); //메모리 반환으로 삭제
    return head;
}

int main()
{
    ListNode *head = NULL;
    int nodecount;
    int nodedata;
    int data;
    printf("노드의 개수->");
    scanf("%d", &nodecount);
    for(int i=1; i<=nodecount; i++){
        printf("노드 #%d 데이터 : ",i);
        scanf("%d", &nodedata);
        head = insert_last(head, nodedata);
    }
    
    print_list(head);
    printf("삭제할 데이터 : ");
    scanf("%d", &data);
    head = delete_node(head, data);
    print_list(head);
    return 0;
}
