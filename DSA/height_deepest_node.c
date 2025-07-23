#include <stdio.h>
#include <stdlib.h>

/*
To find the height of the deepest node of a subtree with given root
Time Complexity: O(n)
Space Complxity: O(h) (In best case, h = lg n; In worse case, h = n)
*/

// Node of the Binary Tree
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
    // Height refers to the height of the deepest Leaf Node in a subtree with given root node

    if (root == NULL)
        return -1;

    int height_right_subtree = get_height(root->right_node);
    int height_left_subtree = get_height(root->left_node);

    return 1 + max(height_right_subtree, height_left_subtree);
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

    printf("The height of the root is %d\n", get_height(root));
    printf("The height of the root->right_node is %d\n", get_height(root->right_node));
    printf("The height of the root->left_node is %d\n", get_height(root->left_node));
    printf("The height of the root->left_node->left_node is %d\n", get_height(root->left_node->left_node));
    printf("The height of the root->left_node->right_node is %d\n", get_height(root->left_node->right_node));
    printf("The height of the root->right_node->right_node is %d\n", get_height(root->right_node->right_node));
    printf("The height of the root->right_node->left_node->left_node is %d\n", get_height(root->right_node->left_node->left_node));

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