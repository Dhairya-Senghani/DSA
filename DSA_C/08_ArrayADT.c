/* Implementing Array as an Abstract Data Type in C Language */
#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize * sizeof(int));
    // Sam as
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void showArray(struct myArray *a)
{
    printf("Printing the Array : \n");
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%0.2d ", (a->ptr)[i]);
    }
}

void setArray(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the Element %d : ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}
int main()
{
    struct myArray marks;
    createArray(&marks, 10, 3);
    setArray(&marks);
    showArray(&marks);

    return 0;
}