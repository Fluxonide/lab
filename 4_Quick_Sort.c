#include <stdio.h>
#include <stdlib.h>
// DIVIDE AND CONQUER APPROACH
// To solve(sort) a problem more efficiently we have an approach called the divide and conquer approach in which we divide the problems into smaller sub problems and collect the solution that will lead to the ultimate solution.

// QUICK SORT - a sorting technique based on the divide and conquer apprach
// It picks an element as pivot and partitions the given array around the picked pivot by placing the pivot in the correct position in the sorted array.

// The key process is partition

// The aim of the partition is to place the pivot(any ele)at its correct position in the sorted array and pull all smaller elements to the left of the pivot, all the greater elements to right.
// Parition is recursively done on each side of the pivot after the pivot is placed in the correct position and finally sorts the array.

// LOGIC
// We start from the leftmost element and keep track of the smaller(or equal) element as i.
//
// Algo: partition(arr, low, high)
// Step 0: 	Start
// Step 1: 	set pivot = arr[low]
// Step 2: 	set i = low + 1, j = high
// Step 3: 	repeat while i < j
// Step 3.1:		while arr[i] <= pivot, i++
// Step 3.2:		while arr[j] > pivot, j--
// Step 3.3:		if i < j, swap(arr[i], arr[j])
// Step 4: 	swap(arr[low], arr[j])
// Step 5: 	return j
// Step 6: 	Stop
//
// Algo: quickSort(arr, low, high)
// Step 0: 	Start
// Step 1: 	if low < high, then
// Step 1.1:		partitionIndex = partition(arr, low, high)
// Step 1.2:		quickSort(arr, low, partitionIndex - 1)
// Step 1.3:		quickSort(arr, partitionIndex + 1, high)
// Step 2: 	end if
// Step 3: 	Stop

int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // tehe first element of the array
    int i = low + 1;
    int j = high;
    int temp;
    do{
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } 
    }while(i<j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;

}

void quickSort(int arr[], int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);  // sort left subarray recursively
        quickSort(arr, partitionIndex + 1, high); // sort right subarray recursively
    }
}

void traverse(int arr[], int size){
    int i = 0;
    while (i<size)
    {
        printf("%d\t", arr[i]);
        i++;
    }
    printf("\n");
}

int main()
{
    int arr[] = {3, 5, 2, 13, 12};
    int size = 5;
    traverse(arr, size);
    quickSort(arr, 0, size - 1);
    traverse(arr, size);
    return 0;
}