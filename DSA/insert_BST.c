#include <stdio.h>
#include <stdlib.h>

/*
This file illustrates and demonstrates the algorithm for iteratevily inserting a key (data node) in a Binary Search Tree.
    The in-general time complexity is O(h) where h is the height of the BST
    The worst case time complexity is O(n)
    The average/best case time complexity is O(log n)
*/

typedef struct Node
{
    int data;
    struct Node *left_node;
    struct Node *right_node;
} Node;

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

Node *insert(Node *root, int key)
{
    Node *ptr = NULL;
    Node *curr_node = root;

    while (curr_node != NULL)
    {
        if (curr_node->data == key)
        {
            return NULL;
        }

        else if (curr_node->data > key)
        {
            ptr = curr_node;
            curr_node = curr_node->left_node;
        }

        else
        {
            ptr = curr_node;
            curr_node = curr_node->right_node;
        }
    }

    Node *new = create_node(key);
    if (ptr == NULL)
        return new;
    if (ptr->data > key)
    {
        ptr->left_node = new;
    }
    else
    {
        ptr->right_node = new;
    }

    return new;
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
    Node *root = create_node(6);
    insert(root, 8);
    insert(root, 5);
    insert(root, 2);
    insert(root, 11);
    insert(root, 0);
    insert(root, 4);
    insert(root, 7);

    in_order(root);
    int key = 1;

    /*     if (insert(root, key) != NULL)
        {
            printf("\nThe key %d is inserted (iterative): %d\n", key, insert(root, key)->data);
        }
        else
        {
            printf("\nThe key %d was already present in the BST (iterative)\n", key);
        } */

    insert(root, key);
    printf("\n");

    in_order(root);

    free_Nodes(root);

    return 0;
}