#include <stdio.h>
#include <stdlib.h>
#define size 5

void enqueue(int Q[], int *front, int*rear, int data){
    int flag;
    if ((*front == 0 && *rear == size-1) ||(*front == *rear + 1))
    {
        printf("Queue Overflow!\n");
    }else
    {
         if(*front == -1)
        {
            *front = 0;
            *rear = 0;
            flag = *rear;
        }else if(*rear == size-1){
            (*front)--;
            flag = *front;
    }else{
        (*rear)++;
        flag = *rear;
    }
    Q[flag] = data;
    }
}

void dequeue(int Q[], int *front, int* rear){
    int choice = *rear;
    if (*front == -1 && *rear == -1)
    {
        printf("Queue Underflow\n");
    }else if (*front == *rear)
    {
        *front = *rear = -1;
    }else if (*front<*rear && choice == *rear)
    {
        (*rear)--;
    }else{
        (*front)++;
    }
    
    
    
}
void traverse(int Q[], int front, int rear){
    int i = 0;
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", Q[i]);
    }
    printf("\n");
    
}


int main() {
    int Q[size];
    int front = -1, rear = -1;
    enqueue(Q, &front, &rear, 10);
    enqueue(Q, &front, &rear, 20);
    enqueue(Q, &front, &rear, 30);
    enqueue(Q, &front, &rear, 40);
    enqueue(Q, &front, &rear, 50);
    enqueue(Q, &front, &rear, 60);

    traverse(Q, front, rear);
    dequeue(Q, &front, &rear);
    dequeue(Q, &front, &rear);
    dequeue(Q, &front, &rear);
    dequeue(Q, &front, &rear);

    enqueue(Q, &front, &rear, 20);
    enqueue(Q, &front, &rear, 30);
    enqueue(Q, &front, &rear, 40);
    enqueue(Q, &front, &rear, 50);
    traverse(Q, front, rear);
    
    


    return 0;
}