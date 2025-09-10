#include <stdio.h>

#define MAX 100

void display(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int insert(int arr[], int n, int pos, int val) {
    if (n >= MAX) {
        printf("Array is full. Cannot insert.\n");
        return n;
    }
    if (pos < 0 || pos > n) {
        printf("Invalid position.\n");
        return n;
    }

    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = val;
    n++;

    printf("Inserted successfully.\n");
    return n;
}

int delete(int arr[], int n, int pos) {
    if (n == 0) {
        printf("Array is empty. Cannot delete.\n");
        return n;
    }
    if (pos < 0 || pos >= n) {
        printf("Invalid position.\n");
        return n;
    }

    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;
    printf("Deleted successfully.\n");
    return n;
}

int search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

void sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted in ascending order.\n");
}

int main() {
    int arr[MAX];
    int n = 0;
    int choice, val, pos, key, index;

    printf("Enter initial size of array: ");
    scanf("%d", &n);
    if (n > MAX) {
        printf("Size exceeds maximum limit.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        printf("\nArray Operations Menu:\n");
        printf("1. Display\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Sort\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(arr, n);
                break;
            case 2:
                printf("Enter position to insert (0 to %d): ", n);
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &val);
                n = insert(arr, n, pos, val);
                break;
            case 3:
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                n = delete(arr, n, pos);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &key);
                index = search(arr, n, key);
                if (index != -1)
                    printf("Element found at index %d.\n", index);
                else
                    printf("Element not found.\n");
                break;
            case 5:
                sort(arr, n);
		display(arr, n);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}

