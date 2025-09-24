#include <stdio.h>
#include <stdlib.h>

void display();
void in_b();
void in_e();
void in_bw();
void del_b();
void del_e();
void del_bw();
void menu();

struct node {
    int data;
    struct node *link;
};
typedef struct node node1;

node1 *start = NULL;

int main() {
    printf("Singly linked list\n");
    printf("MENU\n");
    menu();
    return 0;
}

void menu() {
    int x;
    printf("\n1. Display\n2. Insertion at beginning\n3. Insertion at end\n4. Insertion in between\n5. Deletion at beginning\n6. Deletion at end\n7. Deletion in between\n8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &x);

    switch (x) {
        case 1: display(); break;
        case 2: in_b(); break;
        case 3: in_e(); break;
        case 4: in_bw(); break;
        case 5: del_b(); break;
        case 6: del_e(); break;
        case 7: del_bw(); break;
        case 8: exit(0);
        default:
            printf("Invalid choice! Try again.\n");
            menu();
    }
}

node1 *create() {
    node1 *nptr = (node1*)malloc(sizeof(node1));
    if (nptr == NULL) {
        printf("Memory Overflow\n");
        exit(1); // exit as memory allocation failed
    }
    return nptr;
}

void display() {
    node1 *ptr = start;
    if (ptr == NULL) {
        printf("\nNo elements to display\n");
    } else {
        printf("\nElements in the linked list are:\n");
        while (ptr != NULL) {
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
    menu();
}

void in_b() {
    int val;
    printf("\nEnter the element to be inserted at beginning: ");
    scanf("%d", &val);

    node1 *nptr = create();
    nptr->data = val;
    nptr->link = start;
    start = nptr;

    printf("Element inserted at beginning\n");
    menu();
}

void in_e() {
    int val;
    printf("\nEnter the element to be inserted at end: ");
    scanf("%d", &val);

    node1 *nptr = create();
    nptr->data = val;
    nptr->link = NULL;

    if (start == NULL) {
        start = nptr;
    } else {
        node1 *temp = start;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = nptr;
    }

    printf("Element inserted at end\n");
    menu();
}

void in_bw() {
    int val, pos, i;
    printf("\nEnter the element and the position to be inserted: ");
    scanf("%d %d", &val, &pos);

    if (pos <= 0) {
        printf("Invalid position!\n");
        menu();
        return;
    }

    node1 *nptr = create();
    nptr->data = val;
    nptr->link = NULL;

    if (pos == 1) {
        nptr->link = start;
        start = nptr;
    } else {
        node1 *temp = start;
        for (i = 1; i < pos - 1; i++) {
            if (temp == NULL) {
                printf("Position out of range!\n");
                free(nptr);
                menu();
                return;
            }
            temp = temp->link;
        }
        if (temp == NULL) {
            printf("Position out of range!\n");
            free(nptr);
            menu();
            return;
        }
        nptr->link = temp->link;
        temp->link = nptr;
    }

    printf("Element inserted at position %d\n", pos);
    menu();
}

void del_b() {
    if (start == NULL) {
        printf("\nList is empty! No elements to delete.\n");
    } else {
        node1 *temp = start;
        start = start->link;
        free(temp);
        printf("\nElement deleted from beginning\n");
    }
    menu();
}

void del_e() {
    if (start == NULL) {
        printf("\nList is empty! No elements to delete.\n");
        menu();
        return;
    }

    if (start->link == NULL) {
        // Only one node
        free(start);
        start = NULL;
    } else {
        node1 *temp = start;
        node1 *prev = NULL;
        while (temp->link != NULL) {
            prev = temp;
            temp = temp->link;
        }
        prev->link = NULL;
        free(temp);
    }
    printf("\nElement deleted from end\n");
    menu();
}

void del_bw() {
    int pos, i;
    printf("Enter the position of element to delete: ");
    scanf("%d", &pos);

    if (start == NULL) {
        printf("List is empty! No elements to delete.\n");
        menu();
        return;
    }
    if (pos <= 0) {
        printf("Invalid position!\n");
        menu();
        return;
    }

    if (pos == 1) {
        node1 *temp = start;
        start = start->link;
        free(temp);
        printf("\nElement deleted from position 1\n");
    } else {
        node1 *temp = start;
        node1 *pre = NULL;
        for (i = 1; i < pos; i++) {
            pre = temp;
            temp = temp->link;
            if (temp == NULL) {
                printf("Position out of range!\n");
                menu();
                return;
            }
        }
        pre->link = temp->link;
        free(temp);
        printf("\nElement deleted from position %d\n", pos);
    }
    menu();
}
