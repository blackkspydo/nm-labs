// Newton's interpolation
#include <stdio.h>
#include <math.h>
#define MAX 15
#define YES 'y'

int main()
{
    int i, j, n;
    float xp, fp, sum, pi, x[MAX], f[MAX], a[MAX], d[MAX][MAX];
    char q;
    printf("Input the number of data pairs:");
    scanf("%d", &n);
    printf("Input data pairs x(i) and values f(i) (one set in each line):");
    for (i = 0; i < n; i++)
    {
        scanf("%f%f", &x[i], &f[i]);
    }

    // Construct difference table
    for (i = 0; i < n; i++)
    {
        d[i][0] = f[i];
    }
    for (j = 1; j < n; j++)
    {
        for (i = 0; i < n - j; i++)
        {
            d[i][j] = (d[i + 1][j - 1] - d[i][j - 1]) / (x[i + j] - x[i]); // Fix indexing here
        }
    }

    // Set the coefficients of interpolation polynomial
    for (i = 0; i < n; i++)
    {
        a[i] = d[0][i];
    }

    // Compute interpolation value
    do
    {
        printf("\nInput x at which interpolation is required:");
        scanf("%f", &xp);
        sum = a[0];
        for (i = 1; i < n; i++)
        {
            pi = 1.0;
            for (j = 0; j < i; j++)
            {
                pi = pi * (xp - x[j]);
            }
            sum = sum + a[i] * pi;
        }
        fp = sum;

        // Write results
        printf("\nInterpolated function value at x=%f is %f.", xp, fp);
        printf("\nDo you want to input another value? (y/n): ");
        scanf(" %c", &q);
    } while (q == YES);

    return 0;
}


// Input the number of data pairs:4
// Input data pairs x(i) and values f(i) (one set in each line):-1 -1
// -2 -9
// 2 11
// 4 69

// Input x at which interpolation is required:1

// Interpolated function value at x=1.000000 is 3.000000.