
#include <stdio.h>
#define MAX 5

int main() {
    int queue[MAX], front = -1, rear = -1;
    int n, i, item;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &item);

        if (rear == MAX - 1) {
            printf("Queue is Full\n");
            break;
        }

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = item;
    }

    printf("\nQueue elements are: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    if (front == -1) {
        printf("Queue is Empty");
    }

    if (front != -1) {
        printf("\n\nEnter the number of elements to delete: ");
        scanf("%d", &n);

        for (i = 0; i < n; i++) {
            if (front == -1 || front > rear) {
                printf("Queue is Empty\n");
                break;
            }

            printf("Deleted element: %d\n", queue[front]);
            front++;
        }
    }

    printf("\nQueue after deletion: ");

    if (front == -1 || front > rear) {
        printf("Queue is Empty");
    } else {
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }

    return 0;
}

