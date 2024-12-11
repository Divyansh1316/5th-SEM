#include <stdio.h>

void details()
{
    printf("Name: Divyansh Dhaundiyal\nSection: D(G1)\nRno: 31\n\nEuler's Method\n\n");
}

float fn(float x, float y)
{
    float eq = x + y;
    return eq;
}

void main()
{
    details();
    float n, a, b, y = 1.0, yn = 0.0, x = 0.0;
    printf("Enter a and b : ");
    scanf("%f %f", &a, &b);
    printf("Enter intervals : ");
    scanf("%f", &n);

    float h = (b - a) / n;

    printf("\nIteration\tx\t\ty");
    for (int i = 0; i < n; i++)
    {
        yn = y + h * fn(x, y);
        printf("\n%d\t\t%f\t%f", i + 1, x, yn);
        y = yn;
        x = x + h;
    }
    printf("\n\nFinal approximate solution at x = %f : %f", x, yn);
}