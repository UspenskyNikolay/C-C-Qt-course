#include <stdio.h>

int SUM (int n) {
   int d = 0;
   if(!n)
     return 0;
       d = d + n % 10;
       d = d + SUM (n / 10);
     return d;
}

void  main ()
{
int a;
	    printf("Enter the date of born\n");
	    scanf("%d", &a);
 	    printf ("Sum of digit of date: %d\n", SUM(a) );
	
}
