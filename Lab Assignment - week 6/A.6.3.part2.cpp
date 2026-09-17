#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int sizeCLL(struct Node *head) {

    if(head == NULL)
        return 0;

    int count = 0;
    struct Node *temp = head;

    do {
        count++;
        temp = temp->next;
    } while(temp != head);

    return count;
}

int main() {

    struct Node *head, *second, *third, *fourth, *fifth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 20;
    second->data = 100;
    third->data = 40;
    fourth->data = 80;
    fifth->data = 60;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head;

    printf("Size of Circular Linked List = %d", sizeCLL(head));

    return 0;
}
