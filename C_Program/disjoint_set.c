#include <stdio.h>

struct DisjSet {
    int parent[10];
    int rank[10];
    int n;
} dis;

void makeSet() {
    int i;
    for(i = 0; i < dis.n; i++) {
        dis.parent[i] = i;
        dis.rank[i] = 0;
    }
}

void displaySet() {
    int i;
    printf("\nParent Array:\n");
    for(i = 0; i < dis.n; i++) {
        printf("\t%d", dis.parent[i]);
    }
    printf("\nRank Array:\n");
    for(i = 0; i < dis.n; i++) {
        printf("\t%d", dis.rank[i]);
    }
    printf("\n");
}

int find(int x) {
    if(dis.parent[x] != x) {
        dis.parent[x] = find(dis.parent[x]);  // Path compression
    }
    return dis.parent[x];
}

void Union(int x, int y) {
    int xset = find(x);
    int yset = find(y);

    if(xset == yset)
        return;

    // Union by rank
    if(dis.rank[xset] < dis.rank[yset]) {
        dis.parent[xset] = yset;
    } else if(dis.rank[xset] > dis.rank[yset]) {
        dis.parent[yset] = xset;
    } else {
        dis.parent[yset] = xset;
        dis.rank[xset]++;
    }
}

int main() {
    int n, x, y;
    printf("How many elements (max 10): ");
    scanf("%d", &dis.n);

    if(dis.n > 10 || dis.n <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    makeSet();

    int ch, wish;
    do {
        printf("\nMENU\n");
        printf("1. Union\n2. Find\n3. Display\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter elements to perform union (0 to %d): ", dis.n - 1);
                scanf("%d %d", &x, &y);
                if(x >= 0 && x < dis.n && y >= 0 && y < dis.n) {
                    Union(x, y);
                } else {
                    printf("Invalid elements.\n");
                }
                break;

            case 2:
                printf("Enter elements to check if connected components (0 to %d): ", dis.n - 1);
                scanf("%d %d", &x, &y);
                if(x >= 0 && x < dis.n && y >= 0 && y < dis.n) {
                    if(find(x) == find(y))
                        printf("Connected components\n");
                    else
                        printf("Not connected components\n");
                } else {
                    printf("Invalid elements.\n");
                }
                break;

            case 3:
                displaySet();
                break;

            default:
                printf("Invalid choice!\n");
        }

        printf("\nDo you wish to continue? (1/0): ");
        scanf("%d", &wish);

    } while(wish == 1);

    return 0;
}

