#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x * x * exp(sqrt(x)) * sin(x);
}

int main()
{
    float a, h, fd1, fd2;
    printf("\nEnter the point at which derivatives are required: ");
    scanf("%f", &a);
    printf("\nEnter the value of h: ");
    scanf("%f", &h);
    fd1 = (f(a + h) - f(a - h)) / (2 * h);
    fd2 = (f(a + h) - 2 * f(a) + f(a - h)) / (h * h);
    printf("\nTHe first and second derivative at x=%f are %f and %f respectively", a, fd1, fd2);
    return 0;
}
