// Write a program to create a circular queue and perform the following operations: 
// a) Enqueue into the circular queue. 
// b) Dequeue from the circular queue. 
// c) Traverse the circular queue

#include <stdio.h>
#include <stdlib.h>
#define size 5
//
// Algo: enqueue(Q, front, rear, data)
// Step 0: 	Start
// Step 1: 	if (*front == 0 AND *rear >= size-1) OR (*front == *rear+1), print "Overflow"
// Step 2: 	else if *front == -1 AND *rear == -1, *front = *rear = 0
// Step 3: 	else if *rear == size-1, *rear = 0
// Step 4: 	else, (*rear)++
// Step 5: 	Q[*rear] = data
// Step 6: 	Stop
//
// Algo: dequeue(Q, front, rear)
// Step 0: 	Start
// Step 1: 	if *front == -1 AND *rear == -1, print "Underflow"
// Step 2: 	else if *front == *rear, *front = *rear = -1
// Step 3: 	else if *front == size-1, *front = 0
// Step 4: 	else, (*front)++
// Step 5: 	Stop

void enqueue(int Q[], int* front, int* rear, int data){
    if ((*front == 0 && *rear>=size-1)||(*front == *rear+1))
    {
        printf("Queue Overflow!\n");
    }else if(*front == -1 && *rear == -1 )
    {
        *front = *rear = 0;
    }else if(*rear == size-1){
        *rear = 0;
    }
    else{
        (*rear)++;
    }   
    Q[*rear] = data;
}

void dequeue(int Q[], int* front, int* rear){
    if (*front == -1 && *rear == -1)
    {
        printf("Queue Underflow!");
    }else if(*front == *rear){
        *front = -1;
        *rear = -1;
    }else if (*front == size-1)
    {
        *front = 0;
    }else{
        (*front)++;
    }
}

void traverse(int Q[], int *front, int* rear) {
    if (*front == -1) {
        printf("Queue is empty\n");
        return;
    }

    int i = *front;

    printf("Circular Queue elements:\n");

    while (1) {
        printf("%d ", Q[i]);

        if (i == *rear)
            break;

        i = (i + 1) % size;   // wrap-around
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
    dequeue(Q, &front, &rear);
    dequeue(Q, &front, &rear);
    enqueue(Q, &front, &rear, 60);
    enqueue(Q, &front, &rear, 70);
    enqueue(Q, &front, &rear, 70);

    traverse(Q, &front, &rear);

    return 0;
}