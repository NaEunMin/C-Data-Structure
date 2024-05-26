#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//0이 아닌 항만 저장하여 다항식의 덧셈, 뺄셈을 하는 프로그램
typedef struct ListNode {
    int coef; // 다항식의 계수
    int exp; // 다항식의 지수
    struct ListNode* link;
} ListNode;

typedef struct ListType {
    int size;
    ListNode* head;
    ListNode* tail;
} ListType;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListType* create() {
    ListType* plist = (ListType*)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

void insert(ListType* plist, int coef, int exp) {
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    if (temp == NULL) error("메모리 할당 에러\n");
    temp->coef = coef;
    temp->exp = exp;
    temp->link = NULL;
    if (plist->tail == NULL) {
        plist->head = plist->tail = temp;
    }
    else {
        plist->tail->link = temp;
        plist->tail = temp;
    }
    plist->size++;
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
    ListNode* a = plist1->head;
    ListNode* b = plist2->head;
    int sum;
    while (a && b) {
        if (a->exp == b->exp) { // a와 b의 지수가 같을 때
            sum = a->coef + b->coef;
            if (sum != 0) insert(plist3, sum, a->exp);
            a = a->link;
            b = b->link;
        }
        else if (a->exp > b->exp) {
            insert(plist3, a->coef, a->exp);
            a = a->link;
        }
        else {
            insert(plist3, b->coef, b->exp);
            b = b->link;
        }
    }
    for (; a != NULL; a = a->link) {
        insert(plist3, a->coef, a->exp);
    }
    for (; b != NULL; b = b->link) {
        insert(plist3, b->coef, b->exp);
    }
}

void poly_sub(ListType* plist1, ListType* plist2, ListType* plist3) {
    ListNode* a = plist1->head;
    ListNode* b = plist2->head;
    int sub;
    while (a && b) {
        if (a->exp == b->exp) { // a와 b의 지수가 같을 때
            sub = a->coef - b->coef;
            if (sub != 0) insert(plist3, sub, a->exp);
            a = a->link;
            b = b->link;
        }
        else if (a->exp > b->exp) {
            a->coef = -(a->coef);
            insert(plist3, a->coef, a->exp);
            a = a->link;
        }
        else {
            b->coef = -(b->coef);
            insert(plist3, b->coef, b->exp);
            b = b->link;
        }
    }
    for (; a != NULL; a = a->link) {
        insert(plist3, a->coef, a->exp);
    }
    for (; b != NULL; b = b->link) {
        insert(plist3, b->coef, b->exp);
    }
}

void poly_print(ListType* plist) {
    ListNode* p = plist->head;
    printf("poly = ");
    while (p != NULL) {
        if (p->coef > 0 && p != plist->head) printf("+");
        if (p->exp == 0) printf("%d", p->coef);
        else if (p->exp == 1) printf("%dx", p->coef);
        else printf("%dx^%d", p->coef, p->exp);
        p = p->link;
    }
    printf("\n");
}

// 문자열 형태의 다항식을 파싱하여 연결 리스트에 삽입하는 함수
void parsePoly(char* poly, ListType* plist) {
    int i = 0, start = 0; // i는 현재 문자를 가리키는 인덱스, start는 항의 시작 인덱스
    int coef = 1, exp = 0; // coef는 계수, exp는 지수 (기본값은 1과 0으로 설정)
    char token[100]; // poly를 잘라서 만들어진 항을 저장하기 위한 배열
    int sign = 1; // 현재 항의 계수의 부호, 기본값은 양수(+)

    int len = strlen(poly); // poly의 길이를 계산
    for (i = 0; i <= len; i++) { // poly의 끝까지 반복(문자열 끝도 처리하기 위해 <= 사용)
        // 현재 문자가 '+' 이거나 '-' 이거나 문자열의 끝이면
        if (poly[i] == '+' || poly[i] == '-' || poly[i] == '\0') {
            if (i != start) { // 항이 존재하면 (항의배열의 길이가 0이 아니면)
                // 현재 토큰을 token 배열에 복사
                strncpy(token, &poly[start], i - start);
                token[i - start] = '\0'; // 복사된 항의 끝에 NULL 문자 추가

                char* xPos = strchr(token, 'x'); // 'x' 문자의 위치를 찾음
                if (xPos != NULL) { // 'x'가 존재하면 (지수가 0이 아닌 항)
                    if (xPos == token) { // 'x'가 토큰의 시작에 있으면 계수는 1
                        coef = sign * 1;
                    }
                    else { // 그렇지 않으면, 'x' 이전까지의 문자열을 계수로 변환
                        *xPos = '\0'; // 'x'를 일시적으로 NULL 문자로 변경하여 문자열 분리
                        coef = sign * atoi(token); // 분리된 문자열을 정수로 변환
                        *xPos = 'x'; // 'x'를 원래 문자로 복원
                    }

                    char* expPos = strchr(xPos, '^'); // '^' 문자의 위치를 찾음
                    if (expPos != NULL) exp = atoi(expPos + 1); // 지수가 있다면 변환
                    else exp = 1; // '^'가 없다면 지수는 1
                }
                else { // 'x'가 없으면 지수가 0
                    coef = sign * atoi(token); // 항를 정수로 변환하여 계수로 설정
                    exp = 0;
                }
                if (coef != 0) insert(plist, coef, exp); // 계수가 0이 아니면 리스트에 추가
            }

            start = i + 1; // 다음 항의 시작 위치를 현재 위치의 다음으로 업데이트
            sign = (poly[i] == '-') ? -1 : 1; // 현재 문자가 '-'이면 부호를 음수로 설정, 아니면 양수
        }
    }
}



int main() {
    ListType* plist1, * plist2, * plist3, * plist4;

    while (1) {
        char poly[100]; // 다항식을 입력할 배열
        char poly2[100];
        plist1 = create();
        plist2 = create();
        plist3 = create(); //덧셈 전용
        plist4 = create(); //빼기 전용
        int choice;
        printf("다항식 계산 프로그램을 시작합니다.\n");
        printf("1:다항식의 합, 2:다항식의 차, 3:프로그램 종료");
        scanf("%d", &choice);
        if (choice == 1) {
            // 두 다항식의 합을 계산하여 출력
            printf("다항식을 입력 : ");
            scanf("%s", poly);
            parsePoly(poly, plist1);

            printf("두 번째 다항식을 입력 : ");
            scanf("%s", poly2);
            parsePoly(poly2, plist2);
            poly_print(plist1);
            poly_print(plist2);
            poly_add(plist1, plist2, plist3);
            printf("다항식의 합 : ");
            poly_print(plist3);
            free(plist1);
            free(plist2);
            free(plist3);
            free(plist4);
        }
        else if (choice == 2) {
            printf("다항식을 입력 : ");
            scanf("%s", poly);
            parsePoly(poly, plist1);

            printf("두 번째 다항식을 입력 : ");
            scanf("%s", poly2);
            parsePoly(poly2, plist2);
            poly_print(plist1);
            poly_print(plist2);
            poly_sub(plist1, plist2, plist4);
            printf("다항식의 차 : ");
            poly_print(plist4);
            free(plist1);
            free(plist2);
            free(plist3);
            free(plist4);
        }
        else if (choice == 3) {
            printf("다항식 계산 프로그램을 종료합니다\n");
            break;
        }
    }
    return 0;
}
