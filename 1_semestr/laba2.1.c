#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
 int main() {
 	setlocale(LC_ALL, "Rus");
	int a,b,c;
	printf("Enter a b c: ");
	scanf("%f %f %f", &a, &b, &c);
	if (a==b && b==c) printf ("����������� ��������������\n");
	else 
	if (a!=c) printf ("����������� �� ��������������\n");
	system("pause");
	return 0;
}

