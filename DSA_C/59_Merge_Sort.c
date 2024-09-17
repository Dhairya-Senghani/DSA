// *********** Merge Sort ********************
// NOT MODIFIED PLEASE READ FROM GFG WEBSITE
// Stable : NO
// Adaptive : NO  (not sure, verify)
// Inplace : YES
// TIME COMPLEXITY
// Worst case : O(n^2)  when array is already sorted
// Best case : O(nlog(n))
// Average : O(nlog(n))
// Space Complexity : O(1) (not sure, verify)

#include <stdio.h>
#include <stdlib.h>

void printArray(int *, int);
// void mergeSort(int *, int *, int *, int, int);
void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int main()
{
    int a[] = {3, 2, 0, 91, 56, 83, -6, -56, 99, -32, 30, 49, 9, 5, 45};
    // int b[] = {1, 5, 25, 65, 87, 90, 95, 99};
    // int a[] = {2, 4, 1, 5, 23, 21};
    // int a[]= {47, 85, 23, 95, 12, 67, 34, 92, 19, 81, 73, 46, 39, 57, 88, 16, 94, 63, 21, 75, 10, 56, 87, 30, 82, 24, 68, 93, 18, 79, 40, 53, 91, 29, 65, 15, 58, 84, 36, 71, 11, 66, 33, 48, 22, 78, 41, 55, 90, 26, 62, 17, 70, 20, 77, 43, 52, 89, 32, 74, 13, 59, 80, 27, 61, 31, 50, 86, 28, 64, 14, 60, 25, 76, 44, 51, 83, 35, 72, 38, 69, 37, 49, 96, 54, 45, 97, 98, 99, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 42};
    // int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};

    int length = sizeof(a) / sizeof(a[0]);

    printArray(a, length);
    mergeSort(a, 0, length - 1);
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

void mergeSort(int *a, int low, int high)
{
    int mid = low + (high - low) / 2;

    if (low < high)
    {
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int *a, int low, int mid, int high)
{
    int i, j, k;
    int *b = (int *)malloc((high - low + 1) * sizeof(int));
    i = low;
    j = mid + 1;
    k = 0; // Start the index of b from 0.
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        b[k++] = a[i++];
    }
    while (j <= high)
    {
        b[k++] = a[j++];
    }
    for (i = low; i <= high; i++)
    {
        a[i] = b[i - low]; // Index of b is starting from 0.
    }
    free(b);
}

// Function which takes two array and merge them in one array.
// void mergeSort(int *a, int *b, int *c, int n, int m)
// {
//     int i, j, k;
//     i = j = k = 0;
//     while (i < n && j < m)
//     {
//         if (a[i] < b[j])
//         {
//             c[k] = a[i++];
//         }
//         else
//         {
//             c[k] = b[j++];
//         }
//         k++;
//     }
//     while (i < n)
//     {
//         c[k++] = a[i++];
//     }
//     while (j < m)
//     {
//         c[k++] = b[j++];
//     }
// }