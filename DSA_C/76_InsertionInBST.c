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
void insert(struct node *, int);

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

    int key = 8;
    inOrder(p);
    insert(p, key);
    printf("\nok is : %d\n", p->right->right->data);
    inOrder(p);

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

void insert(struct node *root, int element)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (element == root->data)
        {
            printf("\nInsertion Unsucessfull !!!\n");
            printf("Already in BST !!\n");
            return;
        }
        else if (element < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    struct node *new = createNode(element);
    
    if (element < prev->data)
    {prev->left=new;
    }
    else{
        prev->right = new;
    }
}