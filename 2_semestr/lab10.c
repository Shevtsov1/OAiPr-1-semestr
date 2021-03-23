#include <stdio.h>
#include <math.h>

float matr[100][100];
void setMatr(float matr[100][100], int n1, int m1);
void viewMatr(float matr[100][100], int n1, int m1);
void matrToTringle(float matr[100][100], int n1, int m1);
void viewTringleMatr(float matr[100][100], int n1, int m1);
void findingRoots(float matr[100][100], int n1, int m1);

int main(void)
{
	int x, n, m;
	printf("Введите кол-во уравнений: ");
	scanf("%d", &n);
	printf("Введите кол-во неизвестных: ");
	scanf("%d", &x);
	m = x + 1;
	setMatr(matr, n, m);
	viewMatr(matr, n, m);
	matrToTringle(matr, n, m);
	viewTringleMatr(matr, n, m);
	findingRoots(matr, n, m);
}

void setMatr(float matr[100][100], int n1, int m1)
{
	printf("Выпишем расширенную матрицу\n");
	int i, j;
	for (i = 0; i < n1; i++)
		for (j = 0; j < m1; j++)
		{
			printf("Введите элемент матрицы [%d][%d]: ", i + 1, j + 1);
			scanf("%f", &matr[i][j]);
		}
}

void viewMatr(float matr[100][100], int n1, int m1)
{
	printf("Матрица:");
	int i, j;
	printf("\n");
	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < m1; j++)
			printf("\t%.2f", matr[i][j]);
		printf("\n");
	}
}

void matrToTringle(float matr[100][100], int n1, int m1)
{
	int k, i, j;
	for (k = 0; k < n1; k++)
	{
		if (fabs(matr[k][k]) < 0.0001)
		{
			printf("Система не имеет единственного решения");
		}
		for (j = m1; j >= 0; j--)
		{

			matr[k][j] /= matr[k][k];
		}
		for (i = k + 1; i < n1; i++)
		{
			for (j = m1; j >= k; j--)
			{
				matr[i][j] -= matr[k][j] * matr[i][k];
			}
		}
	}
}

void viewTringleMatr(float matr[100][100], int n1, int m1)
{
	printf("Ступенчатая матрица:");
	int i, j;
	printf("\n");
	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < m1; j++)
			printf("\t%.2f", matr[i][j]);
		printf("\n");
	}
}

void findingRoots(float matr[100][100], int n1, int m1)
{
	int i, j, k;
	float x[100];
	int format[100];
	i = format[k];
	format[k] = format[m1];
	format[m1] = i;
	for (i = 0; i < n1; i++)
		x[i] = matr[i][n1];
	for (i = n1 - 2; i >= 0; i--)
		for (j = i + 1; j < m1; j++)
			x[i] -= x[j] * matr[i][j];
	printf("Ответ:\n");
	for (j = 0; j < m1-1; j++)
	{
		for (i = 0; i < n1; i++)
		{
			printf("x[%d]: %.2f\n", j+1, x[j]);
			break;
		}
	}
}