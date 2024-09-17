#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *);
struct Node *push(struct Node *, int);
int pop(struct Node **);  // Instead of double pointer we can make top as a global variable.
int isEmpty(struct Node *);
int isFull(struct Node *);

int main()
{
    struct Node *top = NULL;
    top = push(top, 78);
    top = push(top, 8);
    top = push(top, 7);
    top = push(top, 54);
    linkedListTraversal(top);
    printf("Poped Element is : %d\n", pop(&top));
    printf("Poped Element is : %d\n", pop(&top));
    linkedListTraversal(top);
    return 0;
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

struct Node *push(struct Node *top, int element)
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
    return top;
}

int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        struct Node *n = *top;
        int element = (*top)->data;
        *top = (*top)->next;
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