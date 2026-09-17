#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

int countOccurrences(struct Node* head, int key) {
    int count = 0;

    while (head != NULL) {
        if (head->data == key)
            count++;

        head = head->next;
    }

    return count;
}

void deleteOccurrences(struct Node** head, int key) {

    while (*head != NULL && (*head)->data == key) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    struct Node* curr = *head;

    while (curr != NULL && curr->next != NULL) {
        if (curr->next->data == key) {
            struct Node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        }
        else {
            curr = curr->next;
        }
    }
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);

        if (head->next != NULL)
            printf(" -> ");

        head = head->next;
    }
    printf("\n");
}

int main() {

    struct Node* head = NULL;
    int key = 1;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 1);
    insert(&head, 3);
    insert(&head, 1);
    insert(&head, 1);
    insert(&head, 1);

    printf("Original Linked List: ");
    display(head);

    int count = countOccurrences(head, key);

    deleteOccurrences(&head, key);

    printf("Count: %d\n", count);

    printf("Updated Linked List: ");
    display(head);

    return 0;
}