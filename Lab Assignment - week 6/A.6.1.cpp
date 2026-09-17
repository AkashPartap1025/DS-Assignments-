#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void insertEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(int target, int value) {

    struct Node *temp = head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node not found!\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void insertBefore(int target, int value) {

    if (head == NULL)
        return;

    if (head->data == target) {
        insertBeginning(value);
        return;
    }

    struct Node *temp = head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node not found!\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = temp;
    newNode->prev = temp->prev;

    temp->prev->next = newNode;
    temp->prev = newNode;
}

void deleteNode(int key) {

    if (head == NULL) {
        printf("List Empty\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }

    if (temp == head)
        head = head->next;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    printf("Node Deleted\n");
}

void searchNode(int key) {

    struct Node *temp = head;
    int pos = 1;

    while (temp != NULL) {

        if (temp->data == key) {
            printf("Node found at position %d\n", pos);
            return;
        }

        temp = temp->next;
        pos++;
    }

    printf("Node not found\n");
}

void display() {

    struct Node *temp = head;

    if (temp == NULL) {
        printf("List Empty\n");
        return;
    }

    printf("NULL <-> ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {

    int choice, value, target;

    while (1) {

        printf("\n----- DOUBLY LINKED LIST -----\n");

        printf("1. Insert Beginning\n");
        printf("2. Insert End\n");
        printf("3. Insert Before Node\n");
        printf("4. Insert After Node\n");
        printf("5. Delete Node\n");
        printf("6. Search Node\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter Value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;

            case 2:
                printf("Enter Value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter Target Node: ");
                scanf("%d", &target);

                printf("Enter New Value: ");
                scanf("%d", &value);

                insertBefore(target, value);
                break;

            case 4:
                printf("Enter Target Node: ");
                scanf("%d", &target);

                printf("Enter New Value: ");
                scanf("%d", &value);

                insertAfter(target, value);
                break;

            case 5:
                printf("Enter Node to Delete: ");
                scanf("%d", &value);

                deleteNode(value);
                break;

            case 6:
                printf("Enter Value to Search: ");
                scanf("%d", &value);

                searchNode(value);
                break;

            case 7:
                display();
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}