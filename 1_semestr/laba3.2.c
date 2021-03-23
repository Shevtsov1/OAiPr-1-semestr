#include<stdio.h>
#include <locale.h>
#include <math.h>
double main()
{
	setlocale(LC_ALL,"rus");
    float a,x, y;
    printf ("¬ведите число a: ");
    scanf ("%f", &a);
    do {
    	printf("%.0f\n",a*a+1);
    	a=a*a+1;
	}
	while (a<=1000000);
    printf("„исло х: %.0f\n", a);
    return 0;
}
