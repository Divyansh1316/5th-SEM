#include <stdio.h>
#include <math.h>

void details()
{
    printf("Name: Divyansh Dhaundiyal\nSection: D(G1)\nRno: 31\n\nIteration Method\n\n");
}

float f(float x)
{
    float eq = cos(x) - (3 * x) + 1;
    return eq;
}

float f2(float x)
{
    float eq = (cos(x) + 1) / 3;
    return eq;
}

float f3(float x)
{
    float eq = acos((3 * x) - 1);
    return eq;
}

float df2(float x)
{
    float eq = -sin(x) / 3;
    return eq;
}

float df3(float x)
{
    float eq = -3 / (pow(1 - pow((3 * x) - 1, 2), 0.5));
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

        if (fabs(df2(a)) < 1 || fabs(df3(a)) < 1 && fabs(df2(a)) < fabs(df3(a)))
        {
            printf("\n\nO'(x) is : %f", fabs(df2(a)));

            printf("\n\nEquation is : x = (cos(x) + 1) / 3");

            int count = 0;
            float c;

            printf("\n\nIterations\t\tXn\n\n");

            do
            {
                count++;

                c = f2(a);
                printf("x%d\t\t\t%f\n", count, c);

                if (a == c)
                {
                    break;
                }

                a = c;
            } while (fabs(f(c)) > e);
            printf("\nFinal approximate root after %d iterations is : %f\n", count, c);
        }
        else if (fabs(df2(a)) < 1 || fabs(df3(a)) < 1 && fabs(df2(a)) > fabs(df3(a)))
        {
            int count = 0;
            float c;

            printf("\n\nO'(x) is : %f", fabs(df3(a)));

            printf("\n\nEquation is : x = acos((3 * x) - 1)");

            printf("\n\nIterations\t\tC\n\n");

            do
            {
                count++;

                c = f3(a);
                printf("x%d\t\t\t%f\n", count, c);

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
            printf("\nRegulatory condition not satisfied");
        }
    }
    else
    {
        printf("Invalid guess");
    }
}
