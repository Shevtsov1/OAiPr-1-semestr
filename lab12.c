#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct info_t
{
    int value;
    bool use;
} TInfo;

TInfo* GetTable(size_t size)
{
    return (TInfo*)calloc(size, sizeof(TInfo));
}

size_t GetHashKey(size_t size, int value)
{
    return value % size;
}

size_t GetNextKey(size_t size, int key)
{
    return ++key == size ? 0 : key;
}

bool AddToTable(TInfo table[], size_t size, int value)
{
    int secondKey = GetHashKey(size, value);
    int baseKey = secondKey;
    bool isAdd;

    while (table[baseKey].use && ((baseKey = GetNextKey(size, baseKey)) != secondKey))
    {
        ;
    }

    isAdd = (table[baseKey].use == false);

    if (isAdd)
    {
        table[baseKey].value = value;
        table[baseKey].use = true;
    }
    return isAdd;
}

void PrintTable(TInfo table[], size_t size, bool all)
{
    size_t i;
    for (i = 0; i < size; ++i)
    {
        if (all || table[i].use)
        {
            printf("[%u:%d] ", i, table[i].value);
        }
    }
    printf("\n");
}

int GetValue(TInfo table[], size_t size, int value, size_t *counter)
{
    size_t count = 0;

    int secondKey = GetHashKey(size, value);
    int baseKey = secondKey;

    while (table[baseKey].use && table[baseKey].value != value && ((baseKey = GetNextKey(size, baseKey) != secondKey)))
    {
        count++;
    }

    if ((table[baseKey].use) && (table[baseKey].value == value))
    {
        count++;
    }
    else
    {
        count = 0;
    }

    if (counter)
    {
        *counter = count;
    }

    return count ? baseKey : -1;
}

void LoadTable(FILE *f, TInfo table[], size_t size, size_t count)
{
    int value;
    while ((count--) && (fscanf(f, "%d", &value) == 1))
    {
        if (AddToTable(table, size, value) == false)
        {
            fprintf(stderr, "eror: value %d not added ...\n", value);
        }
    }
}

int SortTable(FILE *f, TInfo table[], size_t size, int basekey){

            if (basekey > basekey->next)
            {
                int tmp = basekey;
                basekey = basekey;
                basekey = tmp;
            }
}

int main()
{
    const char CFile[] = "file.txt";

    const size_t size = 20;

    TInfo *table = GetTable(size);

    FILE *f = fopen(CFile, "r");
    if (f == NULL)
    {
        perror(CFile);
        return EXIT_FAILURE;
    }

    LoadTable(f, table, size, 15);

    fclose(f);

    printf("only used elemets: ");
    PrintTable(table, size, false);
    printf("\n");

    printf("all elements: ");
    PrintTable(table, size, true);
    printf("\n");

    int value, key;
    size_t count;

    printf("find value: ");
    scanf("%d", &value);

    if ((key = GetValue(table, size, value, &count)) != -1)
    {
        printf("key %d, attempt %zu\n", key, count);
    }
    else
    {
        fprintf(stderr, "value %d not found ...\n", value);
    }

    return EXIT_SUCCESS;
}