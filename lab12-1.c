#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Table HashTable;

struct Table
{
    int key;
    int value;
    HashTable *next;
};

void AddTable(HashTable **l, int key, int value) {
    HashTable *newElem = (HashTable*)malloc(sizeof(HashTable));
    newElem->next = *l;
    newElem->key = key;
    newElem->value = value;
    *l = newElem;
}

void PrintTable(HashTable* p, int key, int value)
{
    printf("Sorted Hash Table:\n");
    for (int i)
    {
        printf("key: %d", key[i]);
        printf("\t");
        printf("value: %d", value[i]);
        printf("\n");
    }
}

HashTable* TableSort(HashTable *p, int key) {
    for (; p != NULL; p = p->next) {
        if (p->key == key) {
            printf("key: %d\t val: %d\n", p->key, p->val);
            return p;
        }
    }
    return NULL;
}

}

int main()
{
    HashTable *table = NULL;
    int keyr, valuer, minkey = 100, size;
    printf("Enter size of table: ");
    scanf("%d", &size);
    printf("\n");
    int i;
    srand(time(NULL));
    for (i = 0; i < size; ++i) {
        keyr = rand() % 10;
        valuer = rand() % 100;
        AddTable(&table, keyr, valr);
        if (keyr < minkey) minkey = keyr;
    }
    TableSort();
}