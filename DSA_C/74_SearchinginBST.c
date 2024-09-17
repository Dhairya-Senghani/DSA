#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int isPresent(struct node *root, int);
struct node *search(struct node *, int);
void inOrder(struct node *);
struct node *createNode(int);

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

    int key = 3;
    inOrder(p);
    printf("\nIs %d present ? : %d\n", key, isPresent(p, key));
    printf("%d present at node with address : 0x%p", key, search(p, key));
    printf("\nValue at adress 0x%p is %d\n", search(p, key), search(p, key)->data);

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

int isPresent(struct node *root, int key)
{
    if (root != NULL)
    {

        if (key == root->data)
        {
            return 1;
        }
        else if (key < root->data)
        {
            return isPresent(root->left, key);
        }
        else
        {
            return isPresent(root->right, key);
        }
    }
    else
    {
        return 0;
    }
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
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