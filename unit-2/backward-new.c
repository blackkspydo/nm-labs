// Newton's Interpolation using backward difference table

#include <stdio.h>
#include <math.h>
#define MAX 15

int main()
{
    int num_pairs, i, j, k;
    float x[MAX], fx[MAX], backward_diff[MAX], xp, s, h, interpolated_value, p;
    char q;

    // Input the number of data pairs
    printf("\nInput the number of data pairs:");
    scanf("%d", &num_pairs);

    // Input data pairs x(i) and values f(i) (one set in each line)
    printf("\nInput data pairs x(i) and values f(i) (one set in each line):");
    for (i = 1; i <= num_pairs; i++)
    {
        scanf("%f%f", &x[i], &fx[i]);
    }

    // Calculate the value of h
    h = x[2] - x[1];

    // Enter the value at which interpolation is required
    printf("\nEnter the value at which interpolation is required:");
    scanf("%f", &xp);

    // Calculate the value of s
    s = (xp - x[num_pairs] / h);

    // Initialize the value of p and interpolated_value
    p = 1;
    interpolated_value = fx[num_pairs];

    // Copy the values of fx to backward_diff
    for (i = 1; i <= num_pairs; i++)
        backward_diff[i] = fx[i];

    // Calculate the backward difference table
    for (i = num_pairs, k = 1; i >= 1, k < num_pairs; i--, k++)
    {
        for (j = num_pairs; j >= num_pairs - i; j--)
        {
            backward_diff[j] = backward_diff[j] - backward_diff[j - 1];
        }

        // Calculate the value of p
        p = p * (s + k - 1) / k;

        // Calculate the interpolated value
        interpolated_value = interpolated_value + p * backward_diff[num_pairs];
    }

    // Print the interpolated function value
    printf("\nInterpolated function value at x=%f is %f.", xp, interpolated_value);
    return 0;
}