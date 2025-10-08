#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
int count = 0;

// Function to create a new node
struct node* create() {
    int v;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    printf("Enter the value to insert:\n");
    scanf("%d", &v);
    newNode->data = v;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void ins_beg() {
    struct node *newNode = create();
    if (newNode == NULL) return;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Node inserted at beginning.\n");
    count++;
}

// Insert at end
void ins_end() {
    struct node *newNode = create();
    if (newNode == NULL) return;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node *t = head;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = newNode;
        newNode->prev = t;
    }
    printf("Node inserted at end.\n");
    count++;
}

// Insert at specific position
void ins_pos() {
    int pos, i;
    printf("Enter position to insert:\n");
    scanf("%d", &pos);

    if (pos < 1 || pos > count + 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        ins_beg();
    } else if (pos == count + 1) {
        ins_end();
    } else {
        struct node *newNode = create();
        if (newNode == NULL) return;

        struct node *t = head;
        for (i = 1; i < pos - 1; i++) {
            t = t->next;
        }
        newNode->next = t->next;
        newNode->prev = t;
        t->next->prev = newNode;
        t->next = newNode;
        printf("Node inserted at position %d.\n", pos);
        count++;
    }
}

// Delete from beginning
void del_beg() {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct node *d = head;
    if (head->next == NULL) {
        head = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    free(d);
    printf("Node deleted from beginning.\n");
    count--;
}

// Delete from end
void del_end() {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct node *d = head;
    if (head->next == NULL) {
        head = NULL;
    } else {
        while (d->next != NULL) {
            d = d->next;
        }
        d->prev->next = NULL;
    }
    free(d);
    printf("Node deleted from end.\n");
    count--;
}

// Delete from specific position
void del_pos() {
    int pos, i;
    printf("Enter position to delete:\n");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    if (pos < 1 || pos > count) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        del_beg();
    } else if (pos == count) {
        del_end();
    } else {
        struct node *d = head;
        for (i = 1; i < pos; i++) {
            d = d->next;
        }
        d->prev->next = d->next;
        d->next->prev = d->prev;
        free(d);
        printf("Node deleted from position %d.\n", pos);
        count--;
    }
}

// Display the list
void display() {
    if (head == NULL) {
        printf("Linked list is empty.\n");
    } else {
        struct node *t = head;
        printf("Linked list:\n");
        while (t != NULL) {
            printf("%d\t", t->data);
            t = t->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    int ch;
    printf("Doubly Linked List Operations:\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: ins_beg(); break;
            case 2: ins_end(); break;
            case 3: ins_pos(); break;
            case 4: del_beg(); break;
            case 5: del_end(); break;
            case 6: del_pos(); break;
            case 7: display(); break;
            case 8: 
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Wrong choice. Try again.\n");
        }
    }

    return 0;
}
