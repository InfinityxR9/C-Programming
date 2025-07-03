#include <stdio.h>
#include <stdlib.h>

// Short form: DEqueue, not to be confused with the Queue operation - dequeue()
// Implementation using Arrays
// Extended version of the Linear Array Queue Structure

/* 
Allowed operations:
    enqueue() from both front and rear ends
    dequeue() from both front and rear ends
*/

typedef struct Double_Ended_Queue {
    int front;
    int rear;
    int size;
    int* arr;
} DEQueue;

void display(DEQueue *queue)
{
    printf("\n");
    for (int i = queue->front + 1; i <= queue->rear; i++)
    {
        printf("%d ", queue->arr[i]);
    }
}

int isFull(DEQueue *queue)
{
    if (queue->rear == queue->size - 1)
        return 1;
    return 0;
}

int isEmpty(DEQueue *queue)
{
    if (queue->front == queue->rear)
        return 1;
    return 0;
}

int queue_front(DEQueue *queue)
{
    return queue->arr[queue->front + 1];
}

int queue_rear(DEQueue *queue)
{
    return queue->arr[queue->rear];
}

void enqueue_front (DEQueue *queue, int val)
{
    if (isEmpty(queue)) {
        queue->arr[++queue->rear] = val;
    }
    else if (queue->front!=-1) {
        queue->arr[queue->front--] = val;
    }

    else {
        printf("Queue overflow from front");
    }
}

void enqueue_rear (DEQueue *queue, int val)
{
    if (queue->rear!=queue->size-1) {
        queue->arr[++queue->rear] = val;
    }

    else {
        printf("Queue overflow from rear");
    }
}

int dequeue_front (DEQueue *queue)
{
    int checkVal_or_returnVal = -1;
    if (!isEmpty(queue))
    {
        checkVal_or_returnVal = queue->arr[++queue->front];
    }
    else
        printf("Queue underflow");

    return checkVal_or_returnVal;
}

int dequeue_rear (DEQueue *queue)
{
    int checkVal_or_returnVal = -1;
    if (!isEmpty(queue))
    {
        checkVal_or_returnVal = queue->arr[queue->rear--];
    }
    else
        printf("Queue underflow");

    return checkVal_or_returnVal;
}

int peek(DEQueue *queue, int peek_index){
    if (0 < peek_index && peek_index <= (queue->rear - queue->front))
    {
        return queue->arr[peek_index + queue->front];
    }
    return -1;
}

int main(){
    DEQueue* queue = (DEQueue*) malloc(sizeof(DEQueue));
    queue->front = queue->rear = -1;
    queue->size = 6;
    queue->arr = (int*) malloc(sizeof(int)*queue->size);

    enqueue_front(queue, 45);
    printf("front: %d, rear: %d", queue->front, queue->rear);
    enqueue_rear(queue, 59);
    printf("front: %d, rear: %d", queue->front, queue->rear);
    
    dequeue_front(queue);
    printf("front: %d, rear: %d", queue->front, queue->rear);
    
    enqueue_front(queue, 69);
    printf("front: %d, rear: %d", queue->front, queue->rear);
    
    dequeue_rear(queue);
    printf("front: %d, rear: %d\n", queue->front, queue->rear);

    int peekindex= 1;
    printf("The value at peekindex %d is %d", peekindex, peek(queue, peekindex));

    display(queue);

    free(queue->arr);
    free(queue);

    return 0;
}