#include "core.h"


int main(int argc, char *argv[]) {
	int variant;
	do{
		printMenu();
		
		variant = getVariant(3);
		
		switch(variant){
			case 1:
				IterrationMethod();
				break;
			case 2:
				
				break;
		}
		if (variant != 3)
		system("pause");
	}while(variant != 3);
	return 0;
}
