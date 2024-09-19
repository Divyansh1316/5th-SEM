#include <stdio.h>
#include <math.h>

void details()
{
	printf("Name: Divyansh Dhaundiyal\nSection: D(G1)\nRno: 31\n\nGauss Elimination Method\n\n");
}

void main()
{
	details();
	int size;
	printf("Enter size of matrix : ");
	scanf("%d", &size);
	float arr[size][size + 1];

	printf("Enter elements of matrix : \n");

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size + 1; j++)
		{
			scanf("%f", &arr[i][j]);
		}
	}

	printf("\nAugmented matrix :\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size + 1; j++)
		{
			printf("%f ", arr[i][j]);
		}
		printf("\n");
	}

	for (int i = 1; i < size; i++)
	{
		float mul = (arr[i][0] / arr[0][0]);

		for (int j = 0; j < size + 1; j++)
		{
			arr[i][j] = arr[i][j] - mul * arr[0][j];
		}
	}

	printf("\nIntermediate matrix :\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size + 1; j++)
		{
			printf("%f ", arr[i][j]);
		}
		printf("\n");
	}

	for (int i = 2; i < size; i++)
	{
		float mul = (arr[i][1] / arr[1][1]);

		for (int j = 0; j < size + 1; j++)
		{
			arr[i][j] = arr[i][j] - mul * arr[1][j];
		}
	}

	printf("\nUpper Triangular matrix :\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size + 1; j++)
		{
			printf("%f ", arr[i][j]);
		}
		printf("\n");
	}

	int z = arr[size - 1][size] / arr[size - 1][size - 1];

	int y = (arr[size - 2][size] - (z * arr[size - 2][size - 1])) / arr[size - 2][size - 2];

	int x = (arr[size - 3][size] - (z * arr[size - 3][size - 1]) - (y * arr[size - 3][size - 2])) / arr[size - 3][size - 3];

	printf("\nX : %d ", x);
	printf("\nY : %d ", y);
	printf("\nZ : %d ", z);
}
