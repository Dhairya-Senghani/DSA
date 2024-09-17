// *********** Quick Sort ********************
// Stable : NO
// Adaptive : NO  (not sure, verify)
// Inplace : YES
// TIME COMPLEXITY
// Worst case : O(n^2)  when array is already sorted
// Best case : O(nlog(n))
// Average : O(nlog(n))
// Space Complexity : O(1) (not sure, verify)
// Partitioning = some linear function(n)
// If array is sorted than (n-1) partitions are required

#include <stdio.h>

void printArray(int *, int);
void quickSort(int *, int, int);
int partition(int *, int, int);

int main()
{
    int a[] = {3, 5, 2, 13, 12, 2, 13, 45};
    // int a[] = {12, 54, 65, 7, 23, 9};
    // int a[] = {2, 4, 5, 5, 23, 21};
    // int a[]= {47, 85, 23, 95, 12, 67, 34, 92, 19, 81, 73, 46, 39, 57, 88, 16, 94, 63, 21, 75, 10, 56, 87, 30, 82, 24, 68, 93, 18, 79, 40, 53, 91, 29, 65, 15, 58, 84, 36, 71, 11, 66, 33, 48, 22, 78, 41, 55, 90, 26, 62, 17, 70, 20, 77, 43, 52, 89, 32, 74, 13, 59, 80, 27, 61, 31, 50, 86, 28, 64, 14, 60, 25, 76, 44, 51, 83, 35, 72, 38, 69, 37, 49, 96, 54, 45, 97, 98, 99, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 42};
    // int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};

    int length = sizeof(a) / sizeof(a[0]);
    printArray(a, length);
    quickSort(a, 0, length - 1);
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

void quickSort(int *a, int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(a, low, high);
        quickSort(a, low, partitionIndex - 1);  // Sort left subarray
        quickSort(a, partitionIndex + 1, high); // Sort right subarray
        // printArray(a, 8);
        // printf("Partition Index : %d\n", partitionIndex);
    }
}

int partition(int *a, int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        // else{
        //     temp=a[j];
        //     a[j] = a[low];
        //     a[low] = temp;
        // }
    } while (i < j);

    // Swap a[low] & a[j]
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}