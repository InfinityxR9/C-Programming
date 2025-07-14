#include <stdio.h>
#include <stdlib.h>

/*
This file illustrates and demonstrates the algorithm for deleting a key (data node) in a Binary Search Tree.
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

Node *get_inorder_pre(Node *root)
{
    if (root == NULL)
        return NULL;

    root = root->left_node;
    while (root->right_node != NULL)
    {
        root = root->right_node;
    }

    return root;
}

Node *delete(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    // Search for the element
    if (root->data > key)
    {
        root->left_node = delete(root->left_node, key);
    }
    else if (root->data < key)
    {
        root->right_node = delete(root->right_node, key);
    }
    else
    {
        if (root->left_node == NULL && root->right_node == NULL)
        {
            free(root);
            return NULL;
        }

        Node *inorder_pre = get_inorder_pre(root);

        root->data = inorder_pre->data;
        root->left_node = delete(root->left_node, inorder_pre->data);
    }

    return root;
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

    insert(root, key);
    printf("\n");

    in_order(root);
    int key2 = 7;
    if (search(root, key2) == NULL)
        printf("\nElement not in the tree\n");
    else
    {

        Node *return_val = delete(root, key2);
        // printf("%d", return_val->data);

        if (return_val->data == key2)
            printf("Element not found (null returned)\n");
        else
        {
            printf("\n");
            in_order(root);
        }
    }

    free_Nodes(root);

    return 0;
}