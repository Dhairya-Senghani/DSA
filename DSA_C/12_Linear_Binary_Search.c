#include <stdio.h>

int linearSearch(int *, int, int);
int binarySearch(int *, int, int);

int main()
{
    // Linear Search
    // int arr[] = {1, 3, 5, 56, 4, 3, 23, 5, 4, 54634, 56, 23};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // int element = 45;
    // int searchIndex = linearSearch(arr, size, element);
    // printf("Element %d found at index %d.", element, searchIndex);

    // Binary Search
    int arr[] = {1, 5, 9, 15, 23, 45, 98, 154, 289};   // Array needs to be sorted
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 9;
    int searchIndex = binarySearch(arr, size, element);
    printf("Element %d found at index %d.", element, searchIndex);

    return 0;
}

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == element)
        {
            return mid;
        }

        if (arr[mid] > element)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}