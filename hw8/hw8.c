#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#define STACK_SIZE 10

int n = 20, num_t;  
char y_n, str[20], A[8] = {'*'}; 

struct Stack{
  int id;				// id - индекс элемента в массива 
  char Name[20];
  int priority;
  int time_work;  		// Время выполнения задачи
  struct Stack * Next;
};
struct Stack Task[STACK_SIZE], tmpTask;

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

void init_TimeWork(struct Stack * Task) { 		// Функция генерирования времени работы
  Task->time_work = rand()%10;
}

/***********************************************************************************************/

void print_Stack ()					// Функция вывода списка задач
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

void pop_Stack() {					// Функция удаления элемента
     
        if(num_t > 0)
        {
            Task[num_t-1].Next = 0;
            num_t--;
            printf("\nЗадача %d удалена!\n", num_t+1);
			print_Stack ();	
        }
        else
            printf("\nНет задач для удаления!\n");
    }    

/***********************************************************************************************/

void enter()						// Функция ввода задач
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
				printf ("\nВведите время выполнения задачи, сек:");
				scanf("%d", &t_work);
				
				num_t = num_t+1;
				sprintf(Task[num_t].Name, "%s %d", str, num_t);			
				Task[num_t].id = num_t;
				Task[num_t].priority = prior;
				Task[num_t].time_work = t_work;
	
			printf("\n");		
			print_Stack (num_t);
			printf("\nВ стэке  %d задач\n\n", num_t );

			}

			return;	
		}
	
}
/***********************************************************************************************/

void b_sort (){
for (int i = 1 ; i <= num_t+1; i++) { 
     	   for(int j = 1 ; j <= num_t+1- i ; j++) {  
            if(Task[j].priority < Task[j+1].priority) {    // сравниваем два соседних элемента.       
 		          				   // если они идут в неправильном порядке, то  	
              	tmpTask = Task[j];			  //  меняем их местами. 
             	Task[j] = Task[j+1];
              	Task[j+1] = tmpTask; 
              }
          }
     }

print_Stack ();
}

/***********************************************************************************************/


void start_task()
{
//Проверка стэка
    if(num_t == 0)
    {
        printf( "\nСписок задач пуст!\n\n");
        return;
    }
    printf("\nВыполнение задач:\n\n");
    
         

    //Вывод списка задач
        do
        {
	printf("%d %s  Priority: %d\t timework: %d\n", 
	Task[num_t].id,
	Task[num_t].Name,
	Task[num_t].priority, 
	Task[num_t].time_work);
           
           for(int k = 0; k < Task[num_t].time_work ; k++)
            {
                printf("*");
                fflush(stdout);
                sleep(1); 
            }
            printf("Задача выполнена!\n");
            Task[num_t-1].Next = 0;
            num_t--;
        }while(num_t!=0);
    }


/***********************************************************************************************/


int select_menu(void)
{
	char s[3];
	  int c;
	  printf("\nМенеджер задач. Операции со стеком\n\n");
	  printf("1. Ввод задач\n");
	  printf("2. Удаление задачи\n");
	  printf("3. Вывод списка задач\n");
	  printf("4. Сортировка по приоритету\n");
	  printf("5. Выполнить задачи\n");
	  printf("6. Изменить режим (стек/очередь)\n");
	  printf("7. Выход\n");
	  do 
		{ 	printf("\nВведите номер нужного пункта: ");
    	scanf("%s", s);
		getchar();
		c = atoi(s);
	  	} while(c<0 || c>7);
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
      		case 4: b_sort ();
        		break;
      		case 5: start_task();
        		break;
		case 6: printf("Функция временно не работает\n\n");
        		break;  
		case 7: exit(0);
    	}
  
	}

  	return 0;
}

