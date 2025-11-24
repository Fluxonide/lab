// Write  a  program  to  declare  an  array  of  size  100  and  perform  the  following 
// operations: 
// a) Initialize the array with random numbers. 
// b) Calculate sum and average of elements in the array. 
// c) Display all the even numbers in the array. 
// d) Display all the odd numbers in the array. 
// e) Display all the prime numbers in the array. 
// f) Reverse the array. 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 100

#define size 100
//
// Algo: add(arr)
// Step 0: 	Start
// Step 1: 	set sum = 0
// Step 2: 	repeat for i = 0 to size-1, sum = sum + arr[i]
// Step 3: 	return sum
// Step 4: 	Stop
//
// Algo: average(sum)
// Step 0: 	Start
// Step 1: 	average = sum / size
// Step 2: 	print average
// Step 3: 	Stop
//
// Algo: displayEven(arr)
// Step 0: 	Start
// Step 1: 	repeat for i = 0 to size-1
// Step 2: 	if arr[i] % 2 == 0, print arr[i]
// Step 3: 	Stop
//
// Algo: displayOdd(arr)
// Step 0: 	Start
// Step 1: 	repeat for i = 0 to size-1
// Step 2: 	if arr[i] % 2 != 0, print arr[i]
// Step 3: 	Stop
//
// Algo: displayPrime(arr)
// Step 0: 	Start
// Step 1: 	repeat for i = 0 to size-1
// Step 2: 	set isPrime = 1
// Step 3: 	if arr[i] <= 1, isPrime = 0
// Step 4: 	else, repeat for j = 2 to arr[i]-1
// Step 4.1:		if arr[i] % j == 0, isPrime = 0, break
// Step 5: 	if isPrime == 1, print arr[i]
// Step 6: 	Stop
//
// Algo: reverseArr(arr)
// Step 0: 	Start
// Step 1: 	set start = 0, end = size - 1
// Step 2: 	while start < end
// Step 2.1:		swap(arr[start], arr[end])
// Step 2.2:		start++, end--
// Step 3: 	Stop

int add(int arr[]){
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

void traverse(int arr[]){
    for (int i = 0; i < size; i++)
    {
        printf("%d: %d\n", i, arr[i]);
    }
}

void average(int sum){
    int average = sum/size;
    printf("The average is: %d\n", average);
}

void displayEven(int arr[]){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]%2 != 0)
        {
            continue;
        }
        printf("%d: %d\n", i, arr[i]);
    } 
}
void displayOdd(int arr[]){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]%2 == 0)
        {
            continue;
        }
        printf("%d: %d\n", i, arr[i]);
    } 
}

void displayPrime(int arr[]){
    int isPrime = 1;
    for (int i = 0; i < size; i++)
    {
        isPrime = 1;
        if (arr[i]<=1)
        {
            isPrime = 0;
        }else{
            for (int j = 2; j < arr[i]; j++)
            {
                if (arr[i]%j == 0)
                {
                    isPrime = 0;
                    break;
                }   
            }  
        }
        if (isPrime == 0)
        {
            continue;
        }
        printf("%d: %d\n", i, arr[i]);
    } 
}

void reverseArr(int arr[]){
    int start = 0, end = size -1;
    while (start<end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int arr[size];
    srand(time(NULL));//uses the current time as seed for rand()

    //Initializing the array with random values
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand()%1000;
    }

    //Traverse
    traverse(arr);

    //SUM
    int sum1 = add(arr);
    printf("Sum of the array: %d\n", sum1);

    //AVERAGE
    average(sum1);

    //Display Even
    displayEven(arr);

    //Display odd
    displayOdd(arr);

    //Display prime
    printf("PRIME\n");
    displayPrime(arr);

    //Reversing the Array
    reverseArr(arr);



    
    
    return 0;
}