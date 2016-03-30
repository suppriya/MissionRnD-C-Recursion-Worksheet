/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
int *spiraal(int, int, int**, int*,int,int,int);
int *spiral(int rows, int columns, int **input_array)
{
	
	if ((rows > 0) && (columns > 0) && (input_array != NULL))
	{
		int *arr , val, k = 0;
		arr = (int*)malloc(sizeof(int)*((rows+1)*(columns+1)));
		if (rows < columns)
		{
			val = (rows / 2) + (rows % 2);
		}
		else if ((rows == columns) || (rows > columns))
		{
			val = ((columns / 2) + (columns % 2));
		}
		spiraal(rows, columns, input_array,arr,k,0,val);
		return arr;
	}
	
	return NULL;
}

int *spiraal(int rows, int columns, int** input_array, int* arr, int k,int a,int val)
{
	int i, j;
		for (i = k; i < columns -  k; i++)
		{
			arr[a++] = input_array[k][i];
		}
		for (i = k + 1,j=columns-1-k; i < rows - 1 - k; i++)
		{
			arr[a++] = input_array[i][j];
		}
		for (i = columns-1-k, j = rows - 1 - k; i>=k; i--)
		{
			arr[a++] = input_array[j][i];
		}

		for ( i = rows - 2 - k; i >k; i--)
		{
			arr[a++] = input_array[i][k];
		}

	
	 if (k<val-1)
	return spiraal(rows, columns, input_array, arr, k+1, a,val);
	else 
		return arr;
}




		