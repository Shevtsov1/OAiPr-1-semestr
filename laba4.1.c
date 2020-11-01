#include <stdio.h>
int main(){
	int a[5];
	unsigned i;
	unsigned j;
	int max;
	int min;
	max=a[0];
	min=a[0];
	for(i=0; i<5; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
   for(i=0; i<5; i++){
   	printf("%d ", a[i]);
   }
   for(i=0; i<5; i++){
   	if(a[i]>max){
   		for(j=i+1;j<5;j++);
   		a[j-1]=a[j];
   		i--;
	   }
   }
   for(j=0;j<4;j++){
   	printf("%d ", a[j]);
   }
	return 0;
}
