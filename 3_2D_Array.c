// Write a program to declare two 2D arrays (matrices) of size M×N where M is the 
// no. of rows and N is the no. of columns, initialize them and perform the following 
// operations: 
// a) Traverse the arrays. 
// b) Add two matrices. 
// c) Multiply two matrices. 
// d) Find transpose of the matrices.

#include <stdio.h>
#include <stdlib.h>
#define M 3
#define N 3

int main() {
    int arr1[M][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr2[M][N] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    printf("ARRAY 1: \n\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", arr1[i][j]);
        }
        printf("\n\n");
    }
    printf("ARRAY 2: \n\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", arr2[i][j]);
        }
        printf("\n\n");
    }

    printf("ADDED ARRAY: \n\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr1[i][j] += arr2[i][j];
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", arr1[i][j]);
        }
        printf("\n\n");
    }

    printf("TRANSPOSE OF ARRAY 2: \n\n");
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d\t", arr2[i][j]);
        }
        printf("\n\n");
    }

    int sum = 0;
    int result[3][3];
    
    //Loop 1: Selects the row from Array 1(i)
    for (int i = 0; i < 3; i++)
    {
        //Loop 2: Selects the column from Array2(j)
        for (int j = 0; j < 3; j++)
        {
            sum = 0;//reset sum for all cells
            //k -> moves right across arr 1(m) and down across arr 2(n)
            for (int k = 0; k < 3; k++)
            {
                sum += arr1[i][k] * arr2[k][j];
            }
            result[i][j] = sum;
        }
    }

    printf("MULTIPLICATION OF ARR1 AND ARR2:\n\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", result[i][j]);
        }
        printf("\n\n");
    }
    

    

    return 0;
}