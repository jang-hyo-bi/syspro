#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void addq(struct node *head, struct node **tail, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*tail == NULL) {
        head->next = newNode;
    } else {
        (*tail)->next = newNode;
    }
    *tail = newNode;
    printf("%d added\n", data);
}

int delete_element(struct node *head, struct node **tail) {
    if (head->next == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    struct node *temp = head->next;
    int deletedData = temp->data;
    head->next = temp->next;

    if (head->next == NULL) {
        *tail = NULL;
    }
    free(temp);
    return deletedData;
}

void printQueue(struct node *head) {
    printf("Full queue: ");
    if (head->next == NULL) {
        printf("Empty\n");
        return;
    }
    struct node *current = head->next;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    struct node *tail = NULL;

    addq(head, &tail, 10);
    addq(head, &tail, 20);
    addq(head, &tail, 30);

    int deleted = delete_element(head, &tail);
    if (deleted != -1) {
        printf("%d removed\n", deleted);
    }

    addq(head, &tail, 40);
    addq(head, &tail, 50);
    printQueue(head);

    struct node *temp = head;
    while (temp != NULL) {
        struct node *toFree = temp;
        temp = temp->next;
        free(toFree);
    }

    return 0;
}

