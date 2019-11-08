#include <stdio.h>
#include <string.h>

/* Таблица частот */
unsigned Freq[256];

void main(  )
{
  FILE *fp;
  int i;

  	  
  	if ((fp = fopen("t.txt", "rt")) == NULL)
  	{
    		printf("Невозможно открыть для чтения файл '%s'\n", "t.txt");
    		return;
  	}

   	memset(Freq, 0, 256 * sizeof(unsigned));
	
	while (!feof(fp))
    		Freq[fgetc(fp)] ++;
  	
	printf("Частоты появления символов:\n");
  		
		for (i = 0; i < 256; i ++)
    			if (Freq[i])
     	 			printf("Символ %c : %5u раз\n", i, Freq[i]);

} 
