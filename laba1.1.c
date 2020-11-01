#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 int main() {
	float x,y;
	printf("Enter x: ");
	scanf("%f", &x);
	y=128*pow(x,2);
	printf("Answer : %.f\n", y);
	system("pause");
	return 0;
}

