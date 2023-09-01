// Gaussian elimination  with partial pivoting

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

int pivot(int n, float a[MAX][MAX], float b[MAX], int k)
{
    int p;
    float large, temp;
    p = k;
    large = fabs(a[k][k]);
    for (int i = k + 1; i <= n; i++)
    {
        if (fabs(a[i][k]) > large)
        {
            large = fabs(a[i][k]);
            p = i;
        }
    }
    if (p != k)
    {
        for (int j = k; j <= n; j++)
        {
            temp = a[p][j];
            a[p][j] = a[k][j];
            a[k][j] = temp;
        }
        temp = b[p];
        b[p] = b[k];
        b[k] = temp;
    }
    return 0;
}

int back_substitution(int n, float a[MAX][MAX], float b[MAX], float x[MAX])
{
    int i, j, k;
    float sum;
    x[n] = b[n] / a[n][n];
    for (k = n - 1; k <= 1; k--)
    {
        sum = 0.0;
        for (j = k + 1; j <= n; j++)
        {
            sum = sum + a[k][j] * x[j];
            x[k] = (b[k] - sum) / a[k][k];
        }
    }
    return 0;
}

int elimination(int n, float a[MAX][MAX], float b[MAX])
{
    int i, j, k, p;
    float factor, sum, temp;
    for (k = 0; k < n - 1; k++)
    {
        pivot(n, a, b, k);
        for (i = k + 1; i < n; i++)
        {
            factor = a[i][k] / a[k][k];
            for (j = k + 1; j < n; j++)
            {
                a[i][j] = a[i][j] - factor * a[k][j];
            }
            b[i] = b[i] - factor * b[k];
        }
    }
    return 0;
}
int gauss2(int n, float a[MAX][MAX], float b[MAX], float x[MAX])
{
    elimination(n, a, b);
    back_substitution(n, a, b, x);
    return 0;
}
int main()
{
    int i, j, n;
    float a[MAX][MAX], b[MAX], x[MAX];
    printf("\nInput the number of variables:");
    scanf("%d", &n);
    printf("\nInput coefficients a(i,j),row-wise (one row on each line):\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%f", &a[i][j]);
    printf("\nEnter the vector b:\n");
    for (i = 1; i <= n; i++)
        scanf("%f", &b[i]);
    gauss2(n, a, b, x);
    printf("\nSolution vectorx:\n");
    for (i = 1; i <= n; i++)
        printf("\t%f", x[i]);
    return 0;
}
