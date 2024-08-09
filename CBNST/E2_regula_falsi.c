#include <stdio.h>
#include <math.h>

void details()
{
    printf("Name: Divyansh Dhaundiyal\nSection: D(G1)\nRno: 31\n\nRegula Falsi Method\n\n");
}

float f(float x)
{
    float eq = (x * x * x) - (2 * x) - 5;
    return eq;
}

void main()
{
    int count = 0;
    float a, b, e;
    float c = (a * f(b) - b * f(a)) / f(b) - f(a);

    details();

    printf("Enter the value of guesses (a and b) : ");
    scanf("%f %f", &a, &b);
    printf("Enter error : ");
    scanf("%f", &e);
    if (f(a) * f(b) < 0)
    {
        printf("\nA\t\tB\t\tC\n\n");
        do
        {
            count++;
            c = (a * f(b) - b * f(a)) / (f(b) - f(a));
            printf("%f\t%f\t%f\n", a, b, c);
            if ((f(a) * f(c)) < 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }

        } while (fabs(f(c)) > e);
        printf("\nFinal approximate root after %d iterations is : %f\n", count, c);
    }
    else
    {
        printf("Invalid guess");
    }
}
