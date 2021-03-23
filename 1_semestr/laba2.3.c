#include <stdio.h>
#include <iostream>
#include <math.h>
int main()
{
	setlocale(LC_ALL, "Russian");
int x,y,z;
printf("Выберите дейстиве:\n");
printf("1-подсчет суммы двух чисел\n");
printf("2-подсчет разности двух чисел\n");
printf("3-подсчет произведенеия двух чисел\n");
printf("4-подсчет частного двух чисел\n");
printf("Ваш выбор : \n");
scanf("%d", &z);
switch (z) {
case 1:
	printf("Введите два числа: \n");
	scanf("%d %d", &x, &y);
	printf("Ваш ответ: %d\n", x+y);
	break;
case 2:
	printf("Введите два числа: \n");
	scanf("%d %d", &x, &y);
	printf("Ваш ответ: %d\n", x-y);
	break;
case 3:
	printf("Введите два числа: \n");
	scanf("%d %d", &x, &y);
	printf("Ваш ответ: %d\n", x*y);
	break;
case 4:
	printf("Введите два числа: \n");
	scanf("%d %d", &x, &y);
	printf("Ваш ответ: %d\n", x/y);
	break;		
}
system("pause");
return 0;	
}
