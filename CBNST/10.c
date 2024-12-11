#include <stdio.h>
#include <math.h>
void details()
{
    printf("Name: Divyansh Dhaundiyal\nSection: D(G1)\nRno: 31\n\nTrapezoidal Method\n\n");
}
double f(double x)
{
    return 1 / (1 + (x * x));
}
double trapezoidal_rule(double a, double b, int n)
{
    double h = (b - a) / n;
    double x, sum = 0.0;
    x = a + 0 * h;
    printf("x0 = %lf\ty0 = %lf\n", x, f(x));
    for (int i = 1; i < n; i++)
    {
        x = a + i * h;
        sum += f(x);
        printf("x%d = %lf\ty%d = %lf\n", i, x, i, f(x));
    }
    x = a + n * h;
    printf("x6 = %lf\ty6 = %lf\n", x, f(x));

    sum += (f(a) + f(b)) / 2.0;
    return sum * h;
}

int main()
{
    details();
    double a, b;
    int n;

    printf("Enter the lower limit (a): ");
    scanf("%lf", &a);

    printf("Enter the upper limit (b): ");
    scanf("%lf", &b);

    printf("Enter the number of intervals (n): ");
    scanf("%d", &n);

    double integral = trapezoidal_rule(a, b, n);

    printf("The approximate integral value is: %lf\n", integral);

    return 0;
}
