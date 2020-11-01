#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
 int main() {
 	setlocale(LC_ALL, "Rus");
	int a,b,c;
	printf("Enter a b c : ");
	scanf("%d %d %d", &a, &b, &c);
	if (c-b==b-a) printf ("Арифметическая прогрессия\n");
	else if (c-b!=b-a) printf ("Не арифметическая прогрессия\n");
	system("pause");
	return 0;
}
