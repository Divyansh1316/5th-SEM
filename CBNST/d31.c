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
	scanf("%d",&size);
	float arr[size][size+1];

		    printf("Enter elements of matrix : ");

	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size+1;j++)
		{
			scanf("%f",&arr[i][j]);	
		}			
	}
	
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size+1;j++)
		{
			printf("%f ",arr[i][j]);	
		}			
		printf("\n");
	}
	
	for(int i=0;i<size;i++)
	{
		if(arr[i][0]!=1)
		{
			int a=arr[i][0];
			for(int j=0;j<size+1;j++)
			{
				arr[i][j]=arr[i][j]/a;
			}
		}
	}	

	printf("\n");	

	for(int i=0;i<size;i++)
	{
		arr[1][i]-=arr[0][i];
		arr[2][i]-=arr[0][i];
	}

	for(int i=1;i<size;i++)
	{
		if(arr[i][1]!=1)
		{
			float a=arr[i][1];
			for(int j=1;j<size+1;j++)
			{
				arr[i][j]=arr[i][j]/a;
			}
		}
	}	
	
	for(int i=0;i<size;i++)
	{
		arr[2][i]-=arr[1][i];
	}
	
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size+1;j++)
		{
			printf("%f ",arr[i][j]);	
		}			
		printf("\n");
	}
}
