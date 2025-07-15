#include <stdio.h>
#include <stdlib.h>

/*
This file illustrates and demonstrates the algorithm for Rotations and Insertion in an AVL Tree.
AVL Trees are self-balancing BINARY SEARCH TREES that maintain the perfectness and balancing of the BST at the time of insertion operation through Rotations.
There are 4 Types of Rotations:
    RR  (Right Right)
    LL  (Left Left)
    RL  (Right Left)
    LR  (Left Right)

Time Complexities of demonstrated Algorithm:
    The in-general time complexity is O(h) where h is the height of the BST
    The worst case time complexity is O(log n)
    The average/best case time complexity is O(log n)
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
        return NULL;

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

Node *search(Node *root, int key)
{
    Node *ptr = root;
    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            return ptr;
        }

        else if (ptr->data < key)
        {
            ptr = ptr->right_node;
        }

        else
        {
            ptr = ptr->left_node;
        }
    }

    return ptr;
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

int main()
{
    Node *root = create_node(11);
    printf("%d\n", root->data);
    root = insert(root, 13);
    printf("%d\n", root->data);
    root = insert(root, 15);
    printf("%d\n", root->data);
    in_order(root);
    printf("\n");
    root = insert(root, 12);
    printf("%d\n", root->data);
    root = insert(root, 14);
    printf("%d\n", root->data);
    root = insert(root, 8);
    printf("%d\n", root->data);
    in_order(root);
    printf("\n");
    root = insert(root, 9);
    printf("%d\n", root->data);
    root = insert(root, 10);
    printf("%d\n", root->data);
    root = insert(root, 0);
    printf("%d\n", root->data);
    in_order(root);

    free_Nodes(root);

    return 0;
}