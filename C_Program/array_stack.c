
#include<stdio.h>
#include<stdlib.h>

void push(), pop(), display(), peek();

int stack[20], top = -1, n, item;

int main() {
    int choice;

    printf("Enter the size of stack (max 20): ");
    scanf("%d", &n);

    if (n > 20 || n <= 0) {
        printf("Invalid size. Must be between 1 and 20.\n");
        return 1;
    }

    printf("\nStack Operations:\n");
    printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit");

    do {
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: printf("Exiting program...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

void push() {
    if (top != n - 1) {
        printf("Enter the element to be pushed: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
        printf("Inserted Successfully.\n");
    } else {
        printf("Can't insert, stack is full!\n");
    }
}

void pop() {
    if (top == -1) {
        printf("Can't delete, stack is empty!\n");
    } else {
        item = stack[top];
        printf("Deleted element: %d\n", item);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("No element in stack.\n");
    } else {
        printf("The topmost element is: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d\t", stack[i]);
        }
        printf("\n");
    }
}
