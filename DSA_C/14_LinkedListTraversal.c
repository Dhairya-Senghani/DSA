/* Singly Linked List */
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *);

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // link second and third nodes
    second->data = 11;
    second->next = third;

    // Terminate the list at thirs node
    third->data = 66;
    third->next = NULL;

    linkedlistTraversal(head);

    return 0;
}


// Display Linked List
void linkedlistTraversal(struct Node *node)
{
    printf("Printing Linkedlist : \n");
    while (node != NULL)
    {
        printf("At Location %d : Element = %d\n", node, node->data);
        node = node->next;
    }
}