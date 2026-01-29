/*****************************************************
 * Singly Linked List – Complete Program (One File)
 * Author : You 😄
 * Purpose: Understand FULL FLOW of SLL step by step
 *****************************************************/

#include <stdio.h>   // For printf, scanf
#include <stdlib.h>  // For malloc, free

/*----------------------------------------------------
 Macros for return status
----------------------------------------------------*/
#define SUCCESS 0
#define FAILURE -1

/*----------------------------------------------------
 Data type alias
 If later you want float / struct, change only here
----------------------------------------------------*/
typedef int data_t;

/*----------------------------------------------------
 Definition of Singly Linked List Node
----------------------------------------------------*/
typedef struct node
{
    data_t data;        // Stores the actual value
    struct node *link;  // Pointer to the next node
} Slist;

/*----------------------------------------------------
 Function Declarations
----------------------------------------------------*/
int insert_at_first(Slist **head, data_t data);
int insert_at_last(Slist **head, data_t data);
int sl_delete_first(Slist **head);
int sl_delete_last(Slist **head);
int sl_delete_list(Slist **head);
int find_node(Slist *head, data_t key);
void print_list(Slist *head);

/*----------------------------------------------------
 MAIN FUNCTION – Program starts here
----------------------------------------------------*/
int main()
{
    int option, data, key, pos;

    /*------------------------------------------------
     Head pointer initialization
     NULL means: list is EMPTY
    ------------------------------------------------*/
    Slist *head = NULL;

    printf("\n--- Singly Linked List Menu ---\n");
    printf("1. Insert at last\n");
    printf("2. Insert at first\n");
    printf("3. Delete last\n");
    printf("4. Delete first\n");
    printf("5. Delete entire list\n");
    printf("6. Find a node\n");
    printf("7. Print list\n");
    printf("8. Exit\n");

    /*------------------------------------------------
     Infinite loop to keep program running
    ------------------------------------------------*/
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
            /*----------------------------------------
             Insert node at LAST
            ----------------------------------------*/
            case 1:
                printf("Enter data to insert at last: ");
                scanf("%d", &data);

                // Pass address of head (double pointer)
                if (insert_at_last(&head, data) == FAILURE)
                {
                    printf("INFO: Insertion failed\n");
                }
                break;

            /*----------------------------------------
             Insert node at FIRST
            ----------------------------------------*/
            case 2:
                printf("Enter data to insert at first: ");
                scanf("%d", &data);

                if (insert_at_first(&head, data) == FAILURE)
                {
                    printf("INFO: Insertion failed\n");
                }
                break;

            /*----------------------------------------
             Delete LAST node
            ----------------------------------------*/
            case 3:
                if (sl_delete_last(&head) == FAILURE)
                {
                    printf("INFO: List is empty\n");
                }
                else
                {
                    printf("INFO: Last node deleted\n");
                }
                break;

            /*----------------------------------------
             Delete FIRST node
            ----------------------------------------*/
            case 4:
                if (sl_delete_first(&head) == FAILURE)
                {
                    printf("INFO: List is empty\n");
                }
                else
                {
                    printf("INFO: First node deleted\n");
                }
                break;

            /*----------------------------------------
             Delete ENTIRE list
            ----------------------------------------*/
            case 5:
                if (sl_delete_list(&head) == FAILURE)
                {
                    printf("INFO: List is already empty\n");
                }
                else
                {
                    printf("INFO: Entire list deleted\n");
                }
                break;

            /*----------------------------------------
             Find a node
            ----------------------------------------*/
            case 6:
                printf("Enter key to search: ");
                scanf("%d", &key);

                pos = find_node(head, key);
                if (pos == FAILURE)
                {
                    printf("INFO: Key not found\n");
                }
                else
                {
                    printf("INFO: %d found at position %d\n", key, pos);
                }
                break;

            /*----------------------------------------
             Print the list
            ----------------------------------------*/
            case 7:
                print_list(head);
                break;

            /*----------------------------------------
             Exit program
            ----------------------------------------*/
            case 8:
                return SUCCESS;

            default:
                printf("Enter a valid option!\n");
        }
    }
}

/*====================================================
 Insert node at FIRST position
====================================================*/
int insert_at_first(Slist **head, data_t data)
{
    // Allocate memory for new node
    Slist *new = malloc(sizeof(Slist));

    // Check allocation failure
    if (new == NULL)
        return FAILURE;

    // Assign data
    new->data = data;

    // New node points to current head
    new->link = *head;

    // Head updated to new node
    *head = new;

    return SUCCESS;
}

/*====================================================
 Insert node at LAST position
====================================================*/
int insert_at_last(Slist **head, data_t data)
{
    Slist *new = malloc(sizeof(Slist));

    if (new == NULL)
        return FAILURE;

    new->data = data;
    new->link = NULL;  // Last node always points to NULL

    // If list is empty
    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    // Traverse till last node
    Slist *temp = *head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    // Attach new node at end
    temp->link = new;

    return SUCCESS;
}

/*====================================================
 Delete FIRST node
====================================================*/
int sl_delete_first(Slist **head)
{
    // Empty list check
    if (*head == NULL)
        return FAILURE;

    // Store current head
    Slist *temp = *head;

    // Move head to next node
    *head = (*head)->link;

    // Free old head
    free(temp);

    return SUCCESS;
}

/*====================================================
 Delete LAST node
====================================================*/
int sl_delete_last(Slist **head)
{
    // Empty list
    if (*head == NULL)
        return FAILURE;

    // Only one node
    if ((*head)->link == NULL)
    {
        free(*head);
        *head = NULL;
        return SUCCESS;
    }

    // Traverse till second last node
    Slist *temp = *head;
    while (temp->link->link != NULL)
    {
        temp = temp->link;
    }

    // Free last node
    free(temp->link);
    temp->link = NULL;

    return SUCCESS;
}

/*====================================================
 Delete ENTIRE list
====================================================*/
int sl_delete_list(Slist **head)
{
    if (*head == NULL)
        return FAILURE;

    Slist *temp;

    // Delete nodes one by one from beginning
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->link;
        free(temp);
    }

    return SUCCESS;
}

/*====================================================
 Find a node in list
 Returns position (1-based)
====================================================*/
int find_node(Slist *head, data_t key)
{
    int pos = 1;

    // Traverse list
    while (head != NULL)
    {
        if (head->data == key)
            return pos;

        head = head->link;
        pos++;
    }

    return FAILURE;
}

/*====================================================
 Print the entire list
====================================================*/
void print_list(Slist *head)
{
    if (head == NULL)
    {
        printf("INFO: List is empty\n");
        return;
    }

    // Traverse and print
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->link;
    }

    printf("NULL\n");
}
