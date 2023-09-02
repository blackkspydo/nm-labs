// Polynomial interpolation using Newton's Interpolation
#include <stdio.h>
#include <math.h>

#define MAX 15
int main()
{
    int i, j, n;
    float xp, fp, sum, pi, x[MAX], f[MAX], a[MAX], d[MAX][MAX];
    char q;
    printf("\nInput the number of data pairs:");
    scanf("%d", &n);
    printf("\nInput data pairs x(i) and values f(i) (one set in each line):");
    for (i = 1; i <= n; i++)
        scanf("%f %f", &x[i], &f[i]);
    for (i = 1; i <= n; i++)
        d[i][1] = f[i];
    for (j = 2; j <= n; j++)
        for (i = 1; i < n - j + 1; i++)
            d[i][j] = (d[i + 1][j - 1] - d[i][j - 1]) / (x[i + j - 1] - x[i]);
    for (j = 1; j <= n; j++)
        a[j] = d[1][j];
    printf("\nInput x at which interpolation is required:");
    scanf("%f", &xp);
    sum = a[i];
    for (i = 2; i <= n; i++)
    {
        pi = 1.0;
        for (j = 1; j <= i - 1; j++)
            pi = pi * (xp - x[j]);
        sum = sum + a[i] * pi;
    }
    fp = sum;
    printf("\n Interpolated function value at x=%f is %f.", xp, fp);
    return 0;
}