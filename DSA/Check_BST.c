#include <stdio.h>
#include <stdlib.h>

/*
This file checks whether the given Binary Tree is a Binary Search Tree or not
Binary Search Tree (BST):
    1. All nodes in the left subtree of a node must have values less than the node's value.
    2. All nodes in the right subtree must have values greater than the node's value.
    3. No node element is repeated
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

int is_BST (Node*);

int is_BST_algo(Node *root, Node** prev)
{
    if (root != NULL) {
        if (!is_BST_algo(root->left_node, prev)) {
            // printf("inside !isbst root left node\n");
            return 0;
        }
        if (*prev != NULL && (*prev)->data >= root->data) {
            // printf("inside prev!= null && prev data..\n");
            return 0;
        }

        *prev = root;
        return is_BST_algo(root->right_node, prev);
    }
    return 1;
}

int is_BST (Node* root) {
    Node* prev = NULL;
    return is_BST_algo(root, &prev);
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
    Node *c1r = create_node(8); // 8
    Node *c1l = create_node(4);
    Node *c2l = create_node(2);
    Node *c2r = create_node(11);
    Node *c3l = create_node(0);
    Node *c32r = create_node(5);// 5
    Node *c12l = create_node(7); // 7

    link_right(root, c1r);
    link_left(root, c1l);

    link_left(c1l, c2l);
    link_left(c1r, c12l);
    link_right(c1r, c2r);

    link_left(c2l, c3l);
    link_right(c2l, c32r);

    printf("is bst: %d\n", is_BST(root));
    in_order(root);

    /*
    The Binary Tree Node Structure: (c === child)
                   (root)                     -- root level
                  /      \
              (c1l)       (c1r)               -- c1 level
               /         /    \
             (c2l)    (c12l)   (c2r)          -- c2 level
             /  \
         (c2l)  (c32r)                        -- c3 level
    */

    free_Nodes(root);

    return 0;
}