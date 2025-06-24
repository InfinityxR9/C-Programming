#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack_Arrays
{
    int top;
    int size;
    char *arr;
} Stack;

int isEmpty(Stack *stack)
{
    if (stack->top == -1)
        return 1;
    return 0;
}

int isFull(Stack *stack)
{
    if (stack->top == stack->size - 1)
        return 1;
    return 0;
}

void push(Stack *stack, char value)
{
    if (!isFull(stack))
        stack->arr[++stack->top] = value;

    else
    {
        printf("Stack Overflow");
    }
}

char pop(Stack *stack)
{
    if (!isEmpty(stack))
    {
        char val = stack->arr[stack->top];
        stack->top--;
        return val;
    }

    printf("Stack Underflow");
}

int isMatch(Stack *stack, char str)
{
    char topVal = (stack->arr)[stack->top];

    if ((str == ')' && topVal == '(') || (str == '}' && topVal == '{') || (str == ']' && topVal == '['))
        return 1;

    return 0;
}

int main()
{
    char *str = "({{}}[])";
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->size = strlen(str);
    stack->arr = (char *)malloc(stack->size * sizeof(char));

    int isUnbalanced = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(stack, str[i]);
            continue;
        }
        if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (isMatch(stack, str[i]))
                pop(stack);
            else
            {
                isUnbalanced = 1;
                printf("Unbalanced");
                break;
            }
        }
    }

    if (!isUnbalanced)
    {
        if (isEmpty(stack))
        {
            printf("Balanced");
        }
        else
        {
            printf("Unbalanced");
        }
    }

    free(stack->arr);
    free(stack);

    return 0;
}