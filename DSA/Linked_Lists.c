#include <stdio.h>
#include <stdlib.h>

// The Linked Lists illustrated and programmed in this .c file can be used to create manipulation functions for a circular and doubly linked lists in the same manner

typedef struct Linked_List
{
    int data;
    struct Linked_List *next;
} Linked_List;

void Display(Linked_List *head)
{
    while (head != NULL)
    {
        head = head->next;
        printf("%d ", head->data);
    };
}

Linked_List *Get_Node_By_index(Linked_List *head, int index)
{
    int loops = 0;
    while (loops < index)
    {
        if (head->next != NULL)
        {
            head = head->next;
            loops++;
        }
        else
            break;
    }

    return head;
}

int Get_Index_By_Value(Linked_List *head, int value)
{
    int index = 0;
    while (head->data != value)
    {
        if (head->next != NULL)
        {
            head = head->next;
            index++;
        }
        else
            break;
    }

    if (head->data == value)
    {
        return index;
    }
    else
        return -1;
}

void insert_start(Linked_List **head_ref, int value)
{
    Linked_List *New = (Linked_List *)malloc(sizeof(Linked_List));
    New->data = value;
    New->next = *head_ref;
    *head_ref = New;
}

void insert_middle(Linked_List *head, int index, int value)
{
    Linked_List *New = (Linked_List *)malloc(sizeof(Linked_List));
    New->data = value;
    New->next = Get_Node_By_index(head, index);
    Get_Node_By_index(head, index - 1)->next = New;
}

void insert_end(Linked_List *head, int value)
{
    Linked_List *New = (Linked_List *)malloc(sizeof(Linked_List));
    New->data = value;
    New->next = NULL;

    while (head->next != NULL)
    {
        head = head->next;
    }
    // printf("\n%d", Node->next);
    head->next = New;
}

void delete_head(Linked_List **head_ref)
{
    Linked_List *old_head = *head_ref;
    *head_ref = (*head_ref)->next;
    free(old_head);
}

void delete_middle(Linked_List *head, int index)
{
    Linked_List *deleting_Node = Get_Node_By_index(head, index);
    Linked_List *previous_Node = Get_Node_By_index(head, index - 1);

    previous_Node->next = deleting_Node->next;
    free(deleting_Node);
}

void delete_end(Linked_List *head)
{
    while ((head->next)->next != NULL)
    {
        head = head->next;
    }
    // printf("\n%d", Node->next);
    free(head->next);
    head->next = NULL;
}

void free_Nodes(Linked_List **head_ref)
{
    Linked_List *temp;
    Linked_List *head = *head_ref;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    *head_ref = NULL;
}

int main()
{
    Linked_List *head = (Linked_List *)malloc(sizeof(Linked_List));
    head->data = 1;
    head->next = NULL;

    Display(head);
    printf("\n");
    insert_end(head, 2);
    insert_end(head, 3);
    insert_end(head, 4);
    insert_end(head, 5);
    insert_middle(head, 3, 96);
    Display(head);

    insert_start(&head, 9);
    printf("This is the linked list after insert at start and changed head position\n");
    Display(head);
    printf("\nThe value of the head is %d", head->data);

    delete_head(&head);
    printf("\nThe linked list after deleting the head is\n");
    Display(head);
    printf("\nThe value of the head is %d", head->data);

    delete_middle(head, 3);
    printf("\nThe linked list after deleting the 3 index value\n");
    Display(head);

    printf("\nThe linked list after deleting the last value\n");
    delete_end(head);
    Display(head);

    printf("\nThe next value of last element is %d", Get_Node_By_index(head, 3)->next);

    int index = Get_Index_By_Value(head, 3);
    printf("\nThe index of the node is %d\n", index);

    Display(head);
    printf("\nThe value at index 5 is %d", Get_Node_By_index(head, 5)->data);

    free_Nodes(&head);

    return 0;
}