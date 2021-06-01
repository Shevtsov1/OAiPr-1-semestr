#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SIZE 10

struct Table;

struct Table
{
    int key;
    int value;
} p[SIZE];

int AddTable()
{
    srand(time(NULL));
    int n = sizeof(p) / sizeof(p[0]);
    for (int i = 0; i < n; i++)
    {
        int valuer = rand() % 100;
        p[i].value = valuer;
    }
}

int HashFunction()
{
    int n = sizeof(p) / sizeof(p[0]);
    for (int i = 0; i < n; i++)
    {
        int tmp = pow(p[i].value, 3);
        if (tmp > 100)
            tmp /= 1000;
        else
            tmp /= 10;
        p[i].key = tmp % SIZE;
    }
}

int CheckResult()
{
    int n = sizeof(p) / sizeof(p[0]);
    int counter = 0;
    do
    {
        for (int i = 0; i < n; i++)
            if (p[i].key != p[i + 1].key)
                return 1;
            else
                return 0;
                counter++;
    } while (counter <= 100);
}

int NormolizeTable()
{
    int n = sizeof(p) / sizeof(p[0]);
    do
    {
        for (int i = 0; i < n; i++)
            if (p[i].key == p[i + 1].key)
                p[i + 1].key += 1;
    } while (!CheckResult);
}

void PrintTable()
{
    int n = sizeof(p) / sizeof(p[0]);
    for (int i = 0; i < n; i++)
        printf("value:%d \t key:%d \n", p[i].value, p[i].key);
}

int TableSort()
{
    int n = sizeof(p) / sizeof(p[0]);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].key > p[j + 1].key)
            {
                int tmp = p[j].key;
                p[j].key = p[j + 1].key;
                p[j + 1].key = tmp;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    AddTable();
    HashFunction();
    printf("Non-sorted Table:\n");
    PrintTable();
    TableSort();
    NormolizeTable();
    TableSort();
    NormolizeTable();
    TableSort();
    NormolizeTable();
    TableSort();
    printf("Sorted Table:\n");
    PrintTable();
    return 0;
}