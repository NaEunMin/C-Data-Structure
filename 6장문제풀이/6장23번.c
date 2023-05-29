/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

9번문제의 insert_last()함수와 18번문제의 merge()함수를 사용하여 해결
*** add()함수의 작동구조 ***
1. insert_last()함수로 노드를 추가한다.
2. merge()함수로 리스트를 오름차순 정렬을 한다.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct SortedList{
    int data;
    struct SortedList *link;
}SortedList;

/*
SortedList* insert_node(SortedList* head, int item){
    SortedList *new = (SortedList*)malloc(sizeof(SortedList)); //새로운 노드 동적생성
    new->data = item; //새로운 노드의 데이터필드에 값 삽입
    new->link = NULL; //리스트의 마지막 노드이므로 다음 노드가 없어야 하므로 NULL
    if(head==NULL){ //처음 리스트에 노드를 추가하는 상황
        new->link = head; //p->link를 현재 head값으로 변경, 마지막 노드이므로 사실상 p->link = NULL
        head = new; //head를 p로 변경, head는 첫 번째 노드를 가리킴, 첫 추가이므로 p가 첫 번째 노드
    }
    else { //처음 추가가 아닌 상황
        SortedList *lastNode = head; //마지막노드를 구하려면 앞에서부터 탐색을 해야하므로 lastNode = head
        while(lastNode->link!= NULL) //앞에서부터 탐색하는데 마지막노드가 아니라면
            lastNode = lastNode->link; //앞에서부터 탐색하는 코드 
        lastNode->link = new; //lastNode는 head처럼 알려주는 표식과 같은 것. 추가한 노드p가 마지막 노드임을 알려줌.
    }
    return head;
}*/
SortedList* add(SortedList *head, int item){
    SortedList *new = (SortedList*)malloc(sizeof(SortedList)); 
    new->data = item; 
    new->link = NULL; 
    if(head==NULL){ 
        new->link = head; 
        head = new; 
    }
    else { 
        SortedList *lastNode = head;
        while(lastNode->link!= NULL) 
            lastNode = lastNode->link; 
        lastNode->link = new; 
    }
    
    int temp; //정수를 임시보관하는 변수
    int min; //for문 1회 검사할때 가장작은 정수를 보관하는 변수
    SortedList *q = head; //for문 내부에서 앞에서부터 리스트 검사할때 필요한 변수
    SortedList *tmp = NULL; //q는 한번 검사완료하면 검사시작리스트에서 한칸 전진후 다시 끝까지 검사함. 이때 검사시작리스트를 저장하는 변수
    SortedList *target = head; //최소값이 저장되어있는 리스트를 저장하는 변수
    for(SortedList *p = head; p!=NULL; p = p->link){
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


void display(SortedList *head){
    for(SortedList *p=head; p!=NULL; p=p->link){
        printf("%d ", p->data);
    }
}
int main()
{
    SortedList *head;

    head = add(head, 1);
    head = add(head, 3);
    head = add(head, 5);
    head = add(head, 4);
    head = add(head, 2);
    
    display(head);


    return 0;
}
