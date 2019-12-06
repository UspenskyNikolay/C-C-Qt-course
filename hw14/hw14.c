#include <stdio.h>
#include <stdlib.h>


#define SPACE ' '
char matrix[3][3];		 /* = {  матрица для крестиков-ноликов */


void get_computer_move(void), get_player_move(int num);
void disp_matrix(void); void init_matrix(void);
char check (void);

int main()
{
	char done;
	int cas, num1 = 1, num2 = 2;

	init_matrix();
	printf("Игра крестики-нолики.\n");
	  printf("Выберите тип игры:\n");
	  printf("1. Игра против компьютера.\n");
	  printf("2. Игра двух игроков.\n");
	  printf("3. Выти из игры\n");
	  scanf("%d", &cas);
	  if (cas==1) {
		printf("Вы будете играть против компьютера.\n");
		done = SPACE;
			do {
				disp_matrix(); 				/* вывод игровой доски */
				get_player_move(cas); 			/* ходит игрок */
				done = check(); 			/* проверка на победу */
			if (done!=SPACE) break; 			/* победитель */
			 	get_computer_move(); 		/* ходит компьютер */
			 	done=check(); 				
			} while(done==SPACE);
				if(done=='X') printf("Вы выиграли!\n");
				  else printf("Я выиграл!!!!\n");
					disp_matrix(); 			/* отображение результирующего положения */
		} 

		else if (cas==2){
		printf("Игра двух игроков.\n");
		printf("Игрок 1 играет крестиками, игрок 2 - ноликами.\n");
		done = SPACE;
			do {	
				disp_matrix(); 				/* вывод игровой доски */
				get_player_move(num1); 			/* ходит 1-й игрок */
				done = check(); 
				disp_matrix();
			if (done!=SPACE) break; 
			 	get_player_move(num2); 			/* ходит 2-й игрок */
			 	done=check(); 
			} while(done==SPACE);
				disp_matrix(); 				/* отображение результирующего положения */
					if(done=='X') printf("Вы выиграли!\n");
						 else printf("Игрок 2 выиграл!\n");
		}
			else exit(0);
return 0;
}

void init_matrix(void)
{
    for(int i=0; i<3; i++)
    	for(int j=0; j<3; j++) matrix[i][j] =  ' ';
}


			
void get_player_move(int num)		/* ввод хода игрока (1-го или 2-го) */
{
	int x, y;
	if (num==1)
		printf("\nВведите координаты вашего X\n");
	else
		printf("\nВведите координаты вашего O\n");
	printf("Строка: ");
	scanf ("%d", &x);
	printf("Столбец: ");
	scanf("%d", &y);
	x--; y--;
	if (x<0 || y<0 || x>2 || y>2 || matrix[x] [y] !=SPACE)
	{
		printf("Неправильный ход, попробуйте снова.\n");
		get_player_move(num);
	}
		else {
			if (num==1)	matrix[x][y]='X';
				else	matrix[x][y]='O';
		}
}


void get_computer_move(void)			/* ход компьютера */
{
	register int t;
		char *p;
	p = (char *) matrix;
	for (t=0; *p!=SPACE && t<9; ++t) p++;
		if(t==9)
		  {
		    printf("Ничья\n");
		    exit(0); 			/* game over */
		  }
		else *p = 'O';
}


void disp_matrix(void)				/* отображение игровой доски */
{
	int t;
	for(t=0; t<3; t++)
	{
		printf(" %c | %c | %c", matrix[t][0], matrix[t][1], matrix[t][2]);
		if(t!=2) printf("\n---|---|---\n");
	}
	printf("\n");
}


char check(void)				/* проверка на победу */
{
	int t;
	char *p;
	for(t=0; t<3; t++) { 			/* проверка строк */
	p = &matrix[t] [0];
		if (*p==* (p+1) && * (p+1)==*(p+2)) return *p;
		}
			for(t=0; t<3; t++) { 	/* проверка столбцов */
				p = &matrix[0][t];
			if(*p==*(p+3) && *(p+3)==*(p+6)) return *p;
		}

	/* проверка диагоналей */
	if(matrix[0] [0]==matrix [1] [1] && matrix[1] [1]==matrix [2] [2]) return matrix[0][0];
	if(matrix[0] [2]==matrix [1] [1] && matrix[1] [1]==matrix [2] [0]) return matrix[0][2];
	return SPACE;
}
