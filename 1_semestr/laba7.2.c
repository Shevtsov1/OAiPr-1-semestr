#include <stdio.h>
#include <locale.h>

int findSymInStr(char[1000], char);


int main(void)
{
	setlocale(LC_ALL, "Russian");

	char userString[1002] = {};
	char userChar;

	printf("%s\n", "Введите строку, не более 1000 эл-ов, латиницей: ");
	fgets(userString, sizeof(userString), stdin);

	printf("%s\n", "Введите символ латиницей: ");
	userChar = getchar();

	printf("Символ %c повторялся %d раз(а)\n", userChar, findSymInStr(userString, userChar));

	return 0;
}


int findSymInStr(char string[1002], char sumbol)
{
	int i,count = 0;
	for ( i = 0; i < (sizeof(char)*1002/sizeof(char)); ++i)
	{
		if ((int)string[i] == (int)sumbol)
		{
			count++;
		}
	}

	return count;
}
