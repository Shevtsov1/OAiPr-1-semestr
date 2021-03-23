#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{  setlocale(LC_ALL, "Rus");
    int A[7]; 
    int i,sum1=0;
    int j,sum2=0;
    int k;
     printf("¬ведите массив A:\n");
    for (i = 0; i < 7; i++) {
    printf("A[%d]= ", i);
    scanf ("%i", &A[i]) ;
    }
    printf("¬ведите номер элемента массива k: ", k);
    scanf("%d", &k);
       for (i = 0; i < k; i++) {   
       sum1 += A[i];
       }
       printf("—умма элементов от первого до k = %d\n", sum1); 
       for (j = k; j < 7 ; j++) {   
       sum2 += A[j];
       }
       printf("—умма элементов от k+1 до последнего = %d\n", sum2);
       if(sum1>=sum2){
       	printf("—умма от первого до k (%d) больше\n", sum1);
	   }
	   else{
	   	printf("—умма от k+1 до первого (%d) больше", sum2);
	   }
    return 0;
}
