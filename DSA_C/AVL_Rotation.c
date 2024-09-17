#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
};

// global variabal
int i = 0;

int getHeight(struct node *);
struct node *createNode(int);
int getBalancedFactor(struct node *);
struct node *leftRotate(struct node *);
struct node *rightRotate(struct node *);
struct node *insert(struct node *, int);
int max(int, int);
void inOrder(struct node *);

int main()
{
    // struct node *root = NULL;
    // printf("address is %p\n", root);
    // root = insert(root, 1);
    // printf("address is %p\n", root);
    // root = insert(root, 2);
    // printf("address is %p\n", root);
    // root = insert(root, 4);
    // printf("address is %p\n", root);
    // root = insert(root, 5);
    // printf("address is %p\n", root);
    // root = insert(root, 6);
    // printf("address is %p\n", root);
    // root = insert(root, 3);

    // inOrder(root);

    return 0;
}

int getHeight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

struct node *createNode(int key)
{
    struct node *n = (struct node *)malloc(sizeof(struct node *));
    n->data = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

int getBalancedFactor(struct node *n)
{

    if (n == NULL)
    {
        return 0;
    }
    return (getHeight(n->left) - getHeight(n->right));
}

struct node *rightRotate(struct node *y)
{
    printf("rotating right\n");
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return x;
}

struct node *leftRotate(struct node *x)
{
    printf("rotating left\n");
    struct node *y = x->right;
    struct node *T2 = y->left;
    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

struct node *insert(struct node *n, int key)
{
    if (n == NULL)
    {
        // printf("DOFO is %d\n", i++);
        printf("inside n = NULL\n");
        return createNode(key);
    }
    if (key < n->data)
    {
        printf("inside key < n->data\n");
        n->left = insert(n->left, key);
    }
    else if (key > n->data)
    {
        printf("inside key > n->data\n");
        n->right = insert(n->right, key);
    }

    printf("geting height\n");
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    printf("getting balanced factor\n");
    int bf = getBalancedFactor(n);

    // Left Left Case
    if (bf > 1 && key < n->left->data)
    {
        printf("left left case\n");
        return rightRotate(n);
    }

    // Right Right Case
    if (bf < -1 && key > n->right->data)
    {
        printf("right right case\n");
        return leftRotate(n);
    }

    // Left Right Case
    if (bf > 1 && key > n->left->data)
    {
        printf("left right case\n");
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }

    // Right Left Case
    if (bf < -1 && key < n->right->data)
    {
        printf("right left case\n");
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }

    return n;
}

int max(int a, int b)
{
    printf("geting maximum\n");
    return (a > b) ? a : b;
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