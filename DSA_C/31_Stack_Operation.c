#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *);
void push(int);
int pop();
int isEmpty(struct Node *);
int isFull(struct Node *);
int peak(struct Node *, int);

struct Node *top = NULL;

int main()
{
    linkedListTraversal(top);
    push(45);
    push(78);
    push(90);
    linkedListTraversal(top);
    printf("Peak element at %d is : %d\n", 1, peak(top, 1));
    printf("Peak element at %d is : %d\n", 2, peak(top, 2));
    printf("Peak element at %d is : %d\n", 3, peak(top, 3));
    return 0;
}

int peak(struct Node *top, int position)
{
    for (int i = 1; (i < position && top != NULL); i++)
    {
        top = top->next;
    }
    if (top != NULL)
    {
        return top->data;
    }
    else
    {
        return -1;
    }
}

void linkedListTraversal(struct Node *top)
{
    printf("Printing Stack Using Linked List :\n");
    while (top != NULL)
    {
        printf("%0.2d ", top->data);
        top = top->next;
    }
    printf("\n");
}

void push(int element)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = element;
        n->next = top;
        top = n;
    }
}

int pop()
{
    if (isEmpty(top))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        struct Node *n = top;
        int element = top->data;
        top = top->next;
        free(n);
        return element;
    }
}
int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}