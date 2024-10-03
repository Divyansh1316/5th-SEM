#include <stdio.h>
#include <math.h>

void details()
{
    printf("Name: Divyansh Dhaundiyal\nSection: D(G1)\nRno: 31\n\nSecant Method\n\n");
}

float f(float x)
{
    float eq = (x * x * x) - (5 * x) + 1;
    return eq;
}

void main()
{
    int i = 0, n, flag;
    float a, b, e;
    float c = (a * f(b) - b * f(a)) / f(b) - f(a);

    details();

    printf("Enter the value of guesses (a and b) : ");
    scanf("%f %f", &a, &b);
    printf("Enter error : ");
    scanf("%f", &e);
    printf("Enter number of iterations : ");
    scanf("%d", &n);

    if ((f(a) * f(b)) > 0)
    {
        printf("Invalid guess");
    }
    else
    {
        printf("\nA\t\tB\t\tC\n\n");
        do
        {

            i++;
            c = (a * f(b) - b * f(a)) / (f(b) - f(a));

            printf("%f\t%f\t%f\n", a, b, c);

            a = b;
            b = c;

        } while (fabs(f(c)) > e && i < n);
        if (fabs(f(c)) <= e)
        {
            printf("\nFinal approximate root after %d iterations is : %f\n", i, c);
        }
        else
        {
            printf("\nMaximum iterations reached, approximate root not converged");
        }
    }
}
