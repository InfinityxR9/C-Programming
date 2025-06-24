#include <stdio.h>
#include <stdlib.h>

// This will be a by default circular Queue for better space management

typedef struct Queue_Arrays {
    int front;
    int rear;
    int* arr;
    int size;
} Queue;

void Display(Queue* queue){
    for (int i = queue->front+1; i <= queue->rear; i++)
    {
        printf("%d ", queue->arr[i]);
    }
}

int main(){
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->size = 7;
    queue->front = queue->rear = 0;
    queue->arr = (int*) malloc(queue->size*sizeof(int));

    Display(queue);

    free(queue->arr);
    free(queue);

    return 0;
}