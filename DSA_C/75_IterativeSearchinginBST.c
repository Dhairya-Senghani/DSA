#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int);
void inOrder(struct node *);
struct node *searchIter(struct node *, int);

int main()
{
    // This is a BST
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    int key = 6;
    inOrder(p);
    printf("\n%d present at node with address : 0x%p\n", key, searchIter(p, key));
    printf("Value at adress 0x%p is %d\n", searchIter(p, key), searchIter(p, key)->data);

    return 0;
}

struct node *createNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%0.2d ", root->data);
        inOrder(root->right);
    }
}

// Iterative approach
struct node *searchIter(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}