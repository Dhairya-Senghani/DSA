// *********** Count Sort ********************
// NOT MODIFIED PLEASE READ FROM GFG WEBSITE
// Stable : NO
// Adaptive : NO  (not sure, verify)
// Inplace : YES
// TIME COMPLEXITY
// Worst case : O(m+n) , where m is the maximum element of array 
//              O(n) , if n >> m (n is very large)
// Best case : O(nlog(n))
// Average : O(nlog(n))
// Space Complexity : O(1) (not sure, verify)
// One of the fastest algorithm

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int *, int);
void countSort(int *, int);
int maximum(int *, int);
int main()
{
    int a[] = {3, 2, 0, 91, 56, 83, 6, 56, 99, 32, 30, 49, 9, 5, 45};
    // int a[] = {1, 5, 2};
    // int a[] = {2, 4, 1, 5, 23, 21};
    // int a[]= {47, 85, 23, 95, 12, 67, 34, 92, 19, 81, 73, 46, 39, 57, 88, 16, 94, 63, 21, 75, 10, 56, 87, 30, 82, 24, 68, 93, 18, 79, 40, 53, 91, 29, 65, 15, 58, 84, 36, 71, 11, 66, 33, 48, 22, 78, 41, 55, 90, 26, 62, 17, 70, 20, 77, 43, 52, 89, 32, 74, 13, 59, 80, 27, 61, 31, 50, 86, 28, 64, 14, 60, 25, 76, 44, 51, 83, 35, 72, 38, 69, 37, 49, 96, 54, 45, 97, 98, 99, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 42};
    // int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};

    int length = sizeof(a) / sizeof(a[0]);

    printArray(a, length);
    countSort(a, length);
    printArray(a, length);

    return 0;
}

void printArray(int *a, int n)
{
    printf("Printing Array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%0.2d ", a[i]);
    }
    printf("\n");
}

void countSort(int *a, int n)
{
    int max = maximum(a, n);
    int *count = (int *)malloc((max + 1) * sizeof(int));
    int i, j;

    for (i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        count[a[i]] = count[a[i]] + 1;
    }

    i = 0; // counter for count array
    j = 0; // counter for given array

    while (i <= max)
    {
        if (count[i] > 0)
        {
            a[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
    free(count);
}

int maximum(int *a, int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}