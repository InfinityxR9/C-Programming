#include <stdio.h>
#include <stdlib.h>

/*
This file illustrates and demonstrates the algorithm for recursively and iteratevily searching a key (data node) in a Binary Search Tree.
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

Node* search_recur (Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == key) {
        return root;
    }

    else if (root->data > key) {
        return search_recur(root->left_node, key);
    }
    else {
        return search_recur(root->right_node, key);
    }
}

Node* search_iter (Node* root, int key) {
    Node* ptr = root;
    while (ptr != NULL){
        if (ptr->data == key) {
            return ptr;
        }

        else if (ptr->data < key) {
            ptr = ptr->right_node;
        }

        else {
            ptr = ptr->left_node;
        }
    }
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
    Node *c1l = create_node(5);
    Node *c2l = create_node(2);
    Node *c2r = create_node(11);
    Node *c3l = create_node(0);
    Node *c32r = create_node(4);// 5
    Node *c12l = create_node(7); // 7

    link_right(root, c1r);
    link_left(root, c1l);

    link_left(c1l, c2l);
    link_left(c1r, c12l);
    link_right(c1r, c2r);

    link_left(c2l, c3l);
    link_right(c2l, c32r);

    in_order(root);
    int key = 5;

    if (search_recur(root, key) != NULL) {
        printf("\nThe key %d is found (recursive): %d\n", key, search_recur(root, key)->data);
    }
    else {
        printf("\nThe key %d was not found in the BST (recursive)\n", key);
    }

    if (search_iter(root, key) != NULL) {
        printf("\nThe key %d is found (iterative): %d\n", key, search_iter(root, key)->data);
    }
    else {
        printf("\nThe key %d was not found in the BST (iterative)\n", key);
    }

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