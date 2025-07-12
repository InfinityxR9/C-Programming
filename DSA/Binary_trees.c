#include <stdio.h>
#include <stdlib.h>

/*
This file contains the declaration and definition of the Binary Trees Nodes and the Traversal methods As
1. In-Order Traversal
2. Pre-Order Traversal
3. Post-Order Traversal
*/

// Each Node of the Binary Tree
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

void post_order(Node *root)
{
    // static Node* ptr = root;
    if (root != NULL)
    {
        post_order(root->left_node);
        post_order(root->right_node);
        printf("%d ", root->data);
    }
}

void pre_order(Node *root)
{
    // static Node* ptr = root;
    if (root != NULL)
    {
        printf("%d ", root->data);
        pre_order(root->left_node);
        pre_order(root->right_node);
    }
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

    in_order(root);
    printf("\n");
    pre_order(root);
    printf("\n");
    post_order(root);

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