#include <stdio.h>
#include <math.h>

void details()
{
    printf("Name: Divyansh Dhaundiyal\nSection: D(G1)\nRno: 31\n\nNewton's Backward Interpolation Method\n\n");
}

int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

float succ_add(float u, int n)
{
    float ans = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans = ans * (u + i);
    }
    return ans;
}

int main()
{
    details();

    int size, pt, c = 1;
    printf("Enter the number of unknowns : ");
    scanf("%d", &size);
    int y[size], p[size];

    printf("Enter year and population :\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d %d", &y[i], &p[i]);
    }

    int p_new = y[size - 1];

    int diff = y[1] - y[0];
    for (int i = 1; i < size - 1; i++)
    {
        int diff_cal = y[i + 1] - y[i];
        if (diff == diff_cal)
        {
            c++;
        }
    }

    printf("Enter calculating point : ");
    scanf("%d", &pt);

    if (c == size - 1 && pt >= y[size - 2] && pt <= y[size - 1])
    {
        printf("\nYear Population\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d %d", y[i], p[i]);
            printf("\n");
        }

        printf("\n");
        int fx[size - 1];
        int max[size];
        int num = size;

        max[0] = p[size - 1];
        for (int i = 0; i < num - 1; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                fx[j] = p[j + 1] - p[j];
                printf("%d ", fx[j]);
            }
            max[i + 1] = fx[size - 2];
            for (int k = 0; k < size - 1; k++)
            {
                p[k] = fx[k];
            }
            size--;
            printf("\n");
        }

        // printf("\n");
        // for (int i = 0; i < num; i++)
        // {
        //     printf("%d ", max[i]);
        // }

        float u = (float)(pt - p_new) / diff;
        // printf("\n\nU is : %f", u);

        float ans;
        for (int i = num - 1; i >= 0; i--)
        {
            ans += (max[i] * succ_add(u, i)) / fact(i);
        }
        printf("\nFinal f(calculating point) : %f", ans);
    }
    else
    {
        printf("Unequal intervals");
    }
}