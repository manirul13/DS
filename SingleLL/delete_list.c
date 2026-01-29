#include "sll.h"

int sl_delete_list(Slist **head)
{
	if (*head == NULL)
	{
	    return FAILURE;
	}
	
	Slist *temp;
	while (*head)
	{
	    temp = *head;
	    *head = (*head)->link;
	    
	    free(temp);
	}
	
	return SUCCESS;
}