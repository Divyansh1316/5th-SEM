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
    float a, b, y, yn = 0.0, x;
    int n;
    printf("Enter x and y : ");
    scanf("%f %f", &x, &y);
    printf("Enter value of x u want to approximate  : ");
    scanf("%f", &b);
    printf("Enter intervals : ");
    scanf("%d", &n);

    float h = (b - x) / n;

    printf("\nIteration\tx\t\ty");
    for (int i = 0; i < n; i++)
    {
        yn = y + h * fn(x, y);
        printf("\n%d\t\t%f\t%f", i + 1, x, y);
        y = yn;
        x = x + h;
    }
    printf("\n%d\t\t%f\t%f", n + 1, x, yn);
    printf("\n\nFinal approximate solution at x = %f : %f", x, yn);
}