
/** Code by Uspensky *****/

/**************************************************************************************/
/*                 Программа вычисления площади круга 		  	                      */	
/**************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include "h.h" 

typedef  float  fl;
volatile fl	R;
 
fl S;

fl	Area_Circle (fl R){	/*  Функция вычисления площади круга */
	S = Pi*R*R;
	return S;
}

int main () {

		printf("Программа вычисления площади круга\n Введите радиус окружности R, в см.:"); 	
label:	
		scanf("%f", &R);
		printf("Ввод R: %.2f\n", R);
		if ( R < 0 ){
				printf ("Радиус отрицательный, введите положительный радиус:");
		  	goto label;
		}
		printf ("Площадь круга: %.5g см2", Area_Circle(R));
 			
		
getchar(); getchar();
	return 0;
} 


