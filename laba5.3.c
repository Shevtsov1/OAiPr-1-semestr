#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(int argc, char *argv[])
 {
    setlocale(LC_ALL, "Rus");
	int matr[100][100];
    int i, j, n, m,k;
    do {
        printf("Введите кол-во строк <1000\n");
        scanf("%d", &n);
    } while (n >= 100);
    do {
        printf("Введите кол-во столбцов <100\n");
        scanf("%d", &m);
    } while (n >= 100);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Введите элементы матрицы[%d][%d] ", i+1, j+1);
            scanf("%d", &matr[i][j]);
        }
    }
    printf("\nНачальная матрица:");
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < m; j++) {
            printf("\t %d", matr[i][j]);
        }
    }
    int rowSum;
	int help;

	for ( i = 0; i < n; ++i)
	{
		rowSum = 0;

		for ( j = 0; j < n; ++j)
		{
			rowSum += matr[i][j];
		}

		if(rowSum == 0)
		{
			for ( k = 0; k < n; ++k) matr[k][i] /= 2;
			help = 0;
			break;
		}
		else help = 1;
	}

	if(help == 1) printf("%s\n", "\nМатрица не имеет нулевых строк!");
	else
	{
		printf("%s\n", "\n Матрица после изменений: ");
	for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < m; j++) {
            printf("\t %d", matr[i][j]);
            }
        }
	}
    return 0;
}
