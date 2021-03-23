#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
 int main() {
 	setlocale(LC_ALL, "Rus");
	int a,b,c;
	printf("Enter a b c: ");
	scanf("%f %f %f", &a, &b, &c);
	if (a==b && b==c) printf ("Треугольник равносторонний\n");
	else 
	if (a!=c) printf ("Треугольник не равносторонний\n");
	system("pause");
	return 0;
}

