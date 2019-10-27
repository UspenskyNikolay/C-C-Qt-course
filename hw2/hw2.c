#include <stdio.h>

int main()
{
    char x = 127;
	int a = x;
		printf("was x: %d \n", x);
    x = x + 1;
	a = a + 1;
    if(x<0) 
	{ 	printf("x is now: %d \n", x);
		printf("overflow number: %d \n", a);
	}
			printf("Symbol: %c \n", x);
    return 0;
}
