#include <stdio.h>
#include <stdlib.h>
//
// Algo: merge(arr, low, mid, high)
// Step 0: 	Start
// Step 1: 	set i = low, j = mid + 1, k = low
// Step 2: 	while i <= mid AND j <= high
// Step 2.1:		if arr[i] < arr[j], B[k++] = arr[i++]
// Step 2.2:		else, B[k++] = arr[j++]
// Step 3: 	while i <= mid, B[k++] = arr[i++]
// Step 4: 	while j <= high, B[k++] = arr[j++]
// Step 5: 	copy B to arr from low to high
// Step 6: 	Stop
//
// Algo: mergeSort(arr, low, high)
// Step 0: 	Start
// Step 1: 	if low < high, then
// Step 1.1:		mid = (low + high) / 2
// Step 1.2:		mergeSort(arr, low, mid)
// Step 1.3:		mergeSort(arr, mid + 1, high)
// Step 1.4:		merge(arr, low, mid, high)
// Step 2: 	end if
// Step 3: 	Stop

void merge(int arr[], int low, int mid, int high){
    int i, j, k;
    int B[20];
    i = low;
    j = mid + 1;
    k = low;
    while (i<=mid && j<=high)
    {
        if (arr[i]<arr[j])
        {
            B[k] = arr[i];
            i++, k++;
        }else
        {
            B[k] = arr[j];
            j++, k++;
        }   
    }
    while (i<=mid)
    {
        B[k] = arr[i];
        k++, i++;
    }
    while (j<=high)
    {
        B[k] = arr[j];
        k++, j++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = B[i];
    }
    
}

void mergeSort(int arr[], int low, int high){
    int mid;
    if (low<high)
    {
        mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr,mid+1, high);
        merge(arr, low, mid, high);

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

int main() {
    int arr[] = {234, 1, 2, 675, 32, 123, 5 , 87, 32, 56};
    int size = 10;
    traverse(arr, size);
    mergeSort(arr, 0, 9);
    traverse(arr, size);

    return 0;
}