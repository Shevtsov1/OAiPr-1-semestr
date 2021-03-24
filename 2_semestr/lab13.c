#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int setMas(int mas[100], int n);
int sortNegElem(int mas[100], int n);
int sortPosElem(int mas[100], int n);

int main(void)
{
    int mas[100], n;
    n = setMas(mas, n);
    sortNegElem(mas, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", mas[i]);
    }
    printf("\n");
    return 0;
}

int setMas(int mas[100], int n)
{
    int i;
    printf("Введите размер массива(до 100): ");
    scanf("%d", &n);
    printf("\nЗаданный массив: \n");
    for (i = 0; i < n; i++)
    {
        mas[i] = rand() % 101 - 50;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", mas[i]);
    }
    printf("\n");
    return n;
}

int sortNegElem(int mas[100], int n)
{
    int help = 1;
    while (help == 1)
    {
        help = 0;
        for (int i = 0; i < n; i++)
        {
            if (mas[i] > mas[i + 1])
            {
                int arg = mas[i + 1];
                mas[i + 1] = mas[i];
                mas[i] = arg;
                help = 1;
            }
            else
            {
                ;
            }
        }
    }
}

int sortPosElem(int mas[100], int n)
{
    int help = 1;
    while (help == 1)
    {
        help = 0;
        for (int i = 0; i < n; i++)
        {
            if (mas[i] > 0)
            {
                if (mas[i] < mas[i + 1])
                {
                    int arg = mas[i + 1];
                    mas[i + 1] = mas[i];
                    mas[i] = arg;
                    help = 1;
                }
                else
                {
                    ;
                }
            }
            else
            {
                ;
            }
        }
    }
}