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

#define size 10
//
// Algo: insert(arr, U, data, index)
// Step 0: 	Start
// Step 1: 	if *U >= size, print "Full"
// Step 2: 	else
// Step 2.1:		set i = *U - 1
// Step 2.2:		while i >= index, arr[i+1] = arr[i], i--
// Step 2.3:		arr[index] = data, (*U)++
// Step 3: 	Stop
//
// Algo: delete(arr, U, ele)
// Step 0: 	Start
// Step 1: 	if *U <= 0, print "Empty"
// Step 2: 	else
// Step 2.1:		find index i of ele
// Step 2.2:		if not found, return
// Step 2.3:		while i < *U - 1, arr[i] = arr[i+1], i++
// Step 2.4:		(*U)--
// Step 3: 	Stop
//
// Algo: merge(arr1, arr2, U1, U2)
// Step 0: 	Start
// Step 1: 	set total_size = *U1 + *U2, i = *U1, j = 0
// Step 2: 	while i < total_size, arr1[i] = arr2[j], i++, j++
// Step 3: 	*U1 = total_size
// Step 4: 	Stop
//
// Algo: search(arr, U, data)
// Step 0: 	Start
// Step 1: 	set i = 0
// Step 2: 	while i < U
// Step 2.1:		if arr[i] == data, print "Found at index i"
// Step 2.2:		i++
// Step 3: 	Stop
//
// Algo: bubbleSort(arr, U)
// Step 0: 	Start
// Step 1: 	repeat for i = 0 to U-2
// Step 2: 	repeat for j = 0 to U-i-2
// Step 3: 	if arr[j] > arr[j+1], swap(arr[j], arr[j+1])
// Step 4: 	Stop

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