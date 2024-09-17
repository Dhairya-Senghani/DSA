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
void enqueue_Back(struct queue *, int);
void enqueue_Front(struct queue *, int);
int dequeue_Front(struct queue *);
int dequeue_Back(struct queue *);
int isFull(struct queue *);
int isEmpty(struct queue *);

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->f = q->r = NULL;

    printf("is Empty? : %d\n", isEmpty(q));
    printf("is Full? : %d\n", isFull(q));
    printf("Dequeuing Element : %d\n", dequeue_Front(q));
    display(q);
    enqueue_Back(q, 68);
    enqueue_Back(q, 42);
    enqueue_Front(q, 5);
    enqueue_Front(q, 95);
    printf("is Empty? : %d\n", isEmpty(q));
    printf("is Full? : %d\n", isFull(q));
    display(q);
    printf("Dequeuing Element : %d\n", dequeue_Front(q));
    printf("Dequeuing Element : %d\n", dequeue_Front(q));
    printf("Dequeuing Element : %d\n", dequeue_Back(q));
    printf("Dequeuing Element : %d\n", dequeue_Back(q));
    printf("Dequeuing Element : %d\n", dequeue_Back(q));
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

void enqueue_Back(struct queue *q, int element)
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

int dequeue_Front(struct queue *q)
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

void enqueue_Front(struct queue *q, int element)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Double Ended Queue is Empty\n");
    }
    else
    {
        n->data = element;
        n->next = q->f;
        if (q->r == NULL)
        {
            q->r = n;
        }

        q->f = n;
    }
}

int dequeue_Back(struct queue *q)
{
    int element = -1;
    if (q->f == NULL)
    {
        printf("Double Ended Queue is Empty\n");
    }
    else
    {
        struct Node *ptr = q->f;
        element = q->r->data;
        if (ptr == q->r)
        {
            free(q->r);
            q->r = NULL;
            q->f = NULL;
        }
        else
        {
            while (ptr->next != q->r)
            {
                // printf("DOFO\n");
                ptr = ptr->next;
            }
            free(q->r);
            q->r = ptr;
        }
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