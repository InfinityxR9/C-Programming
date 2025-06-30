#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *front, *rear = NULL;

void Display()
{
    Node *ptr = front;
    while (ptr != NULL)
    {
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));

    if (node == NULL)
        printf("Queue is full");

    else
    {
        node->data = val;
        node->next = NULL;

        if (front == NULL)
        {
            printf("i'm here");
            front = rear = node;
        }

        else
        {
            rear->next = node;
            rear = node;
        }
    }
}

int dequeue()
{
    int checkVal_or_returnVal = -1;
    if (front != NULL)
    {
        Node *ptr = front;
        front = front->next;
        checkVal_or_returnVal = ptr->data;
        free(ptr);
    }
    else
        printf("Queue underflow");

    return checkVal_or_returnVal;
}

int peek(int peek_index)
{ // returns the postioned node from the front
    if (peek_index > 0)
    {
        Node *ptr = front;
        while (peek_index > 1 && ptr != NULL)
        {
            ptr = ptr->next;
            peek_index--;
        }

        if (ptr == NULL)
            return -1;
        return ptr->data;
    }
    return -1;
}

int main()
{
    Display();
    enqueue(67);
    enqueue(46);
    enqueue(96);
    enqueue(69);
    enqueue(30);
    Display();
    dequeue();
    dequeue();
    dequeue();
    printf("-------------------------\n");
    Display();
    printf("front data: %d ", front->data);

    int peek_index = 2;
    printf("\nThe data at peek_index %d is %d", peek_index, peek(peek_index));
    return 0;
}