
/** Code by Uspensky *****/

/**************************************************************************************/
/*                 Programm for printing array of random symbols                      */	
/**************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () 
{
	srand (time(NULL));
	int i, k;
	char c , array[1000];

		for (i = 0; i < 1000; i++)
		{	
			k = rand () %255;		
	    	if((k<48)||(k>57))
	    	{		
				array[i] = k;
				printf ("Char %d: %c\n",i, array[i]);
	    	}
		}
} 
