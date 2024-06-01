/*Массив максимумов
Дана целочисленная квадратная матрица 10 х 10. реализовать алгоритм вычисления суммы максимальных элементов из каждой строки. 
Напечатать значение этой суммы. Предполагается, что в каждой строке такой элемент единственный. 
Реализовать функцию поиска максимума в строке из 10 элементов*/

#include <stdio.h>
#include <inttypes.h>
#define SIZE 10

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

//функция которая находит максимальный элемент в строке в двумерном массиве
void max_in_strings_matrix_2(int n, int m, int a[m][n])
{
	int i, j;
	int max1 = a[0][0];
	int max2 = a[1][0];
	int max3 = a[2][0];
	int max4 = a[3][0];
	int max5 = a[4][0];
	int max6 = a[5][0];
	int max7 = a[6][0];
	int max8 = a[7][0];
	int max9 = a[8][0];
	int max10 = a[9][0];
	for (i = 0; i < m; i++)
	{ 
		for (j = 0; j < n; j++)
		{
			if (a[0][j]>max1)
			{
				max1 = a[0][j];
			}
			if (a[1][j]>max2)
			{
				max2 = a[1][j];
			}
			if (a[2][j]>max3)
			{
				max3 = a[2][j];
			}
			if (a[3][j]>max4)
			{
				max4 = a[3][j];
			}
			if (a[4][j]>max5)
			{
				max5 = a[4][j];
			}
			if (a[5][j]>max6)
			{
				max6 = a[5][j];
			}
			if (a[6][j]>max7)
			{
				max7 = a[6][j];
			}
			if (a[7][j]>max8)
			{
				max8 = a[7][j];
			}
			if (a[8][j]>max9)
			{
				max9 = a[8][j];
			}
			if (a[9][j]>max10)
			{
				max10 = a[9][j];
			}
		}
	}
	printf("%d ", max1+max2+max3+max4+max5+max6+max7+max8+max9+max10);
	//return sum;
	
}

int main() 
{ 
 int a[SIZE][SIZE]; /* двумерный массив*/ 
 InputMatrix(SIZE,SIZE, a);
 max_in_strings_matrix_2(SIZE,SIZE, a);
 return 0; 
}
