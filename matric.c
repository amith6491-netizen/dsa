#include <stdio.h>

int sum(int a[10][10], int m, int n)
{
    int i, j, s = 0;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            s = s + a[i][j];
        }
    }

    return s;
}

float average(int total, int m, int n)
{
    return (float)total / (m * n);
}

int main()
{
    int a[10][10], m, n, i, j, total;
    float avg;

    printf("Enter number of rows: ");
    scanf("%d", &m);

    printf("Enter number of columns: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    total = sum(a, m, n);
    avg = average(total, m, n);

    printf("\nSum of matrix = %d", total);
    printf("\nAverage of matrix = %.2f", avg);

    return 0;
}