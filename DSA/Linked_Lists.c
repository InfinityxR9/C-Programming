#include <stdio.h>
#include <stdlib.h>

typedef struct Linked_List{
    int data;
    struct Linked_List* next;
} Linked_List;

void Display(Linked_List* head){
    printf("%d ", head->data);
    while (head->next != NULL) {
        head = head->next;
        printf("%d ", head->data);
    };
}

Linked_List* Get_Node_By_index(Linked_List* head, int index){
    int loops = 0;
    while (loops < index){
        if (head->next !=NULL){
            head = head->next;
            loops++;
        }
        else break;
    }

    return head;
}

void insert_middle(Linked_List* head, int index, int value){
    Linked_List* New = (Linked_List*) malloc(sizeof(Linked_List));
    New->data = value;    
    New->next = Get_Node_By_index(head, index);
    Get_Node_By_index(head, index-1)->next = New;
}

void insert_end(Linked_List* head, int value){
    Linked_List* New = (Linked_List*) malloc(sizeof(Linked_List));
    New->data = value;
    New->next = NULL;

    while(head->next !=NULL){
        head = head->next;
    }
    // printf("\n%d", Node->next);
    head->next = New;
}

void free_Nodes(Linked_List** head_ref){
    Linked_List* temp;
    Linked_List* head = *head_ref;
    while(head!=NULL){
        temp = head;
        head = head->next;
        free(temp);
    }

    *head_ref = NULL;
}

int main(){ 
    Linked_List* head = (Linked_List*) malloc(sizeof(Linked_List));
    head->data = 59;
    head->next = NULL;

    Display(head);
    printf("\n");
    insert_end(head, 699);
    insert_end(head, 59);
    insert_end(head, 6);
    insert_end(head, 96);
    insert_middle(head, 3, 96);
    Display(head);

    free_Nodes(&head);

printf("This is the Linked_List.c file");

    return 0;
}