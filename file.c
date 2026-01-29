#include <stdio.h>
#include <stdlib.h>

/** Definition for singly-linked list.*/
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode *curr = &dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;

        int sum = x + y + carry;
        carry = sum / 10;

        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;

        curr->next = node;
        curr = curr->next;

        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    }

    return dummy.next;
}

struct ListNode *createNode(int val){
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* insertEnd(struct ListNode* head , int val){
    struct ListNode* node = createNode(val);

    if(head == NULL){
        return node;
    }
    struct ListNode* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = node;
    return head;
}

void printList(struct ListNode* head){
    while(head != NULL){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
 void freeList(struct ListNode* head){
    while(head != NULL){
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
 }
int main()
{
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;

    l1 = insertEnd(l1, 2);  
    l1 = insertEnd(l1, 4);  
    l1 = insertEnd(l1, 3);  

    l2 = insertEnd(l2, 5);
    l2 = insertEnd(l2, 6);
    l2 = insertEnd(l2, 4);

    printf("List 1: ");
    printList(l1);
    
    printf("List 2: ");
    printList(l2);

    struct ListNode* result = addTwoNumbers(l1, l2);

    printf("Result: ");
    printList(result);


    freeList(l1);
    freeList(l2);
    return 0;
}