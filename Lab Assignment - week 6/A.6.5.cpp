#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int isCircular(struct Node *head) {

    if(head == NULL)
        return 0;

    struct Node *temp = head->next;

    while(temp != NULL && temp != head) {
        temp = temp->next;
    }

    if(temp == head)
        return 1;
    else
        return 0;
}

int main() {

    struct Node *head, *second, *third, *fourth, *fifth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 2;
    second->data = 4;
    third->data = 6;
    fourth->data = 7;
    fifth->data = 5;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    fifth->next = head;

    if(isCircular(head))
        printf("True");
    else
        printf("False");

    return 0;
}
