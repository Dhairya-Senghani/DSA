#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void display(struct Node *);
struct Node *insertAtFirst(struct Node *, int);
void insertAtIndex(struct Node *, int, int);

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 45;
    head->next = head;
    display(head);

    head = insertAtFirst(head, 65);
    head = insertAtFirst(head, 12);
    head = insertAtFirst(head, 5);
    head = insertAtFirst(head, 43);
    head = insertAtFirst(head, 81);
    head = insertAtFirst(head, 90);
    display(head);

    insertatIndex(head, 2, 100);
    display(head);

    return 0;
}

void display(struct Node *head)
{
    printf("Displayin Circular Linked List : \n");
    struct Node *p = head;
    do
    {
        printf("%0.2d ", p->data);
        p = p->next;
    } while (p != head);

    // OR
    // while (p->next != head)
    // {
    //     printf("%0.2d ", p->data);
    //     p = p->next;
    // }
    // printf("%0.2d ", p->data);

    printf("\n");
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head->next;
    ptr->data = data;
    ptr->next = head;

    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}