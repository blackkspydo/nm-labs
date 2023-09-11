
#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x * x * cos(x);
}

int main()
{
    int n, i;
    float a, b, h, sum = 0.0, ict;
    printf("\n Give lower limit of integration a:");
    scanf("%f", &a);
    printf("\n Give upper limit of integration a:");
    scanf("%f", &b);
    printf("\n Give the segment width h:");
    scanf("%f", &h);
    n = (b - a) / h;
    for (i = 1; i <= n - 1; i++)
        sum = sum + 2 * f(a + i * h);
    sum = sum + f(a) + f(b);
    ict = sum * h / 2;
    printf("\n Integration between %f and %f when h = %f is %f.", a, b, h, ict);
    return 0;
}