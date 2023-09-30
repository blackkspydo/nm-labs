// Q.1 Approximation of root of non-linear eqn using bisection method.
// Non linear eqn using bisection method

#include <stdio.h>
#include <math.h>

#define EPS 0.00001

float f(float x)
{
    return sin(x) - 2 * x + 1;
}

int main()
{
    float a, b, c;
    int n = 0;
    do
    {
        printf("Enter two valid initial points a and b:\n");
        scanf("%f%f", &a, &b);
    } while (f(a) * f(b) >= 0);

    do
    {
        n++;
        c = (a + b) / 2;
        if (f(c) == 0)
            break;
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
        printf("a = %f, b = %f, c = %f\n", a, b, c);
    }while (fabs((b - a) / a) > EPS);
    printf("The approximate root of given function is %f with %d number of iterations.", c, n);
    return 0;
}