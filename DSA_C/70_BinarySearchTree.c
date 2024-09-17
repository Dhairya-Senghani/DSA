#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int isBST(struct node *);
void inOrder(struct node *root);
struct node *createNode(int);

int main()
{
    // This is not a BST
    // struct node *p = createNode(4);
    // struct node *p1 = createNode(1);
    // struct node *p2 = createNode(6);
    // struct node *p3 = createNode(5);
    // struct node *p4 = createNode(2);

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

    inOrder(p);
    printf("\nIs BST ? : %d", isBST(p));

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

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
    
        return isBST(root->right);

    }
    else{
        return 1;
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