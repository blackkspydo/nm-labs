#include <stdio.h>

double divided_difference(double x[], double fx[], int i, int j)
{
    return (fx[j] - fx[i]) / (x[j] - x[i]);
}

double newton_derivative(double x[], double fx[], int n, double point)
{
    double result = 0.0;
    double product = 1.0;

    for (int i = 0; i < n - 1; i++)
    {
        result += divided_difference(x, fx, i, i + 1) * product;
        product *= (point - x[i]);
    }

    return result;
}

int main()
{
    int n = 4;                               // Number of data points
    double x[] = {2.0, 4.0, 9.0, 10.0};      // x values
    double fx[] = {4.0, 56.0, 711.0, 980.0}; // f(x) values

    double point = 5; // The point at which to calculate the derivative

    double derivative = newton_derivative(x, fx, n, point);
    printf("The first-order derivative at x = %.2f is %.2f\n", point, derivative);

    return 0;
}