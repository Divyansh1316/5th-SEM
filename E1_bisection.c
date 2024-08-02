#include <stdio.h>
#include <math.h>

void n()
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

    n();

    printf("Enter x0 and x1 : ");
    scanf("%f %f", &x0, &x1);
    printf("Enter error : ");
    scanf("%f", &e);
    if (f(x0) * f(x1) < 0)
    {
        do
        {
            x2 = (x0 + x1) / 2;
            if ((f(x0) * f(x2)) < 0)
            {
                x1 = x2;
            }
            else
            {
                x0 = x2;
            }
            printf("Root is : %f\n", x2);

        } while (fabs(f(x2)) > e);
    }
    else
    {
        printf("Invalid guess");
    }
}
