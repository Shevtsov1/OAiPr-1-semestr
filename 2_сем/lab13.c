#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void setMas(int *mas, int n);
void masSort(int *mas6, int n);

int main(void)
{
    int *mas, n;
    setMas(mas, n);
    masSort(mas, n);
}

void setMas(int *mas, int n)
{
    int i;
    printf("Введите размер массива: \n");
    scanf("%d", &n);
    srand(time(NULL));
    mas = malloc(n * sizeof(int));
    printf("Заданный массив: \n");
    for (i = 0; i < n; i++)
    {
        mas[i] = rand() % 101 - 50;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", mas[i]);
    }
    printf("\n");
}

void masSort(int *mas, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (mas[i] < 0, mas[i + 1] < 0)
        {
            if (mas[i] > mas[i + 1])
            {
                int arg = mas[i + 1];
                mas[i + 1] = mas[i];
                mas[i] = arg;
            }
        }
        else
        {
            ;
        }
    }
}