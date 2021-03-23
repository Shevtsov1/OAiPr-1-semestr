#include<stdio.h>
#include <locale.h>
int main()
{
    int i;
    setlocale(LC_ALL, "Russian");
    for (i = 401; i < 500; i++)
        if (i % 10 + i / 10 % 10 + i / 100 == 9 && (i % 10 * 100 + i / 10 % 10 * 10 + i / 100) / 36 * 47 == i)
        printf("Это число: %d\n", i);
        return 0;
}

