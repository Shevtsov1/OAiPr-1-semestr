#include "core.h"

#define SIZE 3

float matA[SIZE][SIZE] = {{1.14, -2.15, -5.11},
                                          {-0.71, 0.81, -0.02},
                                          {0.42, -1.13, 7.05}};

float matB[SIZE] = {-4.16, -0.17, 6.15};

float matX[SIZE], matRes[SIZE];
float beta, e;


int CheckCondition()
{
	int i,j;
    float elementsSum = 0;
    int successCount = 0;

    for ( i = 0; i < SIZE; i++)
    {
        for ( j = 0; j < SIZE; j++)
            if (i != j) elementsSum += fabs(matA[i][j]);

        if (fabs(matA[i][i]) > elementsSum) successCount++;
        elementsSum = 0;
    }

    if (successCount == 3) return 1;
    else return 0;
}


void RowSum(int row1, int row2, float coeff, const int columnsCount)
{
	int i;
    for ( i = 0; i < columnsCount; i++)
        matA[row2][i] += matA[row1][i] * coeff;
        matB[row2] += matB[row1] * coeff;
}


void ShowMatrix(const int rows, const int columns, float matrix[rows][columns])
{
	int i,j;
    for ( i = 0; i < rows; i++)
    {
        printf("\n");
        for ( j = 0; j < columns; j++)
                    printf("%2.2f%s", matrix[i][j], ((j+1)%3==0 ? "\n" : "\t"));
    }
}


void SimpleIterationMethod()
{
	int i,j;
    float elementsSum = 0;
    static int iteration;

    if (iteration != 0) 
        for ( i = 0; i < SIZE; i++)
            matX[i] = matRes[i];
    else
        for ( i = 0; i < SIZE; i++)
            matX[i] = matB[i];
        
    for ( i = 0; i < SIZE; i++)
    {
        for ( j = 0; j < SIZE; j++)
            if (i != j) elementsSum += matA[i][j] * matX[j];

        matRes[i] = (matB[i] - elementsSum) / matA[i][i];
        elementsSum = 0;
    }

    iteration++;
}


int CheckResult()
{
	int i;
    float elementsSum = 0;

    for ( i = 0; i < SIZE; i++)
        elementsSum += fabs(matRes[i] - matX[i]);

    beta = elementsSum / SIZE;

    if (beta <= e) return 1;
    else return 0;
}


int iterrationMethod()
{
	int i;
    printf("¬ведите необходимую точность вычислений: ");
    scanf("%f", &e);

    RowSum(2, 0, 1, SIZE);
    RowSum(1, 0, 9, SIZE);
    RowSum(2, 1, 0.05, SIZE);
    RowSum(1, 0, -2.7, SIZE);
    RowSum(0, 1, -0.2, SIZE);

    do{
        SimpleIterationMethod();
    } while (!CheckResult());
    
    for ( i = 0; i < SIZE; i++)
        printf("x%d = %2.2f\n", i+1, matRes[i]);

    return 0;
}
