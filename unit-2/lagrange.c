// Polynomial interpolation using Lagrange's Method

#include <stdio.h>
#include <math.h>

#define MAX_DATA_POINTS 15

int main()
{
    int num_data_points, i, j;
    float x[MAX_DATA_POINTS], y[MAX_DATA_POINTS], interpolated_value, lagrange_factor, sum, x_interpolation_point;
    char q;

    // Prompt user to input the number of data points
    printf("\n Input the number of data points: ");
    scanf("%d", &num_data_points);

    // Prompt user to input data points x(i) and values y(i) (one set in each line)
    printf("\nInput data points x(i) and values y(i) (one set in each line):");
    for (i = 0; i < num_data_points; i++)
        scanf("%f %f", &x[i], &y[i]);

    // Prompt user to input x at which interpolation is required
    printf("\n Input x at which interpolation is required: ");
    scanf("%f", &x_interpolation_point);

    sum = 0.0;

    // Calculate the interpolated value using Lagrange's method
    for (i = 0; i < num_data_points; i++)
    {
        lagrange_factor = 1.0;
        for (j = 0; j < num_data_points; j++)
        {
            if (i != j)
                lagrange_factor = lagrange_factor * (x_interpolation_point - x[j]) / (x[i] - x[j]);
        }
        sum = sum + lagrange_factor * y[i];
    }

    interpolated_value = sum;

    // Print the interpolated function value at x = x_interpolation_point
    printf("\n Interpolated function value at x = %f is %f.", x_interpolation_point, interpolated_value);

    return 0;
}

