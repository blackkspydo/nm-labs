// Solving System of Differential equation
#include <stdio.h>
#include <math.h>
#define EPS 0.00001
float f1(float x, float y1, float y2)
{
    return y2;
}
float f2(float x, float y1, float y2)
{
    return y1 * y2 + x * x + 1;
}
// Routine for Heun's method
void heun(float x0, float x1, float y0, float y1, float h)
{
    float m11, m12, m21, m22;
    printf("\n\nCalculation of y_1(%f) and y_2(%f):", x1, x1);
    printf("\n\n x \t\t y_1(x) \t\t y _2(x)");
    while (fabs(x0 - x1) > 0.0001)
    {
        printf("\n %f\t%f\t%f", x0, y0, y1);
        m11 = f1(x0, y0, y1);
        m21 = f2(x0, y0, y1);
        m12 = f1(x0 + h, y0 + h * m11, y1 + h * m21);
        m22 = f2(x0 + h, y0 + h * m11, y1 + h * m21);
        y0 = y0 + 0.5 * h * (m11 + m12);
        y1 = y1 + 0.5 * h * (m21 + m22);
        x0 = x0 + h;
    }
    printf("\n %f\t%f\t%f", x0, y0, y1);
    return;
}
int main()
{
    float x0, yx0, yx1, xp, h;
    char q;
    printf("\n Enter the initial point x: ");
    scanf("%f", &x0);
    printf("\n Enter the value of y_1(x): ");
    scanf("%f", &yx0);
    printf("\n Enter the value of y_2(x): ");
    scanf("%f", &yx1);
    printf("\n Enter the step length: ");
    scanf("%f", &h);
    do
    {
        printf("\n\n Enter the point x at which y(x) is required: ");
        scanf("%f", &xp);
        heun(x0, xp, yx0, yx1, h);
        printf("\n\n Do you want to approximate at another point?(y/n): ");
        scanf(" %c", &q);
    } while (q == 'y');
    return 0;
}
