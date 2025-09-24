#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct btnode {
    int value;
    struct btnode *l, *r;
};

// Function declarations
struct btnode* insert(struct btnode* root, int data);
struct btnode* delete(struct btnode* root, int data);
struct btnode* findMin(struct btnode* node);
void inorder(struct btnode* root);

int main() {
    struct btnode* root = NULL;
    int ch, data;

    while (1) {
        printf("\n--- BST OPERATIONS ---\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Inorder Traversal\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Enter value to delete: ");
                    scanf("%d", &data);
                    root = delete(root, data);
                }
                break;

            case 3:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// Insert a node
struct btnode* insert(struct btnode* root, int data) {
    if (root == NULL) {
        struct btnode* temp = (struct btnode*)malloc(sizeof(struct btnode));
        temp->value = data;
        temp->l = temp->r = NULL;
        return temp;
    }

    if (data < root->value)
        root->l = insert(root->l, data);
    else if (data > root->value)
        root->r = insert(root->r, data);
    else
        printf("Duplicate value not allowed.\n");

    return root;
}

// Delete a node
struct btnode* delete(struct btnode* root, int data) {
    if (root == NULL)
        return NULL;

    if (data < root->value)
        root->l = delete(root->l, data);
    else if (data > root->value)
        root->r = delete(root->r, data);
    else {
        // Node found
        if (root->l == NULL && root->r == NULL) {
            // Leaf node
            free(root);
            return NULL;
        } else if (root->l == NULL) {
            struct btnode* temp = root->r;
            free(root);
            return temp;
        } else if (root->r == NULL) {
            struct btnode* temp = root->l;
            free(root);
            return temp;
        } else {
            // Node with two children
            struct btnode* temp = findMin(root->r);
            root->value = temp->value;
            root->r = delete(root->r, temp->value);
        }
    }
    return root;
}

// Find the minimum node
struct btnode* findMin(struct btnode* node) {
    while (node->l != NULL)
        node = node->l;
    return node;
}

// Inorder traversal
void inorder(struct btnode* root) {
    if (root != NULL) {
        inorder(root->l);
        printf("%d -> ", root->value);
        inorder(root->r);
    }
}
