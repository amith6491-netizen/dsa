#include <stdio.h>

int sum(int a[], int n)
{
    int i, s = 0;

    for(i = 0; i < n; i++)
    {
        s = s + a[i];
    }

    return s;
}

float average(int total, int n)
{
    return (float)total / n;
}

int main()
{
    int a[100], n, i, total;
    float avg;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    total = sum(a, n);
    avg = average(total, n);

    printf("\nSum = %d", total);
    printf("\nAverage = %.2f", avg);

    return 0;
}