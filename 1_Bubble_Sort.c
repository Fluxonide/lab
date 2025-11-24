#include<stdio.h>
#include<stdlib.h>

//SORTING - refers to the rearrangement of data in proper order
//array can be sorted based on the magnitude of the elements in it.
//a sorted array is easy to operatae on.

//TYPES OF SORTING
//1. Bubble Sort
//easiest sorting technique
//based on the theory of bigger bubbles settling on the surface faster than the smaller ones
//Element at each index is compared with next elements and bigger element is pushed towards the end part of the unsorted array
//
// Algo: bubbleSort(arr, n)
// Step 0: 	Start
// Step 1: 	repeat Step 2 and 3 for i = 0 to n-1
// Step 2: 	repeat Step 3 for j = 0 to n-i-1
// Step 3: 	if arr[j] > arr[j+1], then
// Step 3.1:		swap(arr[j], arr[j+1])
// Step 4: 	end if
// Step 5: 	Stop

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        //i -> for iteration upto n which leads to complete sorting
        //j -> to traverse among the elements of the array
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];//storing the value of the current element
                arr[j] = arr[j+1];//setting next element value to current value
                arr[j+1] = temp;//setting next element value to temp[prev/current element value]
            }
        }  
    }   
}

void traverse(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d: %d\n", i, arr[i]);
    }
    
}


int main(){
    int arr[] = {100, 50, 27, 90, 69};
    int n = 5;
    traverse(arr, n);
    printf("\nAfter Sorting\n");
    bubbleSort(arr, n);
    traverse(arr, n);
    return 0;
}