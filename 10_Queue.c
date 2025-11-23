#include <stdio.h>
#include <stdlib.h>
#define size 5

void enqueue(int Q[], int* front, int* rear, int data){
    if (*front = 0 && *rear>=size-1)
    {
        printf("Queue Overflow! Cannot Enqueue\n");
    }else if(*front == -1 && *rear == -1 )
    {
        *front = *rear = 0;
    }else
    {
        (*rear)++;
    }
    
    Q[*rear] = data;
    
}

void dequeue(int Q[], int* front, int* rear){
    if (*front == -1 ||*front > *rear)
    {
        printf("Queue Underflow\n");
    }else{
        (*front)++;
    }
}



int main() {
    int Q[size];
    int front = -1, rear = -1;
    enqueue(Q, &front, &rear, 10);
    enqueue(Q, &front, &rear, 20);
    enqueue(Q, &front, &rear, 30);
    enqueue(Q, &front, &rear, 40);
    traverse(Q, front, rear);

    dequeue(Q, &front, &rear);
    traverse(Q, front, rear);


    return 0;
}void traverse(int Q[], int front, int rear){
    int i = 0;
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", Q[i]);
    }
    printf("\n");
    
}