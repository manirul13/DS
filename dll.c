/********************************************************
 * Doubly Linked List – Complete Program (One File)
 * Purpose : Understand FULL FLOW of DLL step by step
 ********************************************************/

#include <stdio.h>   // printf, scanf
#include <stdlib.h>  // malloc, free

/*-------------------------------------------------------
 Macros for return status
-------------------------------------------------------*/
#define SUCCESS 0
#define FAILURE -1

/*-------------------------------------------------------
 Data type stored in the list
-------------------------------------------------------*/
typedef int data_t;

/*-------------------------------------------------------
 Definition of Doubly Linked List Node
-------------------------------------------------------*/
typedef struct node
{
    data_t data;          // Stores actual data
    struct node *prev;    // Pointer to previous node
    struct node *next;    // Pointer to next node
} Dlist;

/*-------------------------------------------------------
 Function Declarations
-------------------------------------------------------*/
int insert_at_first(Dlist **head, data_t data);
int insert_at_last(Dlist **head, data_t data);
int dl_delete_first(Dlist **head);
int dl_delete_last(Dlist **head);
int dl_delete_list(Dlist **head);
int find_node(Dlist *head, data_t key);
void print_list_forward(Dlist *head);
void print_list_reverse(Dlist *head);

/*-------------------------------------------------------
MAIN FUNCTION
-------------------------------------------------------*/
int main()
{
    int option, data, key, pos;

    /*---------------------------------------------------
    Head pointer initialization
    NULL means DLL is empty
    ---------------------------------------------------*/
    Dlist *head = NULL;

    printf("\n--- Doubly Linked List Menu ---\n");
    printf("1. Insert at last\n");
    printf("2. Insert at first\n");
    printf("3. Delete last\n");
    printf("4. Delete first\n");
    printf("5. Delete entire list\n");
    printf("6. Find a node\n");
    printf("7. Print list (Forward)\n");
    printf("8. Print list (Reverse)\n");
    printf("9. Exit\n");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                printf("Enter data to insert at last: ");
                scanf("%d", &data);
                insert_at_last(&head, data);
                break;

            case 2:
                printf("Enter data to insert at first: ");
                scanf("%d", &data);
                insert_at_first(&head, data);
                break;

            case 3:
                if (dl_delete_last(&head) == FAILURE)
                    printf("INFO: List is empty\n");
                else
                    printf("INFO: Last node deleted\n");
                break;

            case 4:
                if (dl_delete_first(&head) == FAILURE)
                    printf("INFO: List is empty\n");
                else
                    printf("INFO: First node deleted\n");
                break;

            case 5:
                if (dl_delete_list(&head) == FAILURE)
                    printf("INFO: List already empty\n");
                else
                    printf("INFO: Entire list deleted\n");
                break;

            case 6:
                printf("Enter key to search: ");
                scanf("%d", &key);
                pos = find_node(head, key);
                if (pos == FAILURE)
                    printf("INFO: Key not found\n");
                else
                    printf("INFO: %d found at position %d\n", key, pos);
                break;

            case 7:
                print_list_forward(head);
                break;

            case 8:
                print_list_reverse(head);
                break;

            case 9:
                return SUCCESS;

            default:
                printf("Enter a valid option!\n");
        }
    }
}

/*======================================================
 Insert node at FIRST position
======================================================*/
int insert_at_first(Dlist **head, data_t data)
{
    // Allocate memory for new node
    Dlist *new = malloc(sizeof(Dlist));
    if (!new)
        return FAILURE;

    // Assign data
    new->data = data;

    // New node's prev is NULL (it becomes first node)
    new->prev = NULL;

    // New node points to old head
    new->next = *head;

    // If list was not empty, update old head's prev
    if (*head != NULL)
        (*head)->prev = new;

    // Update head to new node
    *head = new;

    return SUCCESS;
}

/*======================================================
 Insert node at LAST position
======================================================*/
int insert_at_last(Dlist **head, data_t data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if (!new)
        return FAILURE;

    new->data = data;
    new->next = NULL;   // Last node always points to NULL

    // If list is empty
    if (*head == NULL)
    {
        new->prev = NULL;
        *head = new;
        return SUCCESS;
    }

    // Traverse till last node
    Dlist *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    // Link new node
    temp->next = new;
    new->prev = temp;

    return SUCCESS;
}

/*======================================================
 Delete FIRST node
======================================================*/
int dl_delete_first(Dlist **head)
{
    if (*head == NULL)
        return FAILURE;

    // Store current head
    Dlist *temp = *head;

    // Move head to next node
    *head = temp->next;

    // If list not empty after deletion
    if (*head != NULL)
        (*head)->prev = NULL;

    // Free old head
    free(temp);

    return SUCCESS;
}

/*======================================================
 Delete LAST node
======================================================*/
int dl_delete_last(Dlist **head)
{
    if (*head == NULL)
        return FAILURE;

    // If only one node exists
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return SUCCESS;
    }

    // Traverse till last node
    Dlist *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    // Detach last node
    temp->prev->next = NULL;
    free(temp);

    return SUCCESS;
}

/*======================================================
 Delete ENTIRE list
======================================================*/
int dl_delete_list(Dlist **head)
{
    if (*head == NULL)
        return FAILURE;

    Dlist *temp;

    // Delete nodes one by one
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    return SUCCESS;
}

/*======================================================
 Find a node (1-based position)
======================================================*/
int find_node(Dlist *head, data_t key)
{
    int pos = 1;

    while (head != NULL)
    {
        if (head->data == key)
            return pos;

        head = head->next;
        pos++;
    }
    return FAILURE;
}

/*======================================================
 Print list in FORWARD direction
======================================================*/
void print_list_forward(Dlist *head)
{
    if (head == NULL)
    {
        printf("INFO: List is empty\n");
        return;
    }

    // Traverse forward
    printf("NULL <-> ");
    while (head != NULL)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/*======================================================
 Print list in REVERSE direction
======================================================*/
void print_list_reverse(Dlist *head)
{
    if (head == NULL)
    {
        printf("INFO: List is empty\n");
        return;
    }

    // Move to last node
    while (head->next != NULL)
        head = head->next;

    printf("NULL <-> ");
    while (head != NULL)
    {
        printf("%d <-> ", head->data);
        head = head->prev;
    }
    printf("NULL\n");
}
