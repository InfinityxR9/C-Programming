#include <stdio.h>
#include <stdlib.h>

/*
This file illustrates and demonstrates the algorithm for a Custom Sort using Rotations and Insertion in an AVL Tree and their in-order traversal
AVL Trees are self-balancing BINARY SEARCH TREES that maintain the perfectness and balancing of the BST at the time of insertion operation through Rotations.
Time Complexities of demonstrated Algorithm:
    The worst case time complexity is O(n log n)
    The average/best case time complexity is O(n log n)

Space Complexity: O(n)
In-place: No
Stable: No (Duplicates not allowed in the AVL/BS Trees)
Adaptive: No

DISCLAIMER: This Algorithm is not yet stable for handling Duplicate values as a BST/AVL Tree doesn't allow duplicates, If you feed duplicates, inconsistencies might appear.
*/

typedef struct Node
{
    int data;
    int height;
    struct Node *left_node;
    struct Node *right_node;
} Node;

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

void in_order(Node *root, int *arr, int *index)
{
    // static Node* ptr = root;
    if (root != NULL)
    {
        in_order(root->left_node, arr, index);
        arr[(*index)++] = root->data;
        in_order(root->right_node, arr, index);
    }
}

void custom_sort(int *arr, int size, int *id)
{
    Node *root = NULL;
    for (int i = 0; i < size; i++)
    {
        root = insert(root, arr[i]);
    }

    in_order(root, arr, id);
    free_Nodes(root);
}

void print_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {46, 82, 10, 8, 45, 76};
    int size = sizeof(arr) / sizeof(int);
    int id = 0;

    print_arr(arr, size);
    custom_sort(arr, size, &id);
    print_arr(arr, size);

    return 0;
}