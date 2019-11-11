
/** Code by Uspensky *****/

/**************************************************************************************/
/*            ДЗ №7  Программа "Телефонный справочник" 	  	                      */	
/**************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int ch;

struct str_list {
	
	int id;
	char Name [40];
	char Phone [30]; 
	} Phone_book[MAX];


/***************************************************************************************/

void init (void){					// Функция инициализации списка
  int n;
  for(n=0; n<MAX; ++n){ 
	Phone_book[n].id = n;	
	Phone_book[n].Name[0] = '\0';
	}
}

/***************************************************************************************/

int select_menu(void)
{
  char s[80];
  int c;

  printf("1. Введите имя и телефон\n");
  printf("2. Выведите список\n");
  printf("3. Поиск в базе\n");
  printf("4. Выход\n");
  do {
    printf("\nВведите номер нужного пункта: ");
    gets(s);
    c = atoi(s);
  } while(c<0 || c>4);
  return c;
}
/**************************************************************************************/

void enter(void)
{
  int slot;					//функция ввода
  
  	slot = find_free();
  	if(slot==-1) {
  	  	printf("\nСписок заполнен");
  	  	return;
  	}
	
  		printf("Введите имя:");
		gets(Phone_book[slot].Name);
	
		printf("Введите номер телефона:");
  		gets(Phone_book[slot].Phone);

  	
}

/****************************************************************************************/

int find_free(void)				//функция поиска свободной структуры
{
  int t;

  for(t=0; Phone_book[t].Name[0] && t<MAX; ++t) ;

  if(t==MAX) return -1; 			// свободных структур нет 
  return t;
}

/****************************************************************************************/
void Out_list(void)					
{						//функция вывода списка на экран
						// и записи в файл
  int t;
  FILE *fp;
  fp = fopen ("t.txt", "r+");
  for(t=0; t<MAX; ++t) {
    if(Phone_book[t].Name[0]) {			
        printf("%d\t", Phone_book[t].id+1);
	printf("%s\t", Phone_book[t].Name);
	printf("%s\n", Phone_book[t].Phone);
		
	fprintf(fp,"%d\t", Phone_book[t].id+1);   // запись  в файл
	fprintf(fp,"%s\t", Phone_book[t].Name);
	fprintf(fp,"%s\n", Phone_book[t].Phone);
	}

  }fclose (fp);
  printf("\n\n");


}


/****************************************************************************************/

int main () {

char choice;

  init(); 
  for(;;) {
    choice = select_menu();
    switch(choice) {
      case 1: enter();
        break;
      case 2: Out_list();
        break;
      case 3: printf("Функция временно не работает\n\n");
        break;
      case 4: exit(0);
    }
  }

  return 0;


}
