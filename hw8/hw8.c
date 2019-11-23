#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#define STACK_SIZE 10

int n = 20, num_t;  
char y_n, str[20]; 

struct Stack{
  int id;				// id - индекс элемента в массива 
  char Name[20];
  int priority;
  int time_work;  		// Время выполнения задачи
  struct Stack * Next;
};
struct Stack Task[STACK_SIZE];

/********************************************************************************************/

void push(int * head, struct Stack * newTask ){  // Добавление в стек нового элемента
	if(*head == STACK_SIZE){
      		printf( "Ошибка! Стек переполнен. \n");     // Не переполнен ли стек?   
        	abort();
  	}
 		else {	Task[++*head] =*newTask;
				Task[*head-1].Next =&Task[*head];
				Task[*head].Next =0;
  			 }
}

/***********************************************************************************************/

void initPriority(struct Stack * Task) {		// Функция создания  приоритетов
  Task->priority = rand()%10;
}

/***********************************************************************************************/

void init_TimeWork(struct Stack * Task) { 	// Функция генерирования времени работы
  Task->time_work = rand()%10;
}

/***********************************************************************************************/

void print_Stack ()		// Функция вывода списка задач
{ 
 if (num_t == 0) {
        printf("Список задач пуст!\n\n");
        return;
		}
for (int j = 1; j < num_t+1;  j++){
    printf("%d %s  Priority: %d\t timework: %d\n", 
	Task[j].id,
	Task[j].Name,
	Task[j].priority, 
	Task[j].time_work);
	}
printf ("\n");
}
/***********************************************************************************************/

void pop_Stack() {										// Функция удаления элемента
     
        if(num_t > 0)
        {
            Task[num_t-1].Next = 0;
            num_t--;
            printf("\nЗадача %d удалена!\n", num_t+1);
        }
        else
            printf("\nНет задач для удаления!\n");
    }    

/***********************************************************************************************/

void enter()								// Функция ввода задач
{
	srand(time(NULL));
	int prior, t_work;
	char y_n;
	
	printf ("\nЗадачи формируются автоматически? Да/Нет (Y/N):");
  	scanf("%c", &y_n);
		if (y_n == 'Y'){
		    printf ("\nВведите количество задач (1- %d ):", STACK_SIZE);
		    scanf("%d", &num_t);
			if ((num_t < 0)||(num_t > STACK_SIZE))
				{
				   printf("\nОшибка! Введите корректное количество задач\n");	
				   return;		
				}			
		    printf("\n\n");
			for (int j = 1; j < num_t+1; j++)
			{
				Task[j].id = j;
				sprintf(Task[j].Name, "%s %d", "Task", j );
				initPriority(&Task[j]);
				init_TimeWork(&Task[j]);
					
			}
		
			print_Stack (num_t);
		
			printf("\nСтэк заполнен. В стэке  %d задач\n\n", num_t );
		} 

	else 
	   if (y_n == 'N'){
		if (num_t == STACK_SIZE) {
			printf ("Стек полон, задачу добавить невозможно!\n");
			return;	 
		 } else {
				printf ("\nВведите имя задачи:");
				scanf("%s", &str);
				//printf ("\nВ стэке  %d задач\n\n", num_t); 
				printf ("\nВведите приоритет(1-9):");
				scanf("%d", &prior);
				printf ("\nВведите время выпонения задачи, сек:");
				scanf("%d", &t_work);
				
				num_t = num_t+1;
				sprintf(Task[num_t].Name, "%s %d", str, num_t);			
				Task[num_t].id = num_t;
				Task[num_t].priority = prior;
				Task[num_t].time_work = t_work;
	
			print_Stack (num_t);
		
			printf("\nВ стэке  %d задач\n\n", num_t );

			}

			return;	
		}
	
}

/***********************************************************************************************/


int select_menu(void)
{
	char s[3];
	  int c;
	  printf("Менеджер задач. Операции со стеком\n\n");
	  printf("1. Ввод задач\n");
	  printf("2. Удаление задачи\n");
	  printf("3. Вывод списка задач\n");
	  printf("4. Выполнить задачи\n");
	  printf("5. Изменить режим (стек/очередь)\n");
	  printf("6. Выход\n");
	  do 
		{ 	printf("\nВведите номер нужного пункта: ");
    	scanf("%s", s);
		getchar();
		c = atoi(s);
	  	} while(c<0 || c>6);
	  return c;

}

/***********************************************************************************************/


int main () 
{
	num_t = 0;  
	system("clear");
	char choice;
	//init(); 
	
   while (1)
	{
	    choice = select_menu();
	    switch(choice) 
		{
      		case 1: enter();
        		break;
      		case 2: pop_Stack();
        		break;
      		case 3: print_Stack(num_t);
        		break;
      		case 4: printf(" %d \n\n", num_t);
        		break;
			case 5: printf("Функция временно не работает\n\n");
        		break;
			case 6: exit(0);
    	}
  
	}

  	return 0;
}

