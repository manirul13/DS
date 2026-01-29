#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int roll;
    char name[50];
    float marks;
    struct student *next;
};

struct student* createNode(int roll, char name[], float marks){
    struct student *newNode = (struct student*)malloc(sizeof(struct student));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }

    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->marks = marks;
    newNode->next = NULL;

    return newNode;
}

void insertFirst(struct student **head, int roll, char name[], float marks){
    struct student *newNode = createNode(roll, name, marks);
    if(newNode == NULL){
        printf("memory allocation failed\n");
        return;
    }

    newNode->next = *head;
    *head = newNode;
}

void insertEnd(struct student **head, int roll, char name[], float marks){
    struct student *newNode = createNode(roll, name, marks);
    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct student *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

void display(struct student *head){
    struct student *temp = head;
    printf("\nStudent Record: \n");
    while(temp != NULL){
        printf("Roll: %d, Name: %s, Marks: %g\n", temp->roll, temp->name, temp->marks);
        temp = temp->next;
    }
} 

int main() {
    struct student *head = NULL;
    insertEnd(&head, 101, "Manirul", 86.8);
    insertEnd(&head, 154, "Shewli", 92.1);
    insertEnd(&head, 141, "Shefali", 70.5);
    insertFirst(&head, 104, "David", 95.3);
    insertFirst(&head, 134, "John", 79.6);
    insertFirst(&head, 127, "Stephen", 89.8);

    display(head);

    return 0;
}