#include <stdio.h>
#define MAX 10
void details()
{
    printf("Name: Divyansh Dhaundiyal\nSection: D(G1)\nRno: 31\n\nLeast Square Approximation Method\n\n");
}
void gaussJordan(float mat[MAX][MAX], int n, float result[])
{
    int i, j, k;
    float temp;
    for (i = 0; i < n; i++)
    {
        temp = mat[i][i];
        for (j = 0; j <= n; j++)
            mat[i][j] /= temp;
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                temp = mat[j][i];
                for (k = 0; k <= n; k++)
                    mat[j][k] -= temp * mat[i][k];
            }
        }
    }
    for (i = 0; i < n; i++)
        result[i] = mat[i][n];
}
int main()
{
    details();
    int n, i;
    float x[MAX], y[MAX], a, b;
    float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    printf("Enter the number of data points (max %d): ", MAX);
    scanf("%d", &n);
    printf("Enter the values of x and y:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] y[%d]: ", i + 1, i + 1);
        scanf("%f %f", &x[i], &y[i]);
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }
    float mat[MAX][MAX] = {0};
    mat[0][0] = n;
    mat[0][1] = sumX;
    mat[0][2] = sumY;
    mat[1][0] = sumX;
    mat[1][1] = sumX2;
    mat[1][2] = sumXY;
    printf("\nNormal Equations:\n");
    printf("%.2f * a + %.2f * b = %.2f\n", mat[0][0], mat[0][1], mat[0][2]);
    printf("%.2f * a + %.2f * b = %.2f\n", mat[1][0], mat[1][1], mat[1][2]);
    float result[2];
    gaussJordan(mat, 2, result);
    a = result[0];
    b = result[1];
    printf("\nMethod used: Gauss-Jordan\n");
    printf("\nValues of a and b:\n");
    printf("a = %.4f\n", a);
    printf("b = %.4f\n", b);
    printf("\nThe final equation is:\n");
    printf("y = %.4f + %.4f * x\n", a, b);
    return 0;
}
