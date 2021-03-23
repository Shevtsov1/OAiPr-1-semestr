#include <stdio.h>
#include <malloc.h>
#include <locale.h>

void setFlightInfo(void);
void printFlightsInfo(void);
void deleteFlight(void);
void sortFlights(void);
void findFlightInfo(void);
void editFlightInfo(void);
void printFindFlight(int);

#define LEN_DIST 31
#define LEN_T 10
#define LEN_D 15

struct flight
{
	float number, price;
	char destination[LEN_DIST];
	char time[LEN_T], date[LEN_D];
};

struct flight *flights = NULL;
int count = 0;


int main(void)
{
	setlocale(LC_ALL, "Rus");
	int userOption;
	do
	{
		printf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n", "1. ���� ������� ��������",
											       "2. ���������� ������� ��������",
											  	   "3. ����� � ������� ��������",
											   	   "4. ��������� ������� ��������",
											       "5. �������� ���-�� �� �������",
											       "6. ����� ������� ��������",
											       "7. �����");
		    scanf("%d", &userOption);

		switch(userOption)
		{
			case 1:
				setFlightInfo();
				break;
			case 2:
				sortFlights();
				break;
			case 3:
				findFlightInfo();
				break;
			case 4:
				editFlightInfo();
				break;
			case 5:
				deleteFlight();
				break;
			case 6:
				printFlightsInfo();
				break;
			case 7:
				userOption = 0;
				break;
			default: 
				main();
		}

	} while (userOption != 0);

	return 0;
}

void setFlightInfo(void)
{
	flights = (struct flight*)realloc(flights, sizeof(struct flight)*(count+1));

	printf("%s\n", "������� ����� �����:");
	    scanf("%f", &(flights+count)->number);

	printf("%s\n", "������� ����� ����������:");
	    scanf("%s", (flights+count)->destination);

	printf("%s\n", "������� ����� ������:");
	    scanf("%s", (flights+count)->time);

	printf("%s\n", "������� ���� ������ (����/�����/���):");
	    scanf("%s", (flights+count)->date);

	printf("%s\n", "������� ��������� ������:");
	    scanf("%f", &(flights+count)->price);

	printf("���������� � ����� ���������\n");

	count++;
}


void printFlightsInfo(void)
{
	int i;
	int check = 1;

	for ( i = 0; i < count; i++)
	{
		printf("\n����� �����: %g\n", (flights+i)->number);

		    printf("����� ����������: %s\n", (flights+i)->destination);

		        printf("����� ������: %s\n", (flights+i)->time);

		            printf("���� ������: %s\n", (flights+i)->date);

		                printf("��������� ������: %g\n", (flights+i)->price);

		check = 0;
	}

	if (check)
	{
		printf("������ ���-� ����\n");
	}
}


void deleteFlight(void)
{
	int i,j,k;
	int userElement;
	printf("������� ����� ����� ��� ��������:\n");
	    scanf("%d", &userElement);

	for ( i=0; i<count; ++i)
	{
		if (userElement == (flights+i)->number)
		{
			for ( j=i; j<count-1; ++j)
			{
				(flights+j)->number = (flights+j+1)->number;

				for ( k=0; k< LEN_DIST; ++k)
				{
					(flights+j)->destination[k] = (flights+j+1)->destination[k];
				}

				for ( k = 0; k < LEN_T; ++k)
				{
					(flights+j)->time[k] = (flights+j+1)->time[k];
				}

				for ( k = 0; k < LEN_D; ++k)
				{
					(flights+j)->date[k] = (flights+j+1)->date[k];
				}

				(flights+j)->price = (flights+j+1)->price;
			}

			count--;

			flights = (struct flight*)realloc(flights, sizeof(struct flight)*(count+1));

			printf("���� � ������� %d ������\n", userElement);
		}

		else printf("����� � ����� ������� �� �������\n");
	}
}


void sortFlights(void)
{
	int i,k,p;
	int j = 0;
	
	for ( i=0; i<count; ++i)
	{
		j = i;

		for ( k=i; k<count; ++k)
		{
			if ((flights+j)->number > (flights+k)->number) j = k;
		}

		(flights+i)->number=(flights+i)->number+(flights+j)->number-((flights+j)->number=(flights+i)->number);

		for ( p=0; p<LEN_DIST; ++p)
		{
			(flights+i)->destination[p]=(flights+i)->destination[p]+(flights+j)->destination[p]-((flights+j)->destination[p]=(flights+i)->destination[p]);
		}

		for ( p=0; p<LEN_T; ++p)
		{
			(flights+i)->time[p]=(flights+i)->time[p]+(flights+j)->time[p]-((flights+j)->time[p]=(flights+i)->time[p]);
		}

		for ( p=0; p<LEN_D; ++p)
		{
			(flights+i)->date[p]=(flights+i)->date[p]+(flights+j)->date[p]-((flights+j)->date[p]=(flights+i)->date[p]);
		}

		(flights+i)->price=(flights+i)->price+(flights+j)->price-((flights+j)->price=(flights+i)->price);
	}

	printf("������ �������� ������������\n");
}


void printFindFlight(int n)
{
	printf("\n����� �����: %g\n", (flights+n)->number);

	    printf("����� ����������: %s\n", (flights+n)->destination);

	        printf("����� ������: %s\n", (flights+n)->time);

	            printf("���� ������: %s\n", (flights+n)->date);

	                printf("��������� ������: %g\n", (flights+n)->price);
}


void findFlightInfo(void)
{
	int i,j;
	int option;
	int helpCount = 0;
	int check = 1;
	float findNumber, findPrice;
	char findDistination[LEN_DIST] = {};
	char findTime[LEN_T] = {};
	char findDate[LEN_D] = {};

	printf("�������� �������� ������:\n%s\n%s\n%s\n%s\n%s\n\n", "1. ����� �����",
																"2. ����� ����������",
														      	"3. ����� ������",
																"4. ���� ������",
																"5. ��������� ������");
	scanf("%d", &option);
	switch(option)
	{

		case 1:
			printf("������� ����� �����:\n");
			    scanf("%f", &findNumber);

			for ( i = 0; i < count; ++i)
			{
				if ((flights+i)->number == findNumber)
				{
					printf("���������� � ����� �������\n");
					printFindFlight(i);
					check = 0;
				}
			}
			if (check) printf("���������� � ����� �����������\n");
			break;

		case 2:
			printf("������� ����� ����������:\n");
			    scanf("%s", findDistination);

			for ( i = 0; i < count; ++i)
			{
				for ( j = 0; j < sizeof(findDistination); ++j)
				{
					if((int)(flights+i)->destination[j] == (int)findDistination[j]) helpCount++;
				}

				if (helpCount == sizeof(findDistination))
				{
					printf("���������� � ����� �������\n");
					printFindFlight(i);
					helpCount = 0;
					check = 0;
				}
			}
			if (check) printf("���������� � ����� �����������\n");
			break;

		case 3:
			printf("������� ����� ������ (:):\n");
			    scanf("%s", findTime);

			for ( i = 0; i < count; ++i)
			{
				for ( j = 0; j < sizeof(findTime); ++j)
				{
					if((int)(flights+i)->time[j] == (int)findTime[j]) helpCount++;
				}

				if (helpCount == sizeof(findTime))
				{
					printf("���������� � ����� �������\n");
					printFindFlight(i);
					helpCount = 0;
					check = 0;
				}
			}
			if (check) printf("���������� � ����� �����������\n");
			break;

		case 4:
			printf("������� ���� ������(����/�����/���):\n");
			    scanf("%s", findDate);

			for ( i = 0; i < count; ++i)
			{
				for ( j = 0; j < sizeof(findDate); ++j)
				{
					if((int)(flights+i)->date[j] == (int)findDate[j]) helpCount++;
				}

				if (helpCount == sizeof(findDate))
				{
					printf("���������� � ����� �������\n");
					printFindFlight(i);
					helpCount = 0;
					check = 0;
				}
			}

			if (check) printf("���������� � ����� �����������\n");

			break;

		case 5:
			printf("������� ��������� ������:\n");
			scanf("%f", &findPrice);

			for ( i = 0; i < count; ++i)
			{
				if ((flights+i)->price == findPrice)
				{
					printf("���������� � ����� �������\n");
					printFindFlight(i);
					check = 0;
				}
			}

			if (check) printf("���������� � ����� �����������\n");

			break;

		default:
			findFlightInfo();
	}
}


void editFlightInfo(void)
{
	int i;
	int userElement, choise;
	int helpCount = 0;
	int check = 1;
	int editElement;
	float newNumber, newPrice;
	char newDistination[LEN_DIST] = {};
	char newTime[LEN_T] = {};
	char newDate[LEN_D] = {};

	printf("������� ����� ����� ��� ���������:\n");
	scanf("%d", &userElement);

	for ( i = 0; i < count; ++i)
	{
		if ((flights+i)->number == userElement)
		{
			editElement = i;
			break;
		}

		else if (i == count - 1); 
		{
			printf("���� � ����� ������� �����������\n");
			editFlightInfo();
		}
	}

	do
	{
		if (choise == 0) main();

		printf("\n�������� �������� ��� ���������:\n%s\n%s\n%s\n%s\n%s\n%s\n\n", "(1) ����� �����",
																	 		     "(2) ����� ����������",
																		         "(3) ����� ������",
																			     "(4) ���� ������",
																			     "(5) ��������� ������",
																		         "(0) ���������");
		scanf("%d", &choise);

		switch(choise)
		{

			case 1:
				printf("������� ����� ����� �����:\n");
				scanf("%f", &newNumber);

				(flights+editElement)->number = newNumber;

				printf("����� ����� �������\n");

				break;

			case 2:
				printf("������� ����� ����� ����������:\n");
				scanf("%s", newDistination);

				for ( i = 0; i < LEN_DIST; ++i)
				{
					(flights+editElement)->destination[i] = newDistination[i];
				}

				printf("����� ���������� �������\n");

				break;

			case 3:
				printf("������� ����� ����� ������ (:):\n");
				scanf("%s", newTime);

				for ( i = 0; i < LEN_T; ++i)
				{
					(flights+editElement)->time[i] = newTime[i];
				}

				printf("����� ������ ��������\n");

				break;

			case 4:
				printf("������� ����� ���� ������(����/�����/���):\n");
				scanf("%s", newDate);

				for ( i = 0; i < LEN_D; ++i)
				{
					(flights+editElement)->date[i] = newDate[i];
				}

				printf("���� ������ ��������\n");

				break;

			case 5:
				printf("������� ����� ��������� ������:\n");
				scanf("%f", &newPrice);

				(flights+editElement)->price = newPrice;

				printf("��������� ������ ��������\n");

				break;

			case 0:
				choise = 0;
				break;

			default:
				 editFlightInfo();
		}
	} while (choise != 0);
	
}
