#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

void display(struct stack *);
void push(struct stack *, int);
int pop(struct stack *);
int peak(struct stack *, int);
int isEmpty(struct stack *ptr);
int isFull(struct stack *);
int stackTop(struct stack *);
int stackBottom(struct stack *);

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack)); // sp for structure pointer
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    push(sp, 3);
    push(sp, 6);
    push(sp, 9);
    push(sp, 12);
    push(sp, 15);
    push(sp, 18);
    display(sp);
    pop(sp);
    pop(sp);
    display(sp);
    printf("The value at position %d is %d\n", 1, peak(sp, 1));
    printf("The value at position %d is %d\n", 2, peak(sp, 2));
    printf("The value at position %d is %d\n", 3, peak(sp, 3));
    printf("The value at position %d is %d\n", 4, peak(sp, 4));
    printf("The value at position %d is %d\n", 5, peak(sp, 5));
    printf("The value at position %d is %d\n", 6, peak(sp, 6));
    printf("The value at position %d is %d\n", 7, peak(sp, 7));
    printf("The value at position %d is %d\n", 8, peak(sp, 7));

    printf("Top element is : %d\n", stackTop(sp));
    printf("Bottom element is : %d\n", stackBottom(sp));
    return 0;
}

void display(struct stack *ptr)
{
    printf("Displaying Stack :\n");
    for (int i = 0; i <= ptr->top; i++)
    {
        printf("%0.2d ", ptr->arr[i]);
    }
    printf("\n");
}

void push(struct stack *ptr, int element)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return (ptr->arr[(ptr->top)--]);
    }
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int peak(struct stack *ptr, int position)
{
    int index = ptr->top - position + 1;
    if (index < 0)
    {
        printf("Not a Valid Position\n");
        return -1;
    }
    else
    {
        return ptr->arr[index];
    }
}

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int stackBottom(struct stack *sp)
{
    return sp->arr[0];
}