#include<stdio.h>
#include<stdlib.h>

//SORTING - refers to the rearrangement of data in proper order
//array can be sorted based on the magnitude of the elements in it.
//a sorted array is easy to operatae on.

//TYPES OF SORTING
//1. Bubble Sort
//easiest sorting technique
//based on the theory of bigger bubbles settling on the surface faster than the smaller ones
//[gemini give visual representation]
//Element at each index is compared with next elements and bigger element is pushed towards the end part of the unsorted array
//[gemini give visual representation and example of arrray sorted using bubble sort]

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        //i -> for iteration upto n which leads to complete sorting[gemini give some light on this]
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