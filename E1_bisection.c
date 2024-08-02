#include <stdio.h>
#include <math.h>

void details()
{
    printf("Name: Divyansh Dhaundiyal\nSection: D(G1)\nRno: 31\n\n");
}

float f(float x)
{
    float eq = (x * x * x) - (2 * x) - 5;
    return eq;
}

void main()
{
    float x0, x1, e;
    float x2 = (x0 + x1) / 2;

    details();

    printf("Enter 1st and second initial guesses : ");
    scanf("%f %f", &x0, &x1);
    printf("Enter error : ");
    scanf("%f", &e);
    if (f(x0) * f(x1) < 0)
    {
        printf("x0\t\tx1\t\tx2\n\n");
        do
        {
            x2 = (x0 + x1) / 2;
            printf("%f\t%f\t%f\n", x0, x1, x2);
            if ((f(x0) * f(x2)) < 0)
            {
                x1 = x2;
            }
            else
            {
                x0 = x2;
            }

        } while (fabs(f(x2)) > e);
        printf("Final approximate root is : %f\n", x2);
    }
    else
    {
        printf("Invalid guess");
    }
}
