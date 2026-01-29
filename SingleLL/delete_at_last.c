#include "sll.h"

int sl_delete_last(Slist **head)
{
    if (*head == NULL)
    {
        return FAILURE;
    }
    
    if ((*head)->link == NULL)
    {
        free(*head);
        *head = NULL;
        return SUCCESS;
    }
    
    Slist *temp = *head;
    while (temp->link->link != NULL)
    {
        temp = temp->link;
    }
    
    free(temp->link);
    temp->link = NULL;
    
    return SUCCESS;
}