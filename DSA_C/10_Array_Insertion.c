#include <stdio.h>

void Display(int *, int);
int indexInsertion(int *, int *, int, int, int);
int sortInsertion(int *, int *, int, int);
void indexDeletion(int *, int *, int);

int main()
{
    int arr[10] = {7, 8, 12, 27, 88};
    int capacity = sizeof(arr) / sizeof(arr[0]);
    int size = 5;
    Display(arr, size);
    indexInsertion(arr, &size, capacity, 3, 45);
    Display(arr, size);
    sortInsertion(arr, &size, capacity, 15);
    Display(arr, size);
    indexDeletion(arr, &size, 3);
    Display(arr, size);
    return 0;
}

void Display(int arr[], int size)
{
    // Code for Traversal
    printf("Diaplaying Array : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%0.2d ", arr[i]);
    }
    printf("\n");
}

int indexInsertion(int arr[], int *size, int capacity, int index, int element)
{
    if (*size >= capacity)
    {
        return -1;
    }

    for (int i = *size; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    (*size)++;
    return 1;
}

int sortInsertion(int arr[], int *size, int capacity, int element)
{
    if (*size >= capacity)
    {
        return -1;
    }
    int i = (*size) - 1;
    for (; (arr[i] > element) && i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[i + 1] = element;
    (*size)++;
    return 1;
}

void indexDeletion(int arr[], int *size, int index)
{
    for (int i = index; i < (*size) - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}