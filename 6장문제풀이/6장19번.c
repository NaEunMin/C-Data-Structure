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

void split(ListNode *Chead, ListNode* Ahead, ListNode* Bhead){
    ListNode *p = Chead;
    while(p!=NULL){
        if( (p->data)%2!=0 ){
            Ahead = add_node(Ahead, p->data);
        }
        else{
            Bhead = add_node(Bhead, p->data);
        }
        p = p->link;
    }
    print_node(Ahead);
    print_node(Bhead);
}
int main()
{
    ListNode *Ahead, *Bhead, *Chead;
    Chead = add_node(Chead,1);
    Chead = add_node(Chead,2);
    Chead = add_node(Chead,3);
    Chead = add_node(Chead,4);
    Chead = add_node(Chead,5);
    Chead = add_node(Chead,6);
    Chead = add_node(Chead,7);
    Chead = add_node(Chead,8);
    print_node(Chead);
    split(Chead, Ahead, Bhead);
    return 0;
}