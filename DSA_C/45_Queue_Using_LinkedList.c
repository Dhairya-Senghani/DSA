/*
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void display(struct Node *);
void enqueue(struct Node **, struct Node **, int);
int dequeue(struct Node **);
int isFull(struct Node *, struct Node *);
int isEmpty(struct Node *);

int main()
{
    struct Node *f = NULL;
    struct Node *r = NULL;
    printf("is Empty? : %d\n", isEmpty(f));
    printf("is Full? : %d\n", isFull(f, r));
    printf("Dequeuing Element : %d\n",dequeue(&f));
    display(f);
    enqueue(&f, &r, 45);
    enqueue(&f, &r, 5);
    enqueue(&f, &r, 7);
    display(f);
    printf("Dequeuing Element : %d\n",dequeue(&f));
    printf("Dequeuing Element : %d\n",dequeue(&f));
    printf("Dequeuing Element : %d\n",dequeue(&f));
    printf("Dequeuing Element : %d\n",dequeue(&f));
    display(f);
    printf("is Empty? : %d\n", isEmpty(f));
    printf("is Full? : %d\n", isFull(f, r));
    return 0;
}

void display(struct Node *ptr)
{
    printf("Displaying Queue : \n");
    while (ptr != NULL)
    {
        printf("%0.2d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void enqueue(struct Node **f, struct Node **r, int element)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue is Full\n");
    }
    else
    {
        n->data = element;
        n->next = NULL;
        if (*f == NULL)
        {
            *f = n;
        }
        else
        {
            (*r)->next = n;
        }
        *r = n;
    }
}

int dequeue(struct Node **f)
{
    struct Node *ptr = *f;
    int element = -1;
    if (*f == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        *f = (*f)->next;
        element = ptr->data;
        free(ptr);
    }
    return element;
}

int isEmpty(struct Node *f)
{
    if (f == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *f, struct Node *r)
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
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct queue
{
    struct Node *f;
    struct Node *r;
};

void display(struct queue *);
void enqueue(struct queue *, int);
int dequeue(struct queue *);
int isFull(struct queue *);
int isEmpty(struct queue *);

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->f = q->r = NULL;

    printf("is Empty? : %d\n", isEmpty(q));
    printf("is Full? : %d\n", isFull(q));
    printf("Dequeuing Element : %d\n", dequeue(q));
    display(q);
    enqueue(q, 45);
    enqueue(q, 5);
    enqueue(q, 59);
    enqueue(q, 7);
    printf("is Empty? : %d\n", isEmpty(q));
    printf("is Full? : %d\n", isFull(q));
    display(q);
    printf("Dequeuing Element : %d\n", dequeue(q));
    printf("Dequeuing Element : %d\n", dequeue(q));
    printf("Dequeuing Element : %d\n", dequeue(q));
    printf("Dequeuing Element : %d\n", dequeue(q));
    printf("Dequeuing Element : %d\n", dequeue(q));
    display(q);
    printf("is Empty? : %d\n", isEmpty(q));
    printf("is Full? : %d\n", isFull(q));
    return 0;
}

void display(struct queue *q)
{
    struct Node *f = q->f;
    printf("Displaying Queue : \n");
    while (f != NULL)
    {
        printf("%0.2d ", f->data);
        f = f->next;
    }
    printf("\n");
}

void enqueue(struct queue *q, int element)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue is Full\n");
    }
    else
    {
        n->data = element;
        n->next = NULL;
        if (q->f == NULL)
        {
            q->f = n;
        }
        else
        {
            q->r->next = n;
        }
        q->r = n;
    }
}

int dequeue(struct queue *q)
{
    struct Node *ptr = q->f;
    int element = -1;
    if (q->f == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->f = q->f->next;
        element = ptr->data;
        free(ptr);
    }
    return element;
}

int isEmpty(struct queue *q)
{
    if (q->f == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct queue *q)
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