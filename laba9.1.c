#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

#define FILE_COUNT 3

int setMaxElements(int*, int);


int main()
{
	setlocale(LC_ALL, "Rus");

    int i;
    int k = 0;
    int s;
    int **arr = NULL;

	FILE *A_File, *B_File, *C_File, *D_File;

	A_File = fopen("NameA.txt","r");
	B_File = fopen("NameB.txt","r");
	C_File = fopen("NameC.txt","r");
	D_File = freopen("NameD.txt", "w", stdout);

    while ((fscanf(A_File, "%d",&s)!=EOF))
	{    
		if(!A_File) break;  
	    k += 1;
	}

	arr = (int**)malloc(k*sizeof(int*));
    for ( i = 0; i < k; ++i)
	{
		arr[i] = (int*)malloc(FILE_COUNT*sizeof(int));
	}
	 
	 
	rewind(A_File);   

	for( i = 0; i < k ; i++)
	{
	    fscanf(A_File, "%d",(arr[i]+0));
	    fscanf(B_File, "%d",(arr[i]+1));
	    fscanf(C_File, "%d",(arr[i]+2));
	}

	fclose(A_File);
	fclose(B_File);
	fclose(C_File);

    for ( i = 0; i < k; ++i)
    {
    	printf("%d ", setMaxElements(arr[i], FILE_COUNT));
    }
	return 0;
}


int  setMaxElements(int *arr, int n)
{
	int i,j,k;

	for ( i = 0; i < 2*n-2; ++i)
	{
		j = i;

		for ( k = i; k < 2*n-2; ++k)
		{
			if (*(arr+j) < *(arr+k)) j = k;
		}

		*(arr+i) = *(arr+i) + *(arr+j) - (*(arr+j) = *(arr+i));
	}

	return arr[0];
}

