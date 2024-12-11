#include <stdio.h>
void details()
{
    printf("Name: Divyansh Dhaundiyal\nSection: D(G1)\nRno: 31\n\nLagrange's Interpolation Method\n\n");
}
double lagrangeInterpolation(double x[], double y[], int n, double xValue)
{
    double result = 0.0;
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        double term = y[i];
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                term = term * (xValue - x[j]) / (x[i] - x[j]);
            }
        }
        printf("Value = %lf\n", term);
        result += term;
    }
    return result;
}

int main()
{
    details();
    int n;
    printf("Enter number of values\n");
    scanf("%d", &n);
    double x[n], y[n];
    printf("Enter values of x\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &x[i]);
    }
    printf("Enter values of y\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &y[i]);
    }
    double xValue;
    printf("Enter the value of x to interpolate: ");
    scanf("%lf", &xValue);
    double interpolatedValue = lagrangeInterpolation(x, y, n, xValue);
    printf("\nInterpolated value at x = %.2lf is %.2lf\n", xValue, interpolatedValue);
}
