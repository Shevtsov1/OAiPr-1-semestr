#include <stdio.h>
#include <locale.h>

int matr[100][100];
void setMatr( int matr[100][100], int n1, int m1);
int viewMatr( int matr[100][100], int n1, int m1);
int rowSearch( int matr[100][100], int n1, int m1);
int main()
{
	setlocale(LC_ALL, "Rus");
	int n,m;
	printf("������� ���-�� ����� �������: ");
	scanf("%d", &n);
	printf("������� ���-�� �������� �������: ");
	scanf("%d", &m);
	setMatr( matr, n, m);
	viewMatr( matr, n, m);
	rowSearch( matr, n , m);
}
void setMatr( int matr[100][100], int n1, int m1)
{
	int i,j;
	for( i=0; i<n1; i++)
	    for( j=0; j<m1; j++){
	    	printf("������� ������� [%d][%d]", i+1, j+1);
	    	scanf("%d", &matr[i][j]);
		}
}
int viewMatr( int matr[100][100], int n1, int m1)
{
	printf("�������:");
	int i,j;
	printf("\n");
	for( i=0; i<n1; i++){
	    for( j=0; j<m1; j++)
            printf("\t%d", matr[i][j]);
        printf("\n");
    }
    return 0;
}
int rowSearch( int matr[100][100], int n1, int m1)
{
int i,j,k=0,z=0,numstr=0;
    for( i=0; i<n1; i++){
      for( j=0; j<m1; j++){
        if(matr[i][j]<0) k++;
        else k = 0;
        
        if(k==m1)
		    {
        	    printf("\n������ %d �������� ������ ������������� ��������!", i+1);
        	    z = 1;
		    }
        }
        if(z==0)
		{
		    printf("\n������ %d �������� ��������������� �������!\n", i+1);	
		}
    }
}
