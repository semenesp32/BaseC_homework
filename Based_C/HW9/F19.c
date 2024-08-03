/*Больше среднего
Определить количество положительных элементов квадратной матрицы, превышающих по величине среднее 
арифметическое всех элементов главной диагонали. 
Реализовать функцию среднее арифметическое главной диагонали.*/

#include <stdio.h>
#include <inttypes.h>
#define SIZE 5
float a_mean = 0;
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

//функция которая находит среднее арифметическое всех элементов на главной диагонали в двумерном массиве
float arithmetic_mean_matrix_2(int n, int m, int a[m][n])
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
	a_mean = sum/SIZE;
	return a_mean;
	
}
// функция вывода кол-ва элементов матрицы, которые больше среднеарифметического главной диагонали
int positive_elements(int n, int m, int a[m][n])
{
	int i, j;
	int count = 0;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j]> a_mean)
			{
				count++;
			}
		}
	}
	return count;	
}

int main() 
{ 
 int a[SIZE][SIZE]; /* двумерный массив*/ 
 InputMatrix(SIZE,SIZE, a);
 arithmetic_mean_matrix_2(SIZE,SIZE, a);
 printf("%d ", positive_elements(SIZE,SIZE, a));
 return 0; 
}
