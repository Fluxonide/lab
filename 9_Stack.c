// Write a program to create a stack and perform the following operations: 
// a) Push into the stack. 
// b) Pop from the stack. 
// c) Peep from the stack. 
// d) Display the elements of the stack.

#include <stdio.h>
#include <stdlib.h>
#define size 10

int push(int s[], int top, int data){
    if (top>=size-1)
    {
        printf("Stack Overflow\n");
    }else
    {
        top++;
        s[top] = data;
    }
    return top; 
}

int pop(int s[], int top){
    if (top < 0)
    {
        printf("Stack Underflow");
    }else
    {
        int item = s[top];
        top--;
        printf("Element %d popped successfully\n", item);
    }
    return top;
}

void peep(int s[], int top){
    if (top<0)
    {
        printf("Stack is empty\n");
    }else
    {
        printf("Peep: %d \n", s[top]);
    }  
}

void traverse(int s[], int top){
    int i = top;
    while (i!=-1)
    {
        printf("%d\n__\n\n", s[i]);
        i--;
    }
    
}

int main() {
    int Stack[size];
    int top = -1;   
    top = push(Stack, top, 10); 
    top = push(Stack, top, 20); 
    top = push(Stack, top, 30); 
    top = push(Stack, top, 40); 

    traverse(Stack, top);
    top = pop(Stack, top);
    traverse(Stack, top);

    peep(Stack, top);
    
    return 0;
}