#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int setMas(int mas[100], int masEnd[100], int n);
int sortMas(int mas[100], int masEnd[100], int n);
int sortNegElem(int mas[100], int masEnd[100], int n);
int sortPosElem(int mas[100], int masEnd[100], int n);

int main(void)
{
    int mas[100], masPos[100], masNeg[100], masEnd[100], n;
    n = setMas(mas, masEnd, n);
    sortMas(mas, masEnd, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", masEnd[i]);
    }
    printf("\n");
    return 0;
}

int setMas(int mas[100], int masEnd[100], int n)
{
    int i;
    srand(time(NULL));
    printf("Введите размер массива(до 100): ");
    scanf("%d", &n);
    printf("\nЗаданный массив: \n");
    for (i = 0; i < n; i++)
    {
        mas[i] = rand() % 101 - 50;
        masEnd[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", mas[i]);
    }
    printf("\n");
    return n;
}

int sortMas(int mas[100], int masEnd[100], int n)
{
        for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mas[i] >= 0 && mas[j] >= 0)
            {
                if (mas[i] < mas[j])
                {
                    int tmp = mas[i];
                    mas[i] = mas[j];
                    mas[j] = tmp;
                }
            }
        }
    }
    sortNegElem(mas, masEnd, n);
    sortPosElem(mas, masEnd, n);
}

int sortNegElem(int mas[100], int masEnd[100], int n)
{
    int countNeg = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] < 0)
            countNeg++;
    }

    if (!countNeg)
    {
        printf("Array has no negative elements\n");
        return 0;
    }

    masEnd[countNeg];

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] < 0)
        {
            masEnd[k] = mas[i];
            k++;
        }
        else
        {
            ;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (masEnd[j] > masEnd[j + 1])
            {
                int tmp = masEnd[j];
                masEnd[j] = masEnd[j + 1];
                masEnd[j + 1] = tmp;
            }
        }
    }
}

int sortPosElem(int mas[100], int masEnd[100], int n)
{
    int countNeg = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] < 0)
            countNeg++;
    }
    int countPos = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] >= 0)
            countPos++;
    }

    if (!countPos)
    {
        printf("Array has no positive elements\n");
        return 0;
    }

    masEnd[countPos + countNeg];

    int help;
    help = n - countPos;
    int k = help;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] >= 0)
        {
            masEnd[k] = mas[i];
            k++;
        }
        else
        {
            ;
        }
    }
}