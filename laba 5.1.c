#include <stdio.h>
#include <conio.h>
#include <locale.h>
void main(){
	setlocale(LC_ALL, "Rus");
int i,j,kol=0,n,k; 
float a[100][100];
do{
	printf("Введите кол-во строк матрциы (<100)\n");
	scanf("%d",&n);
	printf("Введите кол-во столбцов матрциы (<100)\n");
	scanf("%d",&k);
 } while(n>=100,k>=100);
for(i=0;i<n;i++)
for(j=0;j<k;j++){
	printf("Введите элементы матрицы[%d,%d]\n",	i+1,j+1);
	scanf("%f",&a[i][j]);
 } 
printf("Матрица: \n");
for(i=0;i<n;i++){
	for(j=0;j<k;j++)
	printf("%.0f ", a[i][j]);
	printf("\n");
 }
for(i=0;i<n;i++)
for(j=0;j<k;j++){
	if(a[i][j]==0)
	kol++;
 }
printf("Кол-во нулевых эл-ов матрицы= %.0d\n", kol);
for(i=0;i<n;i++){
 for(j=0;j<k;j++)
  if(a[i][j]<0)
  a[i][j]=0;
 }
printf("Матрица после замены: \n");
for(i=0;i<n;i++){
	for(j=0;j<k;j++)
	printf("%.0f ", a[i][j]);
	printf("\n");
 }
}
