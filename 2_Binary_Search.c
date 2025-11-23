#include <stdio.h>
#include <stdlib.h>

// Binary Search
// Firstly the smallest value in the arrayis taken as low
// Secondly the largest value in the array is taken as high

// mid is the highest integer of (low+high)/2

// if value is greater than mid, then the array lies b/w mid and high so mid is set as low
// if the value is less than mid, then the array lies b/w low and mid so the mid is set as high
// This process is done iteratively until the element is found

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size-1;
    while (low <= high)// if low and high converges or equals there is no element
    {
        mid = (low + high) / 2; // compiler auto sets to higher integer
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (element > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 22, 33, 44, 55, 67, 89, 90};
    int size = 8;
    int element = 67;

    int pos = binarySearch(arr, size, element);\


    if(binarySearch(arr, size, element)){
        printf("Element %d found at:%d\n", element, pos+1);
    }else
    {
        printf("Element not found");
    }
    
    return 0;
}