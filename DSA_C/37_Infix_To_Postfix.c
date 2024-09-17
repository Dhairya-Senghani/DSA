#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

char *InfixToPostfix(char *);
int isOperator(char);
int precidence(char);
int top(struct stack *);
void push(struct stack *, char);
char pop(struct stack *);
int isEmpty(struct stack *);
int isFull(struct stack *);

int main()
{
    char *str = "x-y/z-k*d";
    char *str2 = "a-b*d+c";
    char *str3 = "a-b+t/6";
    char *str4 = "";
    printf("Prefix : %s\n", str);
    printf("Postfix : %s\n", InfixToPostfix(str));
    printf("Prefix : %s\n", str2);
    printf("Postfix : %s\n", InfixToPostfix(str2));
    printf("Prefix : %s\n", str3);
    printf("Postfix : %s\n", InfixToPostfix(str3));
    printf("Prefix : %s\n", str4);
    printf("Postfix : %s\n", InfixToPostfix(str4));
    return 0;
}

char *InfixToPostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = strlen(infix) + 1; // Include NULL Character
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc(sp->size * sizeof(char));
    int i = 0; // Infix scanner
    int j = 0; // Postfix fill

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else if (precidence(infix[i]) > precidence(top(sp)))
        {
            push(sp, infix[i]);
            i++;
        }
        else
        {
            postfix[j] = pop(sp);
            j++;
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precidence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *sp, char element)
{
    if (isFull(sp) == 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = element;
    }
}

char pop(struct stack *sp)
{
    if (isEmpty(sp) == 1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return sp->arr[sp->top--];
    }
}

int top(struct stack *sp)
{
    return sp->arr[sp->top];
}

int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}