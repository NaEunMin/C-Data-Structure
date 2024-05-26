/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

insert_last()함수, print_node()함수를 사용하면 해결가능한 문제

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char Name[5];
    int Age;
    double Heigh;
}Infomation;

typedef struct ListNode{
    Infomation info;
    struct ListNode *link;
}ListNode;

ListNode* insert_last(ListNode *head, Infomation info){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->info = info;
    p->link = NULL;
    if(head==NULL){
        p->link = head;
        head = p;
    }
    else{
        ListNode *lastNode = head; //마지막노드를 구하려면 앞에서부터 탐색을 해야하므로 lastNode = head
        while(lastNode->link!= NULL) //앞에서부터 탐색하는데 마지막노드가 아니라면
            lastNode = lastNode->link; //앞에서부터 탐색하는 코드 
        lastNode->link = p; //lastNode는 head처럼 알려주는 표식과 같은 것. 추가한 노드p가 마지막 노드임을 알려줌.
    }
    return head;
    }

void print_node(ListNode *head){
    for(ListNode *p = head; p!=NULL; p = p->link){
        printf("Name: %s\n", p->info.Name);
        printf("Age: %d\n", p->info.Age);
        printf("Heigh: %lf\n", p->info.Heigh);
    }
    printf("\n");
}
int main()
{
    ListNode *head = NULL;
    Infomation info1 = {"kim",34,1.7};
    Infomation info2 = {"park",27,1.2};
    Infomation info3 = {"lee",48,1.4};
    Infomation info4 = {"choi",30,1.3};
    
    head = insert_last(head, info1);
    head = insert_last(head, info2);
    head = insert_last(head, info3);
    head = insert_last(head, info4);

    print_node(head);
    return 0;
}

///여기부터는 다른 방법 -- 비슷하긴하지만 좀더 깔끔하다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char name[100];
	int age;
	double height;
}Student;
typedef struct ListNode {
	Student student;
	struct ListNode* link;
}ListNode;
ListNode* insert_last(ListNode* head, Student data) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->student = data;
	p->link = NULL;
	if (head == NULL) {
		head = p;
		return head;
	}
	else {
		ListNode* last = head;
		while (last->link != NULL) {
			last = last->link;
		}
		last->link = p;
		return head;
	}
}
void node_show(ListNode*head) {
	ListNode* p = head;
	for (p; p != NULL; p = p->link) {
		printf("이름 : %s 나이 : %d 키 : %.1lf\n", p->student.name, p->student.age, p->student.height);
	}
}
int main() {
	ListNode* head = NULL;
	char name[100];
	int age;
	double height;
	Student student;
	for (int i = 0; i < 3; i++) {
		printf("학생의 정보를 입력해주세요 (이름, 나이, 키) : ");
		scanf("%s%d%lf", name, &age, &height);
		strcpy(student.name, name);
		student.age = age;
		student.height = height;
		head = insert_last(head, student);
	}
	node_show(head);
}
