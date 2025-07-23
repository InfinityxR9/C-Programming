#include <stdio.h>
#include <stdlib.h>

/*
An AVL Tree will be constructed (To create a clean and sober Binary Search Tree) and then the Invert Opertion will be performed, retaining the supreme root.

In the invert operation, We swap the Left and right child nodes of the root of each sub-array. The resulted tree will be a mirror image of the original tree in structural organisation.

The same operation can be performed in the Binary Tree and Binary Search Trees also.
This file illustrates and demonstrates both the Iterative and Recursive approach for the problem.

In-order traversal is reversed and Level-order traversal is mirrored

Time Complexity: O(n)
Space Complexity: O(h) (For balanced BST/AVL, h = lg n)
*/

typedef struct Node
{
    int data;
    int height;
    struct Node *left_node;
    struct Node *right_node;
} Node;

typedef struct Stack_Arrays
{
    int top;
    int size;
    Node **arr;
} Stack;

typedef struct Queue_Arrays
{
    int front;
    int rear;
    Node **arr;
    int size;
} Queue;

int is_Full(Queue *queue)
{
    if (queue->rear == queue->size - 1)
        return 1;
    return 0;
}

int is_Empty(Queue *queue)
{
    if (queue->front == queue->rear)
        return 1;
    return 0;
}

void enqueue(Queue *queue, Node *val)
{
    if (!is_Full(queue))
        queue->arr[++queue->rear] = val;
    else
        printf("Queue overflow");
}

Node *dequeue(Queue *queue)
{
    Node *checkVal_or_returnVal = NULL;
    if (!is_Empty(queue))
    {
        checkVal_or_returnVal = queue->arr[++queue->front];
    }
    else
        printf("Queue underflow");

    return checkVal_or_returnVal;
}

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

void push(Stack *stack, Node *value)
{
    if (!isFull(stack))
        stack->arr[++stack->top] = value;

    else
    {
        printf("Stack Overflow");
    }
}

Node *pop(Stack *stack)
{
    if (!isEmpty(stack))
    {
        Node *val = stack->arr[stack->top];
        stack->top--;
        return val;
    }

    printf("Stack Underflow");
}

Node *stackTop(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->arr[stack->top];
}

Node *stackBottom(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->arr[0];
}

Node *create_node(int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));

    ptr->left_node = ptr->right_node = NULL;
    ptr->data = data;
    ptr->height = 1;

    return ptr;
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

int max(int a, int b)
{
    return a > b ? a : b;
}

int get_height(Node *root)
{
    return root == NULL ? 0 : root->height;
}

int get_balance_factor(Node *root)
{
    return root == NULL ? 0 : get_height(root->left_node) - get_height(root->right_node);
}

Node *left_rotation_return_root(Node *root)
{
    if (root == NULL)
        return NULL;

    Node *new_root = root->right_node;
    Node *transfer_node = new_root->left_node;

    root->right_node = transfer_node;
    new_root->left_node = root;

    root->height = max(get_height(root->left_node), get_height(root->right_node)) + 1;
    new_root->height = max(get_height(new_root->left_node), get_height(new_root->right_node)) + 1;

    return new_root;
}

Node *right_rotation_return_root(Node *root)
{
    if (root == NULL)
        return NULL;

    Node *new_root = root->left_node;
    Node *transfer_node = new_root->right_node;

    root->left_node = transfer_node;
    new_root->right_node = root;

    root->height = max(get_height(root->left_node), get_height(root->right_node)) + 1;
    new_root->height = max(get_height(new_root->left_node), get_height(new_root->right_node)) + 1;

    return new_root;
}

Node *insert(Node *root, int key)
{
    if (root == NULL)
        return (create_node(key));
    if (root->data > key)
        root->left_node = insert(root->left_node, key);
    else if (root->data < key)
        root->right_node = insert(root->right_node, key);
    else
        return root;

    root->height = max(get_height(root->left_node), get_height(root->right_node)) + 1;

    int balance_factor = get_balance_factor(root);

    // RR Rotation
    if (balance_factor < -1 && root->right_node->data < key)
    {
        return left_rotation_return_root(root);
    }
    // LL Rotation
    if (balance_factor > 1 && root->left_node->data > key)
    {
        return right_rotation_return_root(root);
    }
    // RL Rotation
    if (balance_factor < -1 && root->right_node->data > key)
    {
        root->right_node = left_rotation_return_root(root->right_node);
        return right_rotation_return_root(root);
    }
    // LR Rotation
    if (balance_factor > 1 && root->left_node->data < key)
    {
        root->left_node = right_rotation_return_root(root->left_node);
        return left_rotation_return_root(root);
    }

    // Return the modified Root
    return root;
}

int get_total_nodes(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + get_total_nodes(root->left_node) + get_total_nodes(root->right_node);
}

void level_order(Node *root)
{
    Node *element;

    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->size = get_total_nodes(root)*2;
    queue->front = queue->rear = -1;
    queue->arr = (Node **)malloc(queue->size * sizeof(Node *));

    enqueue(queue, root);
    enqueue(queue, NULL);

    while (!is_Empty(queue))
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

        if (queue->arr[queue->front + 1] == NULL && (queue->rear - queue->front > 1))
        {
            enqueue(queue, NULL);
        }
    }

    // printf("Sucessfully completed level order traversal");

    free(queue->arr);
    free(queue);
}

void in_order(Node *root)
{
    // static Node* ptr = root;
    if (root != NULL)
    {
        in_order(root->left_node);
        printf("%d ", root->data);
        in_order(root->right_node);
    }
}

Node *invert(Node *root)
{
    if (root == NULL)
        return NULL;

    Node *temp = root->left_node;
    root->left_node = root->right_node;
    root->right_node = temp;

    invert(root->left_node);
    invert(root->right_node);

    return root;
}

// Iterative Approach for inversion using an explicit Stack
Node *invert_iterative(Node *root)
{
    if (root == NULL)
        return NULL;

    Node *ptr = root;
    Node *temp;

    // We will create a stack to keep track of the nodes whose left and right children are to be swapped
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->size = get_total_nodes(root); // Worse case scenario
    stack->arr = (Node **)malloc(stack->size * sizeof(Node *));

    push(stack, ptr);

    Node *top_element;

    while (!isEmpty(stack))
    {
        top_element = pop(stack);

        temp = top_element->left_node;
        top_element->left_node = top_element->right_node;
        top_element->right_node = temp;

        if (top_element->left_node != NULL)
            push(stack, top_element->left_node);
        if (top_element->right_node != NULL)
            push(stack, top_element->right_node);
    }

    free(stack->arr);
    free(stack);

    return ptr;
}

int main()
{
    Node *root = create_node(11);
    root = insert(root, 13);
    root = insert(root, 15);
    root = insert(root, 12);
    root = insert(root, 14);
    root = insert(root, 8);
    root = insert(root, 9);
    root = insert(root, 10);
    root = insert(root, 0);

    level_order(root);
    // root = invert(root);
    root = invert_iterative(root);
    printf("\n");
    level_order(root);

    free_Nodes(root);

    return 0;
}