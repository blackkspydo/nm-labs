// 5. Write an algorithm and computer program to fit a curve y = ax2 + bx + c for given sets of (xi, yi, g. 0 = 1, ..., x) values by least square method. (4+8)#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define MAX_POINTS 100

int main()
{
    int n, i, j;
    double x[MAX_POINTS], y[MAX_POINTS], a, b, c, sum_x = 0, sum_y = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0, sum_xy = 0, sum_x2y = 0, det, det_a, det_b, det_c;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the data points (x, y):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);
        sum_x += x[i];
        sum_y += y[i];
        sum_x2 += pow(x[i], 2);
        sum_x3 += pow(x[i], 3);
        sum_x4 += pow(x[i], 4);
        sum_xy += x[i] * y[i];
        sum_x2y += pow(x[i], 2) * y[i];
    }

    det = n * (sum_x2 * sum_x4 - sum_x3 * sum_x3) - sum_x * (sum_x * sum_x4 - sum_x2 * sum_x3) + sum_x2 * (sum_x * sum_x3 - sum_x2 * sum_x2);
    det_a = sum_y * (sum_x2 * sum_x4 - sum_x3 * sum_x3) - sum_x * (sum_xy * sum_x4 - sum_x3 * sum_x2y) + sum_x2 * (sum_xy * sum_x3 - sum_x2y * sum_x2);
    det_b = n * (sum_xy * sum_x4 - sum_x3 * sum_x2y) - sum_y * (sum_x * sum_x4 - sum_x2 * sum_x3) + sum_x2 * (sum_x * sum_x2y - sum_xy * sum_x2);
    det_c = n * (sum_x2 * sum_x2y - sum_xy * sum_x3) - sum_x * (sum_x * sum_x2y - sum_xy * sum_x2) + sum_y * (sum_x * sum_x3 - sum_x2 * sum_x2);

    a = det_a / det;
    b = det_b / det;
    c = det_c / det;

    printf("The curve is y = %gx^2 + %gx + %g\n", a, b, c);

    return 0;
}
