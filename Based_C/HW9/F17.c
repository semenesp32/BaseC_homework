/*След матрицы
Составить функцию которая находит след матрицы в двумерном массиве. Показать пример ее работы на матрице из 5 на 5 элементов. 
След матрицы - это сумма элементов на главной диагонали.*/

#include <stdio.h>
#include <inttypes.h>
#define SIZE 5

 //функция ввода двумерного массива
void InputMatrix(int n, int m,int arr[m][n])
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
}
//~ // Функция вывода двумерного массива
void PrintMatrix(int n, int m,int arr[m][n])
{
	putchar('\n');
    int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d\t",arr[i][j]);
			putchar('\n');
		}
		printf("\n");
	}
}

//~ //функция которая находит след матрицы в двумерном массиве
int sled_matrix_2(int n, int m, int a[m][n])
{
	int i, j;
	int sum = 0;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if ((i+1)==(j+1))
			{
				sum = sum + a[i][j];
			}
		}
	}
	return sum;
	
}

int main() 
{ 
 //const int m = 5, n = 5; /* размер массива */ 
 int a[SIZE][SIZE]; /* двумерный массив с типом -- действительное число двойной точности */ 
 InputMatrix(SIZE,SIZE, a);
 //PrintMatrix(SIZE,SIZE, a);

 printf("%d ", sled_matrix_2(SIZE,SIZE, a));
 return 0; 
}
