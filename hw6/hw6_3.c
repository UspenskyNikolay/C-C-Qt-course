
/** Code by Uspensky *****/

/**************************************************************************************/
/*                 Программа вычисления размера считанных данных из текста            */	
/**************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(  )
{
  FILE *fp;
  int i, n = 0;
  char c , Ar_txt[100000]; 
  	  
  	fp = fopen ("t.txt", "r+");
		if (fp==NULL) {
			printf("Cannot open file.\n");
			exit (1);
		}
		while(!feof (fp)) {
			Ar_txt[n] = fgetc(fp);
			n++;
		}
   	  	 printf("Размер считанных данных в байтах: %d\n", n);
	
printf ("Закрытие файла: ");
   if ( fclose (fp) == EOF) printf ("ошибка\n");
   else printf ("выполнено\n");
} 


