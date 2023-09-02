// Newton Raphson Method
#include <stdio.h>
#include <math.h>
#define EPS 0.00001

float f(float x)
{
    return x * x - 3;
}
float fd(float x)
{
    return 2 * x;
}

int main()
{
    float x0, x1;
    int n = 1;
    do
    {
        printf("Enter a valid initial point x0:\n");
        scanf("%f", &x0);
    } while (fd(x0) == 0);
    x1 = x0 - (f(x0) / fd(x0));
    while (fabs((x1 - x0) / x1) > EPS)
    {
        n++;
        x0 = x1;
        x1 = x0 - (f(x0) / fd(x0));
        if (f(x1) == 0)
            break;
    }
    printf("The approximate root of given function is %f with %d number of iterations.", x1, n);
    return 0;
}