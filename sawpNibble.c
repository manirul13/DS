#include <stdio.h>
#include <stdlib.h>

/* Definition for singly-linked list */
struct ListNode {
    int val;
    struct ListNode *next;
};

/* Function to swap nodes in pairs */
struct ListNode* swapPairs(struct ListNode* head) {

    // Create temporary node to handle head swap easily
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = 0;
    temp->next = head;

    // prev always points to node before the pair
    struct ListNode* prev = temp;

    // Continue while there are at least two nodes to swap
    while (prev->next != NULL && prev->next->next != NULL) {

        // First node of the pair
        struct ListNode* a = prev->next;

        // Second node of the pair
        struct ListNode* b = a->next;

        // Swapping the pair
        a->next = b->next;
        b->next = a;
        prev->next = b;

        // Move prev to the end of the swapped pair
        prev = a;
    }

    // New head after swaps
    struct ListNode* newHead = temp->next;

    // Free dummy node
    free(temp);

    return newHead;
}

/* Helper function to create a new node */
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

/* Helper function to print linked list */
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

/* Main function */
int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);

    printf("Original list:\n");
    printList(head);

    // Swap nodes in pairs
    head = swapPairs(head);

    printf("After swapping pairs:\n");
    printList(head);

    return 0;
}
