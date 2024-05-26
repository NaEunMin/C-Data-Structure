#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//함수 리턴이 ListNode* 라면 정상적으로 main함수에서 반영 될 수 있도록 main에 있는 head에 함수리턴값을 잘 저장해주도록 하자 ex) head = delete(head, target)
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;
ListNode* insert_last(ListNode* head, element item) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
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

ListNode* delete(ListNode* head, element target) {
	ListNode* p = head;
	ListNode* pre = NULL;
	for (p; p != NULL; p = p->link) {
		if (p->data == target) {
			if (p == head) {
				ListNode* remove = head;
				head = remove->link;
				free(remove);
				return head;
			}
			else {
				ListNode* remove = p;
				pre->link = remove->link;
				free(remove);
				return head;
			}
		}
		pre = p;
	}
}
void node_show(ListNode* head) {
	ListNode* p;
	for (p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("\n");
}
int node_size(ListNode* head) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	int size = 0;
	for (p = head; p != NULL; p = p->link) {
		size++;
	}
	return size;
}
int node_sum(ListNode* head) {
	ListNode* p;
	int sum = 0;
	for (p = head; p != NULL; p = p->link) {
		sum += p->data;
	}
	return sum;
}
int node_search(ListNode* head, element data) {
	ListNode* p = head;
	int index=1;
	for (p = head; p != NULL; p = p->link) {
		if (p->data == data) {
			return index;
		}
		else index++;
	}
}
int main() {
	ListNode* head = NULL;
	int size;
	int data;
	int search;
	printf("노드의 개수 : ");
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		printf("노드 %d의 데이터 : ", i + 1);
		scanf("%d", &data);
		head = insert_last(head, data);
	}
	node_show(head);
	printf("노드의 개수 : %d\n", node_size(head));
	printf("노드의 합 : %d\n", node_sum(head));
	printf("탐색할 값을 입력 : ");
	scanf("%d", &search);
	printf("%d는 연결 리스트 %d번에서 나타납니다.\n", search, node_search(head,search));

	printf("삭제할 데이터를 입력 : ");
	scanf("%d", &data);
	head = delete(head, data);
	node_show(head);

}
