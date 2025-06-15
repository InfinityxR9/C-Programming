#include <stdio.h>
#include <stdlib.h>

typedef struct Stack_Arrays
{
    int top;
    int size;
    int *arr;
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

void Display(Stack *stack)
{
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->arr[i]);
    }
}

void push(Stack *stack, int value)
{
    if (!isFull(stack))
        stack->arr[++stack->top] = value;

    else
    {
        printf("Stack Overflow");
    }
}

int pop(Stack *stack)
{
    if (!isEmpty(stack))
    {
        int val = stack->arr[stack->top];
        stack->top--;
        return val;
    }

    printf("Stack Underflow");
}

int peek(Stack *stack, int index)
{
    if (index <= stack->top + 1 && index > 0)
        return stack->arr[index - 1];

    return -1;
}

int stackTop(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->arr[stack->top];
}

int stackBottom(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->arr[0];
}

int main()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->size = 5;
    stack->arr = (int *)malloc(stack->size * sizeof(int));

    Display(stack);
    printf("\nisEmpty %d", isEmpty(stack));
    printf("\nisFull %d\n", isFull(stack));

    push(stack, 56);

    Display(stack);
    printf("\nisEmpty %d", isEmpty(stack));
    printf("\nisFull %d\n", isFull(stack));

    // printf("%d", pop(stack));

    Display(stack);
    printf("\nisEmpty %d", isEmpty(stack));
    printf("\nisFull %d\n", isFull(stack));

    printf("%d\n", peek(stack, 1));
    printf("%d\n", peek(stack, 2));
    printf("%d\n", peek(stack, 0));

    push(stack, 96);

    printf("%d\n", stackTop(stack));
    printf("%d\n", stackBottom(stack));

    free(stack->arr);
    free(stack);

    return 0;
}