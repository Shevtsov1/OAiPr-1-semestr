#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 3

float matrA[SIZE][SIZE], matrB[SIZE], matrX[SIZE], matrC[SIZE][SIZE], matrD[SIZE], matrE[SIZE][SIZE - 2];
void setMatr(float matrA[SIZE][SIZE], float matrB[SIZE], float matrX[SIZE], float matrC[SIZE][SIZE], float matrD[SIZE]);
void viewMatrBegin(float matrA[SIZE][SIZE], float matrB[SIZE], float matrX[SIZE]);
void viewMatr(float matrA[SIZE][SIZE], float matrB[SIZE], float matrX[SIZE], float matrC[SIZE][SIZE], float matrD[SIZE], float matrE[SIZE][SIZE - 2]);
void iterMethod(float matrA[SIZE][SIZE], float matrB[SIZE], float matrX[SIZE], float matrC[SIZE][SIZE], float matrD[SIZE], float matrE[SIZE][SIZE - 2]);

float e = 0.0001;

int main()
{
    setMatr(matrA, matrB, matrX, matrC, matrD);
    viewMatrBegin(matrA, matrB, matrX);
    iterMethod(matrA, matrB, matrX, matrC, matrD, matrE);
    printf("Первый этап\n");
    viewMatr(matrA, matrB, matrX, matrC, matrD, matrE);
}

void setMatr(float matrA[SIZE][SIZE], float matrB[SIZE], float matrX[SIZE], float matrC[SIZE][SIZE], float matrD[SIZE])
{
    printf("Выпишем матрицу коэффициентов\n");
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
        {
            printf("Введите элемент матрицы [%d][%d]: ", i + SIZE - 2, j + SIZE - 2);
            scanf("%f", &matrA[i][j]);
        }
    printf("\n");
    for (int j = 0; j < SIZE; j++)
    {
        printf("Введите элемент матрицы свободных членов [%d]: ", j + SIZE - 2);
        scanf("%f", &matrB[j]);
    }
}

void viewMatrBegin(float matrA[SIZE][SIZE], float matrB[SIZE], float matrX[SIZE])
{
    printf("Матрица коэффициентов:");
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            printf("\t%.2f", matrA[i][j]);
        printf("\n");
    }
    printf("Матрица свободных членов:");
    printf("\n");
    for (int j = 0; j < SIZE; j++)
    {
        printf("\t%.2f", matrB[j]);
        printf("\n");
    }
}

void viewMatr(float matrA[SIZE][SIZE], float matrB[SIZE], float matrX[SIZE], float matrC[SIZE][SIZE], float matrD[SIZE], float matrE[SIZE][SIZE - 2])
{
    printf("Матрица коэффициентов:");
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            printf("\t%.2f", matrC[i][j]);
        printf("\n");
    }
    printf("Матрица свободных членов:");
    printf("\n");
    for (int j = 0; j < SIZE; j++)
    {
        printf("\t%.2f", matrD[j]);
        printf("\n");
    }
}

void iterMethod(float matrA[SIZE][SIZE], float matrB[SIZE], float matrX[SIZE], float matrC[SIZE][SIZE], float matrD[SIZE], float matrE[SIZE][SIZE - 2])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                matrC[i][j] = 0;
            else
                matrC[i][j] = -matrA[i][j] / matrA[i][i];
            matrD[i] = matrB[i] / matrA[i][i];
        }
    printf("\n\nNew vector:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        printf("%.2f", matrD[i]);
    }
    for (int i = 0; i < 3; i++)
        matrX[i] = matrD[i];
    do
    {
        for (int i = 0; i < 3; i++)
        {
            matrX[i] = 0;
            for (int j = 0; j < 3; j++)
            {
                matrX[i] = matrX[i] + matrC[i][j] * matrX[i];
                matrX[i] = matrX[i] + matrD[i];
                matrE[i][j] = fabs(matrX[i] - matrX[i]);
            }
            for (int i = 0; i < 3; i++)
                if (e < matrE[i][j])
                    e = matrE[i][j];

            printf("\n\npogreshnost'=%.2f", matrE[i][j]);
        }
        while (e >= 0.0001);
        printf("\n\nResult:\n");
        for (int i = 0; i < 3; i++)
            printf("\n%.2f", matrX[i]);
    }
}