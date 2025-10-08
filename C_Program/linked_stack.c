#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();

struct node {
    int val;
    struct node *next;
};

struct node *start = NULL;

int main()
{
    int choice = 0;
    printf("\nStack operations using linked list\n");
    while(choice != 4)
    {
        printf("\n---Menu---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Please enter a valid choice\n");
        }
    }
    return 0;
}

void push()
{
    int val;
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("Not able to push the element\n");
        return;
    }
    printf("Enter the value: ");
    scanf("%d", &val);

    ptr->val = val;
    ptr->next = start;
    start = ptr;

    printf("Item pushed\n");
}

void pop()
{
    if(start == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    int item = start->val;
    struct node* ptr = start;
    start = start->next;
    free(ptr);
    printf("Item popped: %d\n", item);
}

void display()
{
    struct node *ptr = start;
    if(ptr == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    while(ptr != NULL)
    {
        printf("%d\n", ptr->val);
        ptr = ptr->next;
    }
}

