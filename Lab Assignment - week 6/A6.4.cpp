#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *prev;
    struct Node *next;
};

// Insert at End
void insertEnd(struct Node **head, char value) {

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Check Palindrome
int isPalindrome(struct Node *head) {

    if (head == NULL)
        return 1;

    struct Node *last = head;

    while (last->next != NULL)
        last = last->next;

    while (head != last && head->prev != last) {

        if (head->data != last->data)
            return 0;

        head = head->next;
        last = last->prev;
    }

    return 1;
}

int main() {

    struct Node *head = NULL;

    insertEnd(&head, 'R');
    insertEnd(&head, 'A');
    insertEnd(&head, 'D');
    insertEnd(&head, 'A');
    insertEnd(&head, 'R');

    if (isPalindrome(head))
        printf("True");

    else
        printf("False");

    return 0;
}