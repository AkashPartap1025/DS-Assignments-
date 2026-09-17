#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

int sizeDLL(struct Node *head) {

    int count = 0;

    while(head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

int main() {

    struct Node *head, *second, *third;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    second->data = 20;
    third->data = 30;

    head->prev = NULL;
    head->next = second;

    second->prev = head;
    second->next = third;

    third->prev = second;
    third->next = NULL;

    printf("Size of Doubly Linked List = %d", sizeDLL(head));

    return 0;
}
