#include <stdio.h>
#include <malloc.h>
#include <locale.h>

int getMassLenght();
void getMassElements(int*);
void positiveElements(int*, int);
void sumElements(int*, int);

int main(void)
{
	setlocale(LC_ALL, "Rus");
	int *num;
	getMassElements(num);
	return 0;
}


int getMassLenght()
{
	int lenght;
	printf("%s\n", "������� ����� ��-�� �������: ");
	scanf("%d", &lenght);
	return lenght;
}


void getMassElements(int *arr)
{
	int i;
	int n = getMassLenght();
	arr = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; ++i)
	{
		printf("������� %d ��-� �������\n", i+1);
		scanf("%d", (arr + i));
	}

	positiveElements(arr, n);
	sumElements(arr, n);
}


void positiveElements(int *arr, int n)
{
	int i;
	int positiveCount = 0;
	for ( i = 0; i < n; ++i)
	{
		if(*(arr+i) > 0) positiveCount++;
	}

	printf("���-�� ������������� ��-�� ������� = %d\n", positiveCount);
}


void sumElements(int *arr, int n)
{
    int i;
	int sum = 0;
	for ( i = 0; i < n; ++i)
	{
		sum += *(arr+i);
		if(sum == sum - *(arr+i)) sum = 0;
	}

	printf("����� ��-�� ������� ������� ����� ���������� ���� =  %d\n", sum);
}
