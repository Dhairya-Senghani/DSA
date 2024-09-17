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
int isEmpty(struct stack *ptr);
int isFull(struct stack *);

int main()
{
    // struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    struct stack *s;
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("The stack is Empty : %d\n", isEmpty(s));
    printf("The stack is FUll : %d\n", isFull(s));

    // s->arr[0] = 45;
    // s->top ++;
    push(s, 90);
    push(s, 56);
    push(s, 57);
    push(s, 58);
    push(s, 59);
    push(s, 50);
    push(s, 51);
    display(s);

    printf("Poped element is : %d\n", pop(s));
    printf("Poped element is : %d\n", pop(s));
    printf("Poped element is : %d\n", pop(s));
    printf("Poped element is : %d\n", pop(s));
    printf("Poped element is : %d\n", pop(s));
    printf("Poped element is : %d\n", pop(s));
    printf("Poped element is : %d\n", pop(s));
    printf("Poped element is : %d\n", pop(s));


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
        return 0;
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