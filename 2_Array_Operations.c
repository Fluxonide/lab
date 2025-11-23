// Write a program to declare an array of any size, initialize some of the elements
// and perform the following operations: 
// a) Insert a new element into the array. 
// b) Delete an element from the array. 
// c) Traverse the array. 
// d) Merge two arrays. 
// e) Search an element (linear search) in the array. 
// f)  Sort the elements (bubble sort) of the array.

#include <stdio.h>
#include <stdlib.h>
#define size 10

void insert(int arr[], int* U, int data, int index){
    if (*U>=size)
    {
        printf("Element cannot be inserted as the array is full\n");
    }else
    {
        int i = *U - 1;
        while (i>=index)
        {
            arr[i+1] = arr[i];
            i--;
        }
        arr[index] = data;
        (*U)++;
    } 
} 

void delete(int arr[], int* U, int ele){
    if (*U<=0)
    {
        printf("Element cannot be deleted as Array is Empty\n");
    }else
    {
        int i = 0;
        while (arr[i] != ele)
        {
            i++;
            if (*U == i)
            {
                printf("Element not Found\n");
                return;
            }
        }

        while (i<*U-1)
        {
            arr[i] = arr[i+1];
            i++;
        }
        (*U)--;
 
    }    
}

void traverse(int arr[], int U){
    for (int i = 0; i < U; i++)
    {
        printf("%d: %d\n", i, arr[i]);
    }
}

void merge(int arr1[], int arr2[], int* U1, int* U2){
    int total_size = *U1 + *U2;
    int i = *U1;
    int j = 0;
    while (i<total_size)
    {
        arr1[i] = arr2[j];
        i++, j++;
    }
    *U1 = total_size; 
}

void search(int arr[], int U, int data){
    int i = 0;
    while (i<U)
    {
        if (arr[i] == data)
        {
           printf("Element %d found at index %d\n", data, i);
        }
        i++; 
    }   
}

void bubbleSort(int arr[], int U){
    for (int i = 0; i < U-1; i++)
    {
        for (int j = 0; j < U-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[size] = {1, 2, 3, 4, 5};
    int U = 5;

    insert(arr, &U, 5, 2);
    traverse(arr, U);

    delete(arr, &U, 2);
    traverse(arr, U);

    int arr1[size] = {1, 2, 3, 4, 5};
    int arr2[size] = {6, 7, 8, 9, 10};
    int U1 = 5, U2 = 5;

    merge(arr1, arr2, &U1, &U2);
    traverse(arr1, U1);

    search(arr, U, 5);

    bubbleSort(arr, U);
    traverse(arr, U);
    return 0;
}