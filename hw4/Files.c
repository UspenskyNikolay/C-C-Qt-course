
#include <stdio.h>


int main () 
{
	int n=0, i;
	char str[80], str2[10];
	srand(time(NULL));   
	int r = rand(); 
		
	while (n <10)
	{	n++;
		sprintf (str, "%d %s ", n, ".txt");
		printf("%s\n", str);
		FILE * fp;
		fp = fopen (str, "w+");
		if(fp)
		{
			for(i=0; i<1000; i++)
			{	
				sprintf (str2, "%d ", r %20);				
				fputs (str2, fp);	
			}
		}else printf("Error open file");
	fclose(fp);
	}
}

	
