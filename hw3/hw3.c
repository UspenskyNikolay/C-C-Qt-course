#include <stdio.h>

int main()	{

int i,
	a = 0, 
	x = 0, 
	sum = 0;

do {
	a++;
	while (x<90){
		for (i = 0; i<10; i++){
			sum += i; }
		x += sum;	
		}
	}while (a<10);
	
		printf("a: %d \n", a);
		printf("x: %d \n", x);
		printf("i: %d \n", i);
		printf("sum: %d \n", sum);

	return 0;
}








