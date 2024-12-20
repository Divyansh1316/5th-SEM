#include <stdio.h>
#include <math.h>

#define S 50
int main()
{
    int n, i;
    float x[S], y[S], sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0, a, b;
    printf("Enter the number of data points (n): ");
    scanf("%d", &n);
    printf("Enter data:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = ", i + 1);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i + 1);
        scanf("%f", &y[i]);
    }
    for (i = 0; i < n; i++)
    {
        sumX += x[i];
        sumX2 += x[i] * x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
    }
    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a = (sumY - b * sumX) / n;
    printf("Values are: a = %0.2f and b = %0.2f\n", a, b);
    printf("Equation of best fit is: y = %0.2f + %0.2fx\n", a, b);
    return 0;
}