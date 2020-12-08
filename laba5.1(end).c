#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
    int matr[50][50];
    int i, j, n, m;
    do {
        printf("Введите кол-во строк <50\n");
        scanf("%d", &n);
    } while (n >= 50);
    do {
        printf("Введите кол-во столбцов <50\n");
        scanf("%d", &m);
    } while (n >= 50);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Введите элементы матрицы[%d][%d] ", i+1, j+1);
            scanf("%d", &matr[i][j]);
        }
    }
    printf("\nНачальная матрица :");
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < m; j++) {
            printf("\t %d", matr[i][j]);
        }
    }
    printf("\n");
    int nomer, k;
    int nom[50];
    for (i = 0, k=0; i < n, k < n; i++, k++) {
        nomer = 0;
        for (j = 0; j < m; j++) {
            if (matr[i][j] == 0) {
                nomer++;
            }
        }
        nom[k] = nomer;
    }
    for (k = 0; k < n; k++) {
        printf("\n");
        printf("Число нулевых эл-ов в строке %d ", nom[k]);
    }
    for (k = 0; k < n; k++) {
        if (nom[k] == 0) {
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        if (matr[i][j] < 0) {
                            matr[i][j] = 0;
                        }
                    }
                }
        }
    }
    printf("Матрица после замены: \n");
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < m; j++) {
            printf("\t %d ", matr[i][j]);
        }
    }
}
