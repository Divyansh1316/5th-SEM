#include <stdio.h>
#include <math.h>

void details()
{
    printf("Name: Divyansh Dhaundiyal\nSection: D(G1)\nRno: 31\n\nNewton's Forward Interpolation Method\n\n");
}
int fact(int x)
{
    if (x == 0 || x == 1)
        return 1;
    else
        return x * fact(x - 1);
}
float u_value(float u, int x)
{
    if (x == 0)
        return 1;
    if (x == 1)
        return u;
    else
    {
        float answ = u;
        for (int i = 1; i < x; i++)
        {
            answ *= (answ - i);
        }
        return answ;
    }
}
int main()
{
    int size;
    details();
    printf("Enter the number of arguments :");
    scanf("%d", &size);
    int point;
    printf("\nEnter the value of x :");
    scanf("%d", &point);
    int x[size];
    int y[size];
    printf("\nEnter years and population :\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
    }

    int diff = x[1] - x[0];
    int c = 1;
    for (int i = 1; i < size - 1; i++)
    {
        int diffCal = x[i + 1] - x[i];
        if (diffCal == diff)
        {
            c++;
        }
    }
    if (c == size - 1 && (point > x[0] && point < x[1]))
    {
        int op[size][size];
        for (int a = 0; a < size; a++)
        {
            for (int b = 0; b < size; b++)
            {
                op[a][b] = 0;
            }
        }

        int csize = size - 1;
        int ny[size];
        int fx[size];
        for (int i = 0; i < size; i++)
        {
            ny[i] = y[i];
            op[0][i] = y[i];
        }
        int k = 0;
        fx[0] = ny[0];

        int np = 0;

        while (csize != 0)
        {
            int arr[csize];
            ++np;
            for (int i = 0; i < csize; i++)
            {
                arr[i] = ny[i + 1] - ny[i];
                op[np][i] = arr[i];
            }
            fx[++k] = arr[0];

            for (int i = 0; i < csize; i++)
            {
                ny[i] = arr[i];
            }
            csize--;
        }
        printf("\n\nYears\tPopulation\n");
        for (int a = 0; a < size; a++)
        {
            printf("%d\t", x[a]);
            for (int b = 0; b < size; b++)
            {
                if (op[b][a])
                {
                    printf("%d\t", op[b][a]);
                }
            }
            printf("\n");
        }

        printf("\n");
        float answ = 0;
        float u = (float)(point - x[0]) / diff;
        // printf("%f\n\n", u);
        for (int i = 0; i < size; i++)
        {
            answ += (fx[i] * u_value(u, i)) / fact(i);
        }
        printf("Population at %d =%f\n", point, answ);
    }
    else
    {
        printf("Inavlid Input \n");
    }

    return 0;
}
