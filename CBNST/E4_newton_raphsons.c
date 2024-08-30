#include <stdio.h>
#include <math.h>

void details()
{
    printf("Name: Divyansh Dhaundiyal\nSection: D(G1)\nRno: 31\n\nNewton Raphson's Method\n\n");
}

float f(float x)
{
    float eq = (cos(x)) - (x * pow(2.7, x));
    return eq;
}

float df(float x)
{
    float eq = -(sin(x)) - (x * pow(2.7, x)) - pow(2.7, x);
    return eq;
}

void main()
{
    int count = 0;
    float a, b, e;
    float c;

    details();

    printf("Enter the value of guesses (a and b) : ");
    scanf("%f %f", &a, &b);

    printf("\nEnter error : ");
    scanf("%f", &e);
    if (f(a) * f(b) < 0)
    {
        if (fabs(f(a)) < fabs(f(b)))
        {
            a = a;
        }
        else
        {
            a = b;
        }

        printf("\nInitial guess (a) can be defined as : %f", a);

        printf("\n\nIterations\t\tA\t\t\tC\n\n");

        do
        {
            count++;
            c = a - f(a) / df(a);
            printf("%d\t\t\t%f\t%f\n", count, a, c);

            if (a == c)
            {
                break;
            }

            a = c;
        } while (fabs(f(c)) > e);
        printf("\nFinal approximate root after %d iterations is : %f\n", count, c);
    }
    else
    {
        printf("Invalid guess");
    }
}
