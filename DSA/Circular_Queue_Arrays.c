#include <stdio.h>
#include <stdlib.h>

// This will be a by default Circular Queue
typedef struct Queue_Arrays
{
    int front;
    int rear;
    int *arr;
    int size;
} Queue;

void Display(Queue *queue)
{
    printf("\n");
    for (int i = queue->front + 1; i <= queue->rear; i++)
    {
        printf("%d ", queue->arr[i]);
    }
}

int isFull(Queue *queue)
{
    if ((queue->rear + 1) % queue->size == queue->front)
        return 1;
    return 0;
}

int isEmpty(Queue *queue)
{
    if (queue->front == queue->rear)
        return 1;
    return 0;
}

int queue_front(Queue *queue)
{
    return queue->arr[queue->front + 1];
}

int queue_rear(Queue *queue)
{
    return queue->arr[queue->rear];
}

void enqueue(Queue *queue, int val)
{
    if (!isFull(queue))
    {
        queue->rear = (queue->rear + 1) % queue->size;
        queue->arr[queue->rear] = val;
    }
    else
        printf("Queue overflow");
}

int dequeue(Queue *queue)
{
    int checkVal_or_returnVal = -1;
    if (!isEmpty(queue))
    {
        queue->front = (queue->front + 1) % queue->size;
        checkVal_or_returnVal = queue->arr[queue->front];
    }
    else
        printf("Queue underflow");

    return checkVal_or_returnVal;
}

int peek(Queue *queue, int peek_index)
{ // peek_index is the position (starting from 1, from the front of the queue) of the element to be returned
    if (0 < peek_index && peek_index <= queue->front + queue->rear)
    {
        return queue->arr[peek_index + queue->front];
    }
    return -1;
}

int main()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->size = 7;
    queue->front = queue->rear = 0;
    queue->arr = (int *)malloc((queue->size + 1) * sizeof(int));

    Display(queue);
    enqueue(queue, 60);
    enqueue(queue, 56);
    enqueue(queue, 98);
    enqueue(queue, 36);
    enqueue(queue, 59);
    enqueue(queue, 69);
    Display(queue);
    printf("%d", dequeue(queue));
    Display(queue);

    int peek_ind;
    printf("\nEnter peek index: ");
    scanf("%d", &peek_ind);

    printf("The element at peek_index %d is %d", peek_ind, peek(queue, peek_ind));

    printf("\nFront: %d, Rear: %d", queue->front, queue->rear);

    free(queue->arr);
    free(queue);

    return 0;
}