#include <stdio.h>
#include <math.h>
void details()
{
    printf("Name: Divyansh Dhaundiyal\nSection: D(G1)\nRno: 31\n\nRK Method\n\n");
}
double func(double x, double y)
{
    return (3 * x + y / 2);
}
int main()
{
    details();
    double x0, y0, h, num, k, k1, k2, k3, k4, ans;
    double n;

    printf("Enter x0: ");
    scanf("%lf", &x0);
    printf("Enter y0: ");
    scanf("%lf", &y0);
    printf("Enter h: ");
    scanf("%lf", &h);
    printf("Enter the value of x for which corresponding y is to be found: ");
    scanf("%lf", &num);

    n = (num - x0) / h;

    for (int i = 0; i < n; i++)
    {
        k1 = h * func(x0, y0);
        k2 = h * func(x0 + h / 2, y0 + k1 / 2);
        k3 = h * func(x0 + h / 2, y0 + k2 / 2);
        k4 = h * func(x0 + h, y0 + k3);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        y0 += k;
        x0 += h;

        printf("Step %d: x = %lf, y = %lf, k1 = %lf, k2 = %lf, k3 = %lf, k4 = %lf\n",
               i + 1, x0, y0, k1, k2, k3, k4);
    }
    printf("\nApproximate value of y at x = %.4lf is: %.6lf\n", num, y0);
    return 0;
}