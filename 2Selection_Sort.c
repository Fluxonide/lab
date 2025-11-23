#include<stdio.h>
#include<stdlib.h>
//SELECTION SORT

//Selection Sort is a simple yet efficient sorting algorithm
//It works by repeatedly selecting the smallest element(in case of ascending sort) from the unsorted portion of the array and moving to the sorted portion of the array
//The algorithm repeatedly selects the smallest element from the unsorted portion of the array and swaps it with the first element of the unsorted part
//This process is repeated for the remaining unsorted part until the entire array is sorted.
//Unlike Bubble Sort which pushes the biggest among the unsorted to the sorted part, selection sort pulls the smallest among the sorted part

void selectionSort(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i]>arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp; 
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
    int arr[] = {78, 32, 65, 123, 657, 11, 5, 675, 234, 1};
    int n = 10;

    traverse(arr, n);
    printf("\nAfter Sorting\n");
    selectionSort(arr, n);
    traverse(arr, n);
    return 0;
}
