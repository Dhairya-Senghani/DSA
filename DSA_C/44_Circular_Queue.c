#include <stdio.h>
#include <stdlib.h>

struct circularqueue
{
    int size;
    int f; // Front position will always be empty(int circular queue).
    int r;
    int *arr;
};

void enqueue(struct circularqueue *, int);
int dequeue(struct circularqueue *);
int isEmpty(struct circularqueue *);
int isFull(struct circularqueue *);
void display(struct circularqueue *);

int main()
{
    struct circularqueue *q;
    q = (struct circularqueue *)malloc(sizeof(struct circularqueue));
    q->size = 4;
    // q->f = q->r = q->size - 1;
    q->f = q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    printf("is Empty? : %d\n", isEmpty(q));
    printf("is Full? : %d\n", isFull(q));
    enqueue(q, 45);
    enqueue(q, 5);
    enqueue(q, 68);
    printf("Dequeuing Element : %d\n", dequeue(q));
    enqueue(q, 79);
    display(q);
    // enqueue(q, 45);
    printf("is Empty? : %d\n", isEmpty(q));
    printf("is Full? : %d\n", isFull(q));
    printf("Dequeuing Element : %d\n", dequeue(q));
    display(q);
    printf("Dequeuing Element : %d\n", dequeue(q));
    display(q);
    printf("Dequeuing Element : %d\n", dequeue(q));
    display(q);
    printf("Dequeuing Element : %d\n", dequeue(q));
    display(q);
    // printf("Dequeuing Element : %d\n", dequeue(q));
    // printf("Dequeuing Element : %d\n", dequeue(q));
    printf("is Empty? : %d\n", isEmpty(q));
    printf("is Full? : %d\n", isFull(q));

    return 0;
}

void enqueue(struct circularqueue *q, int element)
{
    if (isFull(q))
    {
        printf("Circuler Queue Overflow!\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = element;
    }
}

int dequeue(struct circularqueue *q)
{
    if (isEmpty(q))
    {
        printf("Circular Queue Underflow!\n");
        return -1;
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        return q->arr[q->f];
    }
}

int isEmpty(struct circularqueue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

int isFull(struct circularqueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

void display(struct circularqueue *q)
{
    printf("Displaying Circular Queue\n");
    for (int i = (q->f + 1) % q->size; i != (q->r + 1) % q->size; i = (i + 1) % q->size)
    {
        printf("%0.2d ", q->arr[i]);
    }
    printf("\n");
}