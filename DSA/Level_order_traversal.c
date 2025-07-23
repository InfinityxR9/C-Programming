#include <stdio.h>
#include <stdlib.h>

/*
Demonstrated Algorithm performs a level-order traversal of a given Binary Tree
LEVEL-ORDER TRAVERSAL: Print the data-nodes of the binary tree level wise
*/

// Each Node of the Binary Tree
typedef struct Node
{
    int data;
    struct Node *left_node;
    struct Node *right_node;
} Node;

typedef struct Queue_Arrays
{
    int front;
    int rear;
    Node **arr;
    int size;
} Queue;

int isFull(Queue *queue)
{
    if (queue->rear == queue->size - 1)
        return 1;
    return 0;
}

int isEmpty(Queue *queue)
{
    if (queue->front == queue->rear)
        return 1;
    return 0;
}

void enqueue(Queue *queue, Node *val)
{
    if (!isFull(queue))
        queue->arr[++queue->rear] = val;
    else
        printf("Queue overflow");
}

Node *dequeue(Queue *queue)
{
    Node *checkVal_or_returnVal = NULL;
    if (!isEmpty(queue))
    {
        checkVal_or_returnVal = queue->arr[++queue->front];
    }
    else
        printf("Queue underflow");

    return checkVal_or_returnVal;
}

Node *create_node(int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));

    ptr->left_node = ptr->right_node = NULL;
    ptr->data = data;

    return ptr;
}

void link_right(Node *root, Node *right_node)
{
    root->right_node = right_node;
}

void link_left(Node *root, Node *left_node)
{
    root->left_node = left_node;
}

void free_Nodes(Node *root)
{
    if (root != NULL)
    {
        free_Nodes(root->left_node);
        free_Nodes(root->right_node);
        free(root);
    }
}

void level_order(Node *root)
{
    Node *element;

    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->size = 500;
    queue->front = queue->rear = -1;
    queue->arr = (Node **)malloc(queue->size * sizeof(Node *));

    enqueue(queue, root);
    enqueue(queue, NULL);

    while (!isEmpty(queue))
    {
        element = dequeue(queue);
        if (element == NULL)
        {
            printf("\n");
            // enqueue(queue, NULL);
            continue;
        }

        printf("%d ", element->data);
        if (element->left_node != NULL)
            enqueue(queue, element->left_node);
        if (element->right_node != NULL)
            enqueue(queue, element->right_node);

        if (queue->arr[queue->front+1] == NULL  && (queue->rear - queue->front > 1))
        {
            enqueue(queue, NULL);
        }
    }

    // printf("Sucessfully completed level order traversal");

    free(queue->arr);
    free(queue);
}

int main()
{
    Node *root = create_node(6);
    Node *c1r = create_node(7);
    Node *c1l = create_node(4);
    Node *c2l = create_node(2);
    Node *c2r = create_node(11);
    Node *c3l = create_node(0);
    Node *c32r = create_node(5);
    Node *c12l = create_node(3);

    link_right(root, c1r);
    link_left(root, c1l);

    link_left(c1l, c2l);
    link_left(c1r, c12l);
    link_right(c1r, c2r);

    link_left(c2l, c3l);
    link_right(c2l, c32r);

    level_order(root);

    /*
    The Binary Tree Node Structure: (c === child)
                    6 (root)                    -- root level
                  /      \
           (c1l) 4        7 (c1r)               -- c1 level
               /         /  \
        (c2l) 2  (c12l) 3   11 (c2r)            -- c2 level
             / \
      (c2l) 0   5 (c32r)                        -- c3 level
    */

    free_Nodes(root);

    return 0;
}