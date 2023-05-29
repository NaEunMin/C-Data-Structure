/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

q->rear가 q->front보다 큰 상황과 아닌 상황을 구별해주면 된다.

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100;
typedef struct{
    int queue[MAX_QUEUE_SIZE];
    int front,rear;
} QueueType;

void init_queue(QueueType *q){
    q->front = q->rear = 0;
}
int is_empty(QueueType *q){
    return (q->front == q->rear);
}
int is_full(QueueType *q){
    return ((q->rear)+1%MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType *q, int item){
    if(is_full(q)){
        fprintf(stderr,"큐 포화 에러\n");
        exit(1);
    }
    else{
        q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
        q->queue[(q->rear)] = item;
    }
}
int dequeue(QueueType *q){
    if(is_empty(q)){
        fprintf(stderr,"큐 공백 에러\n");
        exit(1);
    }
    else{
        q->front = (q->front+1) % MAX_QUEUE_SIZE;
        return q->queue[(q->front)];
    }
}

int get_count(QueueType *q){
    if(q->front <= q->rear){
        return q->rear-q->front;
    }
    else{
        return MAX_QUEUE_SIZE - (q->front - q->rear);
    }
}
int main()
{

    return 0;
}
