#include <iostream>
#include <unistd.h>
#define SPACE ' '

using namespace std;  



class    Game
        {
	    char matrix[3][3];
    public:
	void init_matrix (void); 
        void disp_matrix(void);
        void get_computer_move(void);
        void get_player_move(int num);
        char check (void);

	Game() {init_matrix(); disp_matrix();}        
	~Game() {}
        };


                                                                      
void Game::init_matrix(void)
{
    for(int i=0; i<3; i++)
    	for(int j=0; j<3; j++) matrix[i][j] =  SPACE;
}

void Game::get_player_move(int num)                              /* ввод хода игрока (1-го или 2-го) */
{
	int  x,  y;
	if (num==1)
	        cout << "\nВведите координаты вашего X \n" ;
	else
	        cout << "\nВведите координаты вашего O \n" ;
	cout << "Строка: " ;
	cin >> x;
	cout << "Столбец: ";
	cin >> y;
	x--; y--;
	if (x<0 || y<0 || x>2 || y>2 || matrix[x][y] !=SPACE)
	    {	
                cout << "Неправильный ход, попробуйте снова\n";
		get_player_move(num);
	    }
        else {
		    if (num==1)  matrix[x][y]='X';
		          else   matrix[x][y]='O';
		}
}

void  Game::get_computer_move(void)                             /* ход компьютера */
{
	int t;
	char *p;
	p = (char *) matrix;
	for (t=0; *p!=SPACE && t<9; ++t) p++;
		if(t==9)
		  {
		    cout << "Ничья \n";
		    sleep (5);
		    exit (0);                             	/* конец игры */
		  }
		else *p = 'O';
}

void Game::disp_matrix(void)                                    /* отображение игровой доски */
{
	int t;
	for(t=0; t<3; t++)
	{
		cout <<" "<< matrix[t][0] <<" | "<< matrix[t][1] << " | " << matrix[t][2];
		if(t!=2) cout << "\n---|---|---\n";
	}
	cout << "\n";
}

/******************************************************************************************************/

char Game::check(void)                                           /* проверка на победу */
{
	int t;
	char *p;
	for(t=0; t<3; t++) { 					 /* проверка строк */
	p = &matrix[t][0];
		if (*p==* (p+1) && * (p+1)==*(p+2)) return *p;
		}
			for(t=0; t<3; t++) { 			/* проверка столбцов */
				p = &matrix[0][t];
			if(*p==*(p+3) && *(p+3)==*(p+6)) return *p;
		}

	/* проверка диагоналей */
	if(matrix[0][0]==matrix [1][1] && matrix[1][1]==matrix [2][2]) return matrix[0][0];
	if(matrix[0][2]==matrix [1][1] && matrix[1][1]==matrix [2][0]) return matrix[0][2];
	return SPACE;
}

int main()
{
	
	char done;
	int cas, step = 0, num1 = 1, num2 = 2;
	
	cout << "Игра крестики-нолики.\n";
	  cout << "Выберите тип игры:\n";
	  cout << "1. Игра против компьютера.\n";
	  cout << "2. Игра двух игроков.\n";
	  cout << "3. Выйти из игры.\n";
	  Game G;
	  cin >> cas;
	  if (cas==1) {
		cout << "Вы будете играть против компьютера.\n";
		done = SPACE;
			do {
				G.disp_matrix(); 		/* вывод игровой доски */
				G.get_player_move(cas); 	/* ходит игрок */
				done = G.check(); 		/* проверка на победу */
			if (done!=SPACE) break; 		/* победитель */
			 	G.get_computer_move(); 		/* ходит компьютер */
			 	done=G.check(); 		/* проверка на победу */
			} while(done==SPACE);
				if(done=='X') cout << "Вы выиграли!\n";
				  else cout << "Я выиграл!!!!\n";
					G.disp_matrix(); 	/* отображение результирующего положения */
		} 

		else if (cas==2){
		cout << "Игра двух игроков.\n";
		cout << "Игрок 1 играет крестиками, игрок 2 - ноликами.\n";
		done = SPACE;
			do {	
				G.disp_matrix(); 		/* вывод игровой доски */
				G.get_player_move(num1); 	/* ходит 1-й игрок */
				done = G.check(); 		/* проверка на победу */
				G.disp_matrix();
				step++;
								//cout << step <<"\n";
			if((step > 8) && (done !='X')) {  
				cout << "Ничья\n"; break;}		
			if (done!=SPACE) break; 		/* победитель */
			 	G.get_player_move(num2); 	/* ходит 2-й игрок */
			 	done= G.check();		/* проверка на победу */
				step++;
								
			} while(done==SPACE);
				//G.disp_matrix(); 		/* отображение результирующего положения */
					if(done=='X') cout << "Вы выиграли!\n";
					  else if(done=='O') cout << "Игрок 2 выиграл!\n";
								
			}			
		else exit(0);
return 0;
}

