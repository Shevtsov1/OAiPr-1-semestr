#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	float x,y,z,S;
	printf ("Enter x, y, z:");
	scanf("%f %f %f", &x, &y, &z);
	S=(exp(fabs(x-y))*pow(fabs(x-y),x+y))/(atan(x)+atan(z))+cbrt(pow(x,6)+pow(log(y),2));
	printf("S= %.4f\n", S);
	return 0;
}
