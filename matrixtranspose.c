#include <stdio.h>

int main()
{
    int a[10][10], m, n, i, j;

    printf("Enter rows and columns: ");
    scanf("%d%d", &m, &n);

    printf("Enter matrix:\n");

    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Transpose of matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            printf("%d ", a[j][i]);

        printf("\n");
    }

    return 0;
}