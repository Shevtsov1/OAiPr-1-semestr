#include <stdio.h>
#include <iostream>
#include <math.h>
int main()
{
	setlocale(LC_ALL, "Russian");
int x,y,z;
printf("�������� ��������:\n");
printf("1-������� ����� ���� �����\n");
printf("2-������� �������� ���� �����\n");
printf("3-������� ������������� ���� �����\n");
printf("4-������� �������� ���� �����\n");
printf("��� ����� : \n");
scanf("%d", &z);
switch (z) {
case 1:
	printf("������� ��� �����: \n");
	scanf("%d %d", &x, &y);
	printf("��� �����: %d\n", x+y);
	break;
case 2:
	printf("������� ��� �����: \n");
	scanf("%d %d", &x, &y);
	printf("��� �����: %d\n", x-y);
	break;
case 3:
	printf("������� ��� �����: \n");
	scanf("%d %d", &x, &y);
	printf("��� �����: %d\n", x*y);
	break;
case 4:
	printf("������� ��� �����: \n");
	scanf("%d %d", &x, &y);
	printf("��� �����: %d\n", x/y);
	break;		
}
system("pause");
return 0;	
}
