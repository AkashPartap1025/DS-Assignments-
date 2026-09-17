#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; // global head pointer

// Insert at Beginning
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at End
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert After a Specific Node
void insertAfter(int target, int value) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Target not found!\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from Beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete from End
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Delete Specific Node
void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Node not found!\n");
        return;
    }
    struct Node* del = temp->next;
    temp->next = temp->next->next;
    free(del);
}

// Search for a Node
void searchNode(int key) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Not found!\n");
}

// Display List
void displayList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main Menu
int main() {
    int choice, value, target;
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert After\n");
        printf("4. Delete Beginning\n5. Delete End\n6. Delete Specific\n");
        printf("7. Search\n8. Display\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &value); insertAtBeginning(value); break;
            case 2: printf("Enter value: "); scanf("%d", &value); insertAtEnd(value); break;
            case 3: printf("Enter target: "); scanf("%d", &target); printf("Enter value: "); scanf("%d", &value); insertAfter(target, value); break;
            case 4: deleteBeginning(); break;
            case 5: deleteEnd(); break;
            case 6: printf("Enter value to delete: "); scanf("%d", &value); deleteNode(value); break;
            case 7: printf("Enter value to search: "); scanf("%d", &value); searchNode(value); break;
            case 8: displayList(); break;
            case 9: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}