#include "sll.h"

int find_node(Slist *head, data_t data)
{
    if (head == NULL)
    {
        return FAILURE;
    }
    
    int pos = 1;
    
    while (head)
    {
        if (head->data == data)
        {
            return pos;
        }
        head = head->link;
        pos++;
    }
    return FAILURE;
}