/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

18번 문제의 알고리즘부터 간단하고 쉬운 알고리즘이 있다.
물론 18번과 이 문제의 상황이 달라서 알고리즘이 달라질 수 있지만 오름차순정렬이라는 부분에 초점을 두어 보면 add()함수 작성에 사용한 알고리즘이 훨씬 간단하고 쉽다.

*/

#include <stdio.h>

#define MAX_LIST_SIZE 100
typedef struct {
    int data[MAX_LIST_SIZE];
    int size;
}SortedList;

void init(SortedList *list){
    list->size = 0;
}

int is_empty(SortedList *list){
    return (list->size == 0);
}
int is_full(SortedList *list){
    return (list->size == MAX_LIST_SIZE);
}
void add(SortedList *list, int item){
    if(!is_full(list)) { //리스트가 포화상태가 아니라면
        int i = 0;
        for(i = 0; i<list->size;i++) { //처음부터 최근 입력한 인덱스까지만 검사
            if(list->data[i] > item) { //입력한 값이 list에 있는 값보다 작다면
                for(int j=list->size; j > i; j--) //이미 리스트는 오름차순정렬이 되어있으므로
                    list->data[j] = list->data[j-1]; //새로운 값이 들어오면 기존값들은 1칸씩 뒤로 밀어준다.
                break;
            }
        }
        list->data[i] = item;
        list->size++;
    }
}

void delete(SortedList *list, int item){
    for(int i=0; i<list->size; i++){
        if(item == list->data[i]){
            list->data[i] = list->data[i+1];
        }
    }
}

void clear(SortedList *list) {
    while(!is_empty(list)) {
        // int i = list->size;
        delete(list,list->data[list->size]);
        list->size--;
    }
}

int is_in_list(SortedList *list, int item){
    for(int i=0; i<list->size; i++){
        if(list->data[i]==item){
            return 1;
        }
    }
}

int get_length(SortedList *list){
    return list->size;
}

void display(SortedList *list){
    for(int i=0; i<list->size; i++){
        printf("%d ", list->data[i]);
    }
}
int main()
{
    SortedList list;
    init(&list);
    add(&list, 2);
    add(&list, 3);
    add(&list, 4);
    add(&list, 5);
    add(&list, 1);
    
    display(&list);


    return 0;
}
