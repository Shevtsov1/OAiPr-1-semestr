#include <stdio.h>
#include <stdlib.h>

void setMatrSize(int**);
void inputMatrElements(int, int**);
void viewMatr(int**, int);
void rowsPower(int**, int);
void diagonalSum(int**, int);
int sortElements(int*, int);


int main(void)
{
	int **matrValues = NULL;
	
	setMatrSize(matrValues);

	return 0;
}


void setMatrSize(int **matrix)
{
	int rows;
	int matr;
	int i;
	
	printf("%s", "Введите размер квадратной матрицы: ");
	scanf("%d", &rows);

	matr = (int**)malloc(rows * sizeof(int*));
	for ( i = 0; i < rows; ++i)
	{
		matr[i] = (int*)malloc(rows * sizeof(int));
	}

	inputMatrElements(rows, matrix);
}


void inputMatrElements(int rows, int **userElements)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < rows; ++j)
		{
			printf("%s%d-%d\n", "Введите эл-т матрицы: ", i + 1, j + 1);
			scanf("%d", userElements[i]+j);
		}
	}

	viewMatr(userElements, rows);
	rowsPower(userElements, rows);
	diagonalSum(userElements, rows);
}


void viewMatr(int **matrix, int n)
{
	for(int i = 0; i < 71; i++) printf("-%s", (i == 0 || i == 70 ? "\n" : ""));
	for (int i = 0; i < n; ++i)
	{
		printf("\t\v");

		for (int j = 0; j < n; ++j)
		{
			printf("%d\t", *(matrix[i]+j));
		}

		printf("\n");
	}

	printf("\v");

	for(int i = 0; i < 70; i++) printf("-%s", (i == 69 ? "\n" : ""));
}


void rowsPower(int **matrix, int n)
{
	int values[n];
	int helpValue;

	for (int i = 0; i < n; ++i)
	{
		helpValue = 1;
		for (int j = 0; j < n; ++j)
		{
			if(*(matrix[i]+j) < 0) 
			{
				helpValue = -1;
				break;
			}
			else helpValue *= *(matrix[i]+j);
		}
		values[i] = helpValue;
	}

	for (int i = 0; i < n; ++i)
	{
		if(values[i] != -1)
		{
			printf("%s %d - %d\n", "Произведение эл-ов строки", (i + 1), values[i]);
		}
		else printf("%s %d %s\n", "Строка №", (i + 1), "содержит отрицательный эл-т");
	}
}


int sortElements(int *arr, int n)
{
	int j;

	for (int i = 0; i < 2*n-2; ++i)
	{
		j = i;
		for (int k = i; k < 2*n-2; ++k)
		{
			if (*(arr+j) < *(arr+k)) j = k;
		}

		*(arr+i) = *(arr+i) + *(arr+j) - (*(arr+j) = *(arr+i));
	}

	return arr[0];
}


void diagonalSum(int **matrix, int n)
{
	int up[n-1];
	int down[n-1];
	int *values = NULL;
	int p, j;
	int d = n-2;

	for (int i = 0; i < n-1; ++i)
	{
		up[i] = 0;
		down[i] = 0;
	}

	for (int i = 0; i < n-1; ++i)
	{
		j = 0;
		p = n-(i+1);

		while (p != 0)
		{
			up[i] += matr[j][n-p];
			down[i] += matr[n-p][j];

			j++;
			p--;
		}
	}

	values = (int*)malloc((2*n-2) * sizeof(int));
	for (int i = 0; i < n-1; ++i)
	{
		*(values+i) = up[i];
		*(values+(n-i)) = down[i];
	}

	printf("Наибольшая сумма эл-ов диагонали, параллельной главной: %d\n", sortElements(values, n));

}

