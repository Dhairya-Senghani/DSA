// Bubble Sort
// Stable : YES
// Adaptive : CAN BE MADE
// TIME COMPLEXITY
// Worst case : O(n^2)
// Best case : O(n)  (if Adeptive (may be))
// Average : O(n^2)
// Space Complexity : O(1)
// Intermediate results are usefull (After one pass we come to know that largest element is at the end).
// i.e. If we want to find largesr 3 elements of the given array than we can do bubble sort for the 3 pass only.

#include <stdio.h>
#include <stdlib.h>

void printArray(int *, int);
void bubbleSort(int *, int);

int main()
{
    // int a[] = {12, 54, 65, 7, 23, 9};
    int a[] = {2, 4, 5, 7, 23, 21};
    // int a[]= {47, 85, 23, 95, 12, 67, 34, 92, 19, 81, 73, 46, 39, 57, 88, 16, 94, 63, 21, 75, 10, 56, 87, 30, 82, 24, 68, 93, 18, 79, 40, 53, 91, 29, 65, 15, 58, 84, 36, 71, 11, 66, 33, 48, 22, 78, 41, 55, 90, 26, 62, 17, 70, 20, 77, 43, 52, 89, 32, 74, 13, 59, 80, 27, 61, 31, 50, 86, 28, 64, 14, 60, 25, 76, 44, 51, 83, 35, 72, 38, 69, 37, 49, 96, 54, 45, 97, 98, 99, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 42};
    // int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};

    int length = sizeof(a) / sizeof(a[0]);
    printArray(a, length);
    bubbleSort(a, length);
    printArray(a, length);
    return 0;
}

void printArray(int *a, int length)
{
    printf("Printing Array : \n");
    for (int i = 0; i < length; i++)
    {
        printf("%0.2d ", a[i]);
    }
    printf("\n");
}

void bubbleSort(int *a, int length)
{
    int temp;
    int isSorted;
    // for (int i = 0; i < length - 1; i++)
    for (int i = 1; i < length; i++)
    {
        isSorted = 1;
        printf("Working on Pass %d\n", i);

        // for (int j = 0; j < length - 1 - i; j++)
        for (int j = 0; j < length - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted == 1) // To make the algorithm Adaptive
        {
            break;
            // return;
        }
    }
}