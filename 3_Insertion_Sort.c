#include<stdio.h>
#include<stdlib.h>

//Insertion sort is a simple sorting algorithm that works similiar to the way you sort playing cards in your hands
//The array is virtually split into a sorted and unsorted part
//Values from the unsorted parts are picked and placed at the correct position in the sorted part.
//To sort an array of size n in ascending order, iterate over the array and compare the current element(key) to its predecesor
//if the key is smaller than it's predecessor, compare it with the elements before
//Move the greater elements one position up to make space for swapped element

void insertionSort(int arr[], int n){
    int key;
    int j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;  
    }
}
void traverse(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d: %d\n", i, arr[i]);
    }
    
}

int main(){
    int arr[] = {1, 312 , 5, 11, 4324, 4536 ,33};
    int n = 7;
    insertionSort(arr, n);
    traverse(arr, n);
    return 0;
}