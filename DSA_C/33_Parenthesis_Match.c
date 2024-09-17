#include <stdio.h>
#include <stdlib.h>
#include<string.h>


struct stack
{
    int size;
    int top;
    char *arr;
};

int isParenthesisMatch(char *);
void push(struct stack *, char);
char pop(struct stack *);
int isEmpty(struct stack *);
int isFull(struct stack *);

int main()
{
    char *str = "(6+(5+(2/3)*6)*((a+b)*5+6))+3";
    char *str2 = ")(6+(5+(2/3)*6)*((a+b)*5+6))+3";
    char * str3= "";
    printf("Is Parenthesis Match ? : %d\n", isParenthesisMatch(str));
    printf("Is Parenthesis Match ? : %d\n", isParenthesisMatch(str2));
    printf("Is Parenthesis Match ? : %d\n", isParenthesisMatch(str3));
    return 0;
}

int isParenthesisMatch(char *str)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = strlen(str) + 1;  // Include NULL Character
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '(')
        {
            push(sp, str[i]);
        }
        else if (str[i] == ')')
        {
            if (isEmpty(sp) == 1)
            {
                return 0;
            }
            else
            {
                pop(sp);
            }
        }
        i++;
    }
    if (isEmpty(sp) == 1)
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