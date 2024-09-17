#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Display(struct Node *);
struct Node *insertAtFirst(struct Node *, int);
void insertAtIndex(struct Node *, int, int);
void insertAtEnd(struct Node *, int);
void insertAfterNode(struct Node *, int);

int main()
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 45;
    head->next = NULL;
    Display(head);
    head = insertAtFirst(head, 56);
    head = insertAtFirst(head, 5);
    Display(head);
    insertAtIndex(head, 1, 20);
    Display(head);
    insertAtIndex(head, 4, 89);
    Display(head);
    insertAtEnd(head, 27);
    Display(head);
    insertAtEnd(head, 49);
    Display(head);
    insertAfterNode(head->next->next->next, 99);
    Display(head);

    return 0;
}

void Display(struct Node *node)
{
    printf("Displaying Linkedl List :\n");
    while (node != NULL)
    {
        printf("%0.2d ", node->data);
        node = node->next;
    }
    printf("\n");
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}

void insertAtIndex(struct Node *head, int index, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    while (index != 1)
    {
        head = head->next;
        index--;
    }
    ptr->data = data;
    ptr->next = head->next;
    head->next = ptr;
}

void insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = ptr;
    ptr->next = NULL;
}

void insertAfterNode(struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
}