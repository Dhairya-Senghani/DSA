#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

void enqueue(struct queue *, int);
int dequeue(struct queue *);
int isFull(struct queue *);
int isEmpty(struct queue *);

int main()
{
    struct queue q;
    q.size = 4;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    printf("is empty : %d\n", isEmpty(&q));
    printf("is full : %d\n", isFull(&q));
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 78);
    enqueue(&q, 98);
    // enqueue(&q, 12);
    // dequeue(&q);
    // dequeue(&q);
    printf("Dequeuing element : %d\n", dequeue(&q));
    printf("Dequeuing element : %d\n", dequeue(&q));
    printf("Dequeuing element : %d\n", dequeue(&q));
    printf("Dequeuing element : %d\n", dequeue(&q));
    enqueue(&q, 12);
    printf("Dequeuing element : %d\n", dequeue(&q));
    printf("is empty : %d\n", isEmpty(&q));
    printf("is full : %d\n", isFull(&q));
    return 0;
}


void enqueue(struct queue *q, int element)
{
    if (isFull(q))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = element;
    }
}


int dequeue(struct queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        q->f++;
        return q->arr[q->f];
    }
}


int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}