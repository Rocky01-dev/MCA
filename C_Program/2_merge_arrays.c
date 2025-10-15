
#include <stdio.h>

void merge(int a[], int b[], int c[], int m, int n);

int main() {
    int m, n, i;
    int a[20], b[20], c[40]; // c needs enough space for m+n

    printf("Enter the size of first array: ");
    scanf("%d", &m);

    printf("Enter the elements of first array (sorted): ");
    for (i = 0; i < m; i++)
        scanf("%d", &a[i]);

    printf("Enter the size of second array: ");
    scanf("%d", &n);

    printf("Enter the elements of second array (sorted): ");
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);

    merge(a, b, c, m, n);

    return 0;
}

void merge(int a[], int b[], int c[], int m, int n) {
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while (i < m) {
        c[k++] = a[i++];
    }

    while (j < n) {
        c[k++] = b[j++];
    }

    printf("Merged array is:\n");
    for (i = 0; i < k; i++)
        printf("%d ", c[i]);
    printf("\n");
}
