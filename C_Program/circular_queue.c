#include <stdio.h>
#include <stdlib.h>

void enqueue();
void dequeue();
void display();

int queue[50], n, front = -1, rear = -1, choice, x;

int main() {
    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    }

    return 0;
}

void enqueue() {
    if ((front == rear + 1) || (front == 0 && rear == n - 1)) {
        printf("\nOverflow\n");
        return;
    }

    if (front == -1)  // Queue is empty
        front = 0;

    rear = (rear + 1) % n;

    printf("Enter element: ");
    scanf("%d", &x);
    queue[rear] = x;

    printf("Inserted element is %d\n", x);
}

void dequeue() {
    if (front == -1) {
        printf("\nUnderflow\n");
        return;
    }

    x = queue[front];
    if (front == rear) {
        // Queue has only one element
        front = rear = -1;
    } else {
        front = (front + 1) % n;
    }

    printf("Deleted element is %d\n", x);
}

void display() {
    if (front == -1) {
        printf("\nEmpty queue\n");
        return;
    }

    printf("Queue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % n;
    }
    printf("\n");
}
