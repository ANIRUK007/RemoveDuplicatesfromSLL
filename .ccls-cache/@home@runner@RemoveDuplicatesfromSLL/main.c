#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* deleteDuplicates(struct Node* head) 
{
    struct Node *current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node *temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return head;
}


int main() {
    struct Node* head = NULL;

    insertEnd(&head, 1);
    insertEnd(&head, 1);
    insertEnd(&head, 3);
    insertEnd(&head, 4);

    printf("Linked List: ");
    displayList(head);

    deleteDuplicates(head);
    displayList(head);

    return 0;
}
