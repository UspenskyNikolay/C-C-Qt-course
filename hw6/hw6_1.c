
/** Code by Uspensky *****/

/**************************************************************************************/
/*                 Programm for printing 1....100 with goto    	                      */	
/**************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int n = 0;
int main () {

label:	printf ("Цифра: %d\n", ++n);
 		if ( n < 100)
			goto label;
return 0;
} 
