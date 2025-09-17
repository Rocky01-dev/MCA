
#include <stdio.h>
#include <stdlib.h>

void enqueue();
void dequeue();
void display();
void peek();

int queue[50], front = -1, rear = -1, n;

int main() {
    int choice;

    printf("Enter the size of the queue (max 50): ");
    scanf("%d", &n);

    if (n <= 0 || n > 50) {
        printf("Invalid size. Please enter size between 1 and 50.\n");
        return 1;
    }

    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void enqueue() {
    int item;
    if (rear == n - 1) {
        printf("Queue is full, can't insert data.\n");
        return;
    }

    printf("Enter the element to be inserted: ");
    scanf("%d", &item);

    if (front == -1) { // first insertion
        front = 0;
    }
    rear++;
    queue[rear] = item;

    printf("Inserted successfully.\n");
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);
    front++;

    if (front > rear) { // queue is empty after deletion
        front = rear = -1;
    }
}

void display() {
    if (rear == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d\t", queue[i]);
    }
    printf("\n");
}

void peek() {
    if (front == -1) {
        printf("No element in queue.\n");
    } else {
        printf("Peek element: %d\n", queue[front]);
    }
}
