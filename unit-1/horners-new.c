// Horner's Method for approximating root of given function

/*
 * This program uses Horner's Method to approximate the root of a given function.
 * The user is prompted to enter the degree of the polynomial, the coefficients of the polynomial
 * starting from the highest degree, and a valid initial point. The program then uses Horner's Method
 * to approximate the root of the function and outputs the result along with the number of iterations
 * it took to reach the approximation.
 *
 * Horner's Method is a numerical method for finding the roots of a polynomial. It is a fast and efficient
 * method that can be used to approximate the roots of a polynomial with a high degree of accuracy.
 *
 * The program defines a tolerance level (EPS) for the approximation, which determines the accuracy of the
 * approximation. The program continues to iterate until the difference between the current and next point
 * is less than the tolerance level.
 *
 * The program uses the following formula to calculate the next point:
 *
 * next_point = initial_point - (fx / derivative)
 *
 * where fx and derivative are the results of the Horner's Method calculation for the current point.
 *
 * The program outputs the approximate root of the function and the number of iterations it took to reach
 * the approximation.
 */
#include <stdio.h>
#include <math.h>

#define EPS 0.00001 // EPS is the tolerance level for the approximation

void horner(int degree, float coefficients[], float initial_point, float *fx, float *derivative)
{
    int i;
    *fx = coefficients[0], *derivative = coefficients[0];
    for (i = 1; i < degree; i++)
    {
        printf("%f\n", *fx);
        *fx = coefficients[i] + *fx * initial_point;
        *derivative = *fx + *derivative * initial_point;
    }
    *fx = coefficients[degree] + *fx * initial_point;
}

int main()
{
    float coefficients[10], initial_point, next_point, fx, derivative;
    int i, degree, count = 1;

    printf("Enter the degree of the polynomial:\n");
    scanf("%d", &degree);

    printf("\nEnter the coefficients of the polynomial starting from the highest degree\n");
    for (i = 0; i <= degree; i++)
    {
        scanf("%f", &coefficients[i]);
    }

    printf("Enter a valid initial point:\n");
    scanf("%f", &initial_point);

    printf("The coefficients of the polynomial are:\n");
    for (i = degree; i >= 0; i--)
    {
        printf("%f ", coefficients[i]);
    }
    printf("\n");

    horner(degree, coefficients, initial_point, &fx, &derivative);
    next_point = initial_point - (fx / derivative);

    while (fabs((next_point - initial_point) / next_point) > EPS)
    {
        count++;
        initial_point = next_point;
        horner(degree, coefficients, initial_point, &fx, &derivative);
        next_point = initial_point - (fx / derivative);
    }

    printf("\nThe approximate root of given function is %f with %d number of iterations.", next_point, count);
    return 0;
}