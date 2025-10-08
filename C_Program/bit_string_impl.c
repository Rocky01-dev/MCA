#include <stdio.h>

void input();
void output(int c[]);
void setunion();
void intersection();
void difference();

int a[9] = {0};
int b[9] = {0};

int main()
{
    int ch, wish;
    do
    {
        printf("\nMENU\n");
        printf("1. Input\n2. Union\n3. Intersection\n4. Difference\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                input();
                break;
            case 2:
                setunion();
                break;
            case 3:
                intersection();
                break;
            case 4:
                difference();
                break;
            default:
                printf("Invalid choice!\n");
        }
        printf("\nDo you wish to continue? (1/0): ");
        scanf("%d", &wish);
    } while(wish == 1);
    
    return 0;
}

void input()
{
    int n, x, i;
    
    // Reset arrays before new input
    for(i = 0; i < 9; i++) {
        a[i] = 0;
        b[i] = 0;
    }
    
    printf("Enter size of the 1st set: ");
    scanf("%d", &n);
    printf("Enter elements (1 to 9): ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if(x >= 1 && x <= 9)
            a[x - 1] = 1;
        else
            printf("Invalid element ignored: %d\n", x);
    }
    
    printf("Enter size of the 2nd set: ");
    scanf("%d", &n);
    printf("Enter elements (1 to 9): ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if(x >= 1 && x <= 9)
            b[x - 1] = 1;
        else
            printf("Invalid element ignored: %d\n", x);
    }
    
    printf("\n1st set: ");
    output(a);
    
    printf("\n2nd set: ");
    output(b);
    printf("\n");
}

void output(int c[])
{
    int i;
    printf("{ ");
    for(i = 0; i < 9; i++)
    {
        if (c[i] != 0)
            printf("%d ", i + 1);
    }
    printf("}");
}

void setunion()
{
    int i, c[9];
    for(i = 0; i < 9; i++)
    {
        c[i] = (a[i] || b[i]) ? 1 : 0;
    }
    printf("\nUnion of sets: ");
    output(c);
    printf("\n");
}

void intersection()
{
    int i, c[9];
    for(i = 0; i < 9; i++)
    {
        c[i] = (a[i] && b[i]) ? 1 : 0;
    }
    printf("\nIntersection of sets: ");
    output(c);
    printf("\n");
}

void difference()
{
    int i, c[9];
    for(i = 0; i < 9; i++)
    {
        c[i] = (a[i] == 1 && b[i] == 0) ? 1 : 0;
    }
    printf("\nDifference (1st set - 2nd set): ");
    output(c);
    printf("\n");
}

