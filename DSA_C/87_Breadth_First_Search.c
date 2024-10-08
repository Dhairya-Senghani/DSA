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
    // Initializing Queue (Array Implementation)
    struct queue q;
    q.size = 10;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    //   BFS Implementation
    int node;
    int i = 1;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i); // Enqueue i for exploration

    while (!isEmpty(&q))
    {

        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

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
    if (isEmpty(q))
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