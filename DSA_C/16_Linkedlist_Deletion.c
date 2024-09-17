/* Singly Linked List */
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Display(struct Node *);
struct Node *insertAtFirst(struct Node *head, int data);
struct Node *deleteAtFirst(struct Node *);
void deleteAtIndex(struct Node *, int);
void deleteAtEnd(struct Node *);
struct Node *deleteValue(struct Node *, int);
void deleteAfterNode(struct Node *);

int main()
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 45;
    head->next = NULL;
    head = insertAtFirst(head, 56);
    head = insertAtFirst(head, 6);
    head = insertAtFirst(head, 5);
    head = insertAtFirst(head, 65);
    head = insertAtFirst(head, 4);
    head = insertAtFirst(head, 66);
    Display(head);
    head = deleteAtFirst(head);
    Display(head);
    deleteAtEnd(head);
    Display(head);
    deleteAtIndex(head, 2);
    Display(head);
    head = deleteValue(head, 6);
    Display(head);
    deleteAfterNode(head->next);
    Display(head);

    return 0;
}

void Display(struct Node *node)
{
    printf("Displaying Linked List :\n");
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

struct Node *deleteAtFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

void deleteAtEnd(struct Node *head)
{
    while (head->next->next != NULL)
    {
        head = head->next;
    }
    free(head->next);    // See the sequence for correct output
    head->next = NULL;
}

void deleteAtIndex(struct Node *head, int index)
{
    while (index != 1)
    {
        head = head->next;
        index--;
    }
    struct Node *ptr = head->next;
    head->next = ptr->next;
    free(ptr);
}

void deleteAfterNode(struct Node *node)
{
    node->next = node->next->next;

    // struct Node *ptr = node->next;
    // node->next = ptr->next;
    // free(ptr);

    // Select the fair solution
}

struct Node *deleteValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}