#include<stdio.h>
#include<conio.h>
#include<locale.h>


int main()
{
	setlocale(LC_ALL, "Rus");
 int matr[100][100];
    int i, j, n;
    do {
        printf("Введите кол-во строк и столбцов матрицы <100: ");
        scanf("%d", &n);
    } while (n >= 100);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Введите эл-т матрицы[%d][%d]: ", i+1, j+1);
            scanf("%d", &matr[i][j]);
        }
    }
    printf("\n Матрица :");
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < n; j++) {
            printf("\t %d", matr[i][j]);
        }
    }
    puts("");
    //Произведение эл-ов строк
    {
	int p[n];
	int help;

	for ( i = 0; i < n; ++i)
	{
		help = 1;
		for ( j = 0; j < n; ++j)
		{
			if(matr[i][j] < 0) 
			{
				help = -1;
				break;
			}
			else help *= matr[i][j];
		}
		p[i] = help;
	}

	for ( i = 0; i < n; ++i)
	{
		if(p[i] != -1)
		{
			printf("%s %d - %d\n", "Произведение эл-ов строки №", (i + 1), p[i]);
		}
		else printf("%s %d %s\n", "Cтрока №", (i + 1), "сожерит отрицательный элмемент");
		 }
    }
    int SORT_ELEMENTS(int arr[100], int n)
{
	int j,k;

	for ( i = 0; i < 2*n-2; ++i)
	{
		j = i;
		for ( k = i; k < 2*n-2; ++k)
		{
			if (arr[j] < arr[k]) j = k;
		}

		arr[i] = arr[i] + arr[j] - (arr[j] = arr[i]);
	}

	return arr[0];
}
	int up[n-1];
	int down[n-1];
	int values[100];
	int p;
	int d = n-2;

	for ( i = 0; i < n-1; ++i)
	{
		up[i] = 0;
		down[i] = 0;
	}

	for ( i = 0; i < n-1; ++i)
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

	for ( i = 0; i < n-1; ++i)
	{
		values[i] = up[i];
		values[n-i] = down[i];
	}

	printf("Наибольшая сумма элементов диагонали, параллельной главной: %d\n", SORT_ELEMENTS(values, n));

	return 0;
}
