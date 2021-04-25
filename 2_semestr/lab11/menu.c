void printMenu(){
	system("cls");
	printf("Choose option:\n");
	printf("1.Itteration method\n");
	printf("2.Zeidel method\n");
	printf("3.Exit\n");
    printf(">");
}

int getVariant(int count){
	int variant;
	char s[100];
	scanf("%s", s);
	
	while(sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count){
		printf("Incorrect input. Try again: ");
		scanf("%s", s);
	}
	
	return variant;
}
