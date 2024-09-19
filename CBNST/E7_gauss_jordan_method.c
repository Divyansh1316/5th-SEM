#include <stdio.h>
#include <math.h>

void details()
{
	printf("Name: Divyansh Dhaundiyal\nSection: D(G1)\nRno: 31\n\nGauss Jordan Method\n\n");
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

	for (int i = 0; i < size; i++)
	{
		if (i == 1)
		{
			continue;
		}
		else
		{
			float mul = (arr[i][1] / arr[1][1]);

			for (int j = 0; j < size + 1; j++)
			{
				arr[i][j] = arr[i][j] - mul * arr[1][j];
			}
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

	for (int i = 0; i < size; i++)
	{
		if (i == 2)
		{
			continue;
		}
		else
		{
			float mul = (arr[i][2] / arr[2][2]);

			for (int j = 0; j < size + 1; j++)
			{
				arr[i][j] = arr[i][j] - mul * arr[2][j];
			}
		}
	}

	printf("\nDiagonal matrix :\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size + 1; j++)
		{
			printf("%f ", arr[i][j]);
		}
		printf("\n");
	}

	float z = arr[size - 1][size] / arr[size - 1][size - 1];

	float y = (arr[size - 2][size] - (z * arr[size - 2][size - 1])) / arr[size - 2][size - 2];
	
	float x = (arr[size - 3][size] - (z * arr[size - 3][size - 1]) - (y * arr[size - 3][size - 2])) / arr[size - 3][size - 3];
	
	printf("\nX : %f ", x);
	printf("\nY : %f ", y);
	printf("\nZ : %f ", z);
}
