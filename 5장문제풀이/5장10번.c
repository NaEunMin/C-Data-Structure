/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


/*

*** 피보나치 수열 ***
첫째 및 둘째 항이 1이며 그 뒤의 모든 항은 바로 앞 두 항의 합인 수열이다.  편의상 0번째 항을 0으로 두기도 한다
-피보나치수열의 정의
F(n) = F(n-1) + F(n-2)

*** 알고리즘 ***
1. 처음에 큐에는 F(0)=0, F(1)=1이 들어있다.  //0번째 항은 정의를 쉽게 이해하기 위해 편의상 존재하는 것이라고 하였다.
2. temp에 dequeue하여 0을 삭제후 리턴해준다.
3. enqueue하여 temp+큐의 rear 값을 삽입한다. //여기서 rear는 1이다.
이 과정이 찾고자 하는 피보나치 수열에 도달할때까지 반복하면 된다.

*** 예시 ***
F(3)을 찾아보자.
반복문 i=0 ==> temp=0, q->data[rear]=1이고 enqueue로 큐에 두 값을 더해서 삽입해준다.
반복문 i=1 ==> temp=1, q->data[rear]=1이고 enqueue로 큐에 두 값을 더해서 삽입해준다.  
//temp는 앞에서 0번째항을 dequeue로 삭제했으므로 그 다음요소값인 1이 되고 q->data[rear]는 앞에서 0+1를 하여 값을 삽입했으므로 아직도 1인 것이다.

*** 내가 실수한 부분 ***
        enqueue(q, dequeue(q)+q->data[q->rear]); //temp를 처음에 안쓰고 문제를 접근했었다. 여기까진 괜찮은데
        printf("%d ",dequeue(q)+q->data[q->rear]); //값을 확인해보겠다고 dequeue를 이 코드에서 더 사용해서 큐의 요소를 2번 삭제한 꼴이 되었다.

*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100
typedef struct{
    int data[MAX_QUEUE_SIZE];
    int front,rear;
} QueueType;

void init_queue(QueueType *q){
    q->front = q->rear = 0;
}
int is_empty(QueueType *q){
    return (q->front == q->rear);
}
int is_full(QueueType *q){
    return (q->front == (q->rear+1)%MAX_QUEUE_SIZE);
}
void enqueue(QueueType *q, int item){
    if(is_full(q)){
        fprintf(stderr,"큐 포화 에러\n");
        exit(1);
    }
    else{
        q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
        q->data[(q->rear)] = item;
    }
}
int dequeue(QueueType *q){
    if(is_empty(q)){
        fprintf(stderr,"큐 공백 에러\n");
        exit(1);
    }
    else{
        q->front = (q->front+1) % MAX_QUEUE_SIZE;
        return q->data[(q->front)];
    }
}
void Fibo(QueueType *q, int n){
    enqueue(q, 0);
    enqueue(q, 1);
    for(int i=0; i<n-1; i++){
        int temp = dequeue(q);
        enqueue(q, temp+q->data[q->rear]);
    }
    printf("F(%d) = %d", n, q->data[q->rear]);
}
int main()
{
    QueueType q;
    int n;
    printf("찾고 싶은 피보나치 수열은?");
    scanf("%d", &n);
    Fibo(&q, n);

    return 0;
}
