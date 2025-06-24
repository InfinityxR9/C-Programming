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
        printf("Stack Overflow\n");
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

    printf("Stack Underflow\n");
    return '\0';
}

int getPrecedence(char operator)
{
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/')
        return 2;
    if (operator == '^')
        return 3;

    return -1;
}

int main()
{
    // char *str = "a+b*d-e+g*h-i";
    char *str = "a+b*(c^d-e)^(f+g*h)-i";
    // char *str = "a+b*(d-e)+(g*h)-i";
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->size = strlen(str) + 1;
    stack->arr = (char *)malloc(stack->size * sizeof(char));

    char *postFix = (char *)malloc(stack->size * sizeof(char));
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
        {
            if (getPrecedence(str[i]) > getPrecedence(stack->arr[stack->top]))
            {
                push(stack, str[i]);
                continue;
            }
            else
            {
                char element;
                while (!isEmpty(stack) && getPrecedence(stack->arr[stack->top]) >= getPrecedence(str[i]))
                {
                    element = pop(stack);
                    postFix[size++] = element;
                }
                push(stack, str[i]);
                continue;
            }
        }
        
        else if (str[i] == '(') {
            push(stack, str[i]);
            continue;
        }
        
        else if (str[i] == ')') {
            char popEl;
            while(!isEmpty(stack) && stack->arr[stack->top] !='(') {
                popEl = pop(stack);
                postFix[size++] = popEl;
            }
            pop(stack);
        }

        else
        {
            postFix[size++] = str[i];
        }
    }

    char popElement;
    while (stack->top != -1)
    {
        popElement = pop(stack);
        postFix[size++] = popElement;
    }

    postFix[size] = '\0';
    printf("size is %d\n", size);
    printf("PostFix is %s\n", postFix);

    free(stack->arr);
    free(stack);
    free(postFix);

    return 0;
}