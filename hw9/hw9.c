
#include <stdio.h>
#include <time.h>

#define N 100000

	int i, j, n;
    int a[N];
	int *p;
    clock_t start, stop;

void b_sort(void); void q_sort(int *s_arr, int first, int last);




 
/*******************************************************************************/
void  b_sort (void) {					// Сортировка методом пузырька
start = clock ();
    for(i = 0 ; i < N - 1; i++) { 
       // сравниваем два соседних элемента.
       for(j = 0 ; j < N - i - 1; j++) {  
           if(a[j] > a[j+1]) {           
              int tmp = a[j];
              a[j] = a[j+1] ;
              a[j+1] = tmp; 
           }
        }

    }
stop = clock ();
printf("Метод пузырька требует %f секунд\n", (double) (stop - start)/CLOCKS_PER_SEC);

}

/*******************************************************************************/

void q_sort(int *s_arr, int first, int last)   // Сортировка методом быстрой сортировки
{
 
 if (first < last)
    {
        int left = first, right = last, middle = s_arr[(left + right) / 2];
        do
        {
            while (s_arr[left] < middle) left++;
            while (s_arr[right] > middle) right--;
            if (left <= right)
            {
                int tmp = s_arr[left];
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        q_sort(s_arr, first, right);
        q_sort(s_arr, left, last);
    }

}

/*******************************************************************************/

void min_sort() {					// Сортировка методом поиска минимума
int x[N];
long i, j, k;
start = clock ();
	for( i=0; i < N; i++) {  	// i - номер текущего шага
			k=i; x[i]=a[i];
		for( j=i+1; j < N; j++)   // цикл выбора наименьшего элемента
			if ( a[j] < x[i] ) {
				k=j; x[i]=a[j];			// k - индекс наименьшего элемента
			}
			a[k] = a[i]; 
			a[i] = x[i];		// меняем местами наименьший с a[i]
		}
stop = clock ();
printf("Метод сортировки поиском минимума требует %f секунд\n", (double) (stop - start)/CLOCKS_PER_SEC);
}
/*******************************************************************************/


 int main() 
 {
 p = a;
srand(time(NULL));

    for(i = 0 ; i < N; i++) { 
        a[i] = rand()%100;
    }

	b_sort();
start = clock ();  	
	q_sort(a, 0 ,N-1);
stop = clock ();
	printf("Метод быстрой сортировки требует %f секунд\n", (double) (stop - start)/CLOCKS_PER_SEC);
	min_sort();
return 0;
 }
