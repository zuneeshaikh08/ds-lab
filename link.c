#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;


void push(int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into stack\n", value);
}


int pop() {
    struct Node *temp;
    int value;

    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }

    temp = top;
    value = top->data;
    top = top->next;

    free(temp);

    return value;
}


int peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }

    return top->data;
}


void display() {
    struct Node *temp = top;

    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    printf("Popped: %d\n", pop());

    printf("Top element: %d\n", peek());

    display();

    return 0;
}

