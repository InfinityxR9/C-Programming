#include <stdio.h>
#include <stdlib.h>

typedef struct Node_Linked_List
{
    int data;
    struct Node_Linked_List *next;
} Node;

int isEmpty(Node *top)
{
    if (top == NULL)
        return 1;
    return 0;
}

int isFull(Node *top)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL)
        return 1;

    free(n);
    return 0;
}

void Display(Node *top)
{
    Node *ptr = top;
    if (!isEmpty(ptr))
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        };
    }
    else
        printf("Stack is empty");
}

void push(Node **top_ref, int value)
{
    if (!isFull(*top_ref))
    {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = value;
        node->next = *top_ref;
        *top_ref = node;
    }
    else
        printf("Stack overflow");
}

int pop(Node **top_ref)
{
    if (!isEmpty(*top_ref))
    {
        Node *ptr = *top_ref;
        *top_ref = (*top_ref)->next;
        int data = ptr->data;
        free(ptr);
        return data;
    }
    else
        printf("Stack underflow");
}

int size(Node *top)
{
    int size = 0;
    while (top != NULL)
    {
        top = top->next;
        size++;
    }

    return size;
}

int peek(Node *top, int index)
{
    if (size(top) >= index)
    {
        Node *ptr = top;
        int val;
        for (int i = 1; (i <= index && ptr != NULL); i++)
        {
            val = ptr->data;
            ptr = ptr->next;
        }

        return val;
    }

    printf("Index exceeded");
    return -1;
}

int stackTop(Node *top)
{
    if (!isEmpty(top))
    {
        return top->data;
    }

    return -1;
}

int stackBottom(Node *top)
{
    if (!isEmpty(top))
    {
        Node *ptr = top;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        return ptr->data;
    }

    return -1;
}

void free_Nodes(Node **top_ref)
{
    Node *temp;
    Node *top = *top_ref;
    while (top != NULL)
    {
        temp = top;
        top = top->next;
        free(temp);
    }
    *top_ref = NULL;
}

int main()
{
    Node *top = NULL;

    Display(top);
    printf("\nisEmpty %d", isEmpty(top));
    printf("\nisFull %d\n", isFull(top));

    push(&top, 56);
    push(&top, 64);

    Display(top);
    printf("\nDisplay top successful");
    printf("\nisEmpty %d", isEmpty(top));
    printf("\nisFull %d\n", isFull(top));

    pop(&top);

    Display(top);
    printf("\nDisplay top successful");
    printf("\nisEmpty %d", isEmpty(top));
    printf("\nisFull %d\n", isFull(top));

    push(&top, 100);
    push(&top, 69);
    push(&top, 195);
    Display(top);
    int i = 2;
    printf("\nvalue at index %d is %d", i, peek(top, i));
    printf("\nstackTop value is %d", stackTop(top));
    printf("\nstackBottom value is %d", stackBottom(top));

    free_Nodes(&top);

    return 0;
}