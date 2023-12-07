#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
void push(struct node **top, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    printf("%d\n", data);
}

int pop(struct node **top) {
    if (*top == NULL) {
        printf("stack is empty\n");
        return -1; 
	}
	struct node *temp = *top;
    int poppedData = temp->data;

    *top = temp->next;
    free(temp);
    return poppedData;
}

void printStack(struct node *top) {
    printf("print stack\n");
    while (top != NULL) {
        printf("%d\n ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct node *top = NULL;

	push(&top, 10);
	push(&top, 20);
	push(&top, 30);

    int popped = pop(&top);
    if (popped != -1) {
        printf("%d\n", popped);
    }

    push(&top, 40);
    push(&top, 50);
    printStack(top);

    return 0;
}

