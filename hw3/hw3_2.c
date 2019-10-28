#include <stdio.h>

int main()	{

int num_catalog; 
	
	printf ("Enter the number of catalog to get liter of them: 0...4\t");
	scanf ("%i", &num_catalog);
	switch (num_catalog) 
	{

	case 0: printf ("N\n");
		break;
	case 1: printf ("O\n");
		break;
	case 2: printf ("T\n");
		break;
	case 3: printf ("TR\n");
		break;
	case 4: printf ("F\n");
		break;
	}
	return 0;
}








