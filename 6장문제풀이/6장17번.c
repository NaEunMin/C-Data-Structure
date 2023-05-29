/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

main문에 ahead, bhead 2개의 리스트를 만들어놓고 alternate()안에서 리스트 1개를 만들어서 옮기려고했다.
ap = ahead, bp = bhead라고 하고 ap->link, bp->link가 NULL인 경우와 아닌경우로 나누어서 해결하려고 접근했다.
여기서 문제점은 위 방식대로 하면 2개의 리스트중 하나라도 요소의 개수차이가 2개이상이면 해결이 안된다.
ex) a리스트=1,3 b리스트=2,4,6,8이라고하면 alternate()하면 1,2,3,4,6까지만 되고 8은 안된다. 왜냐하면 조건문에 다 ap->link, bp->link로 걸어놓았기 때문임.
조건문상황 자체를 a갔다가 b갔다가 이렇게 접근해서 발생한 문제같음.

*** 해결 방법 ***
조건문상황을 a가 NULL이 아니면, b가 NULL이 아니면 2가지로만 설정해서 접근해야한다.
위처럼 ->link로해서 NULL인경우 아닌경우해서 접근하면 4가지경우를 모두 고려해야하므로 코드가 복잡할 뿐더러 해결이 안된다.
||논리연산자를 사용해서 둘 중 1개라도 NULL이 아니면 반복하도록 해주면 된다.

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

ListNode *alternate(ListNode *head, ListNode *ahead, ListNode *bhead){
    while(ahead || bhead) { //두개의 리스트중 1개라도 NULL을 안만난경우
        if(ahead != NULL) {
            head = add_node(head, ahead->data);
            ahead = ahead->link;
        }
        if(bhead != NULL) {
            head = add_node(head,bhead->data);
            bhead = bhead->link;
        }
    }
    return head;
    //내가생각한 방법 경우의 수가 많다보니 코드가 복잡하고 논리가 잘못되었다.
  /*        head = add_node(head, ap->data);
        head = add_node(head, bp->data);
        
        if(ap->link != NULL){
            ap = ap->link;
        }
        else if(ap->link == NULL){
            bp = bp->link;
            head = add_node(head, bp->data);
        }
        if(ap->link==NULL && bp->link==NULL) break;
        
        if(bp->link != NULL){
            bp = bp->link;
        }
        else if(bp->link == NULL){
            ap = ap->link;
            head = add_node(head, ap->data);
        }
        if(ap->link==NULL && bp->link==NULL) break;
    }
    return head;*/ 
}

void print_node(ListNode* head){
    for(ListNode* p = head; p!=NULL; p = p->link){
        printf("%d->",p->data);
    }
    printf("\n");
}
int main()
{
    ListNode *head = NULL;
    ListNode *ahead = NULL;
    ListNode *bhead = NULL;
    
    ahead = add_node(ahead, 1);
    ahead = add_node(ahead, 3);
    ahead = add_node(ahead, 5);
    ahead = add_node(ahead, 7);
    
    bhead = add_node(bhead,2);
    bhead = add_node(bhead,4);
    bhead = add_node(bhead,6);
    bhead = add_node(bhead,8);
    bhead = add_node(bhead,10);
    bhead = add_node(bhead,12);
    
    print_node(ahead);
    print_node(bhead);
    
    head = alternate(head, ahead, bhead);

    print_node(head);

    return 0;
}
