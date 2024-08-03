/*Больше по модулю
Составить функцию которая определяет в массиве, состоящем из положительных и отрицательных чисел, 
сколько элементов превосходят по модулю максимальный элемент. 
Прототип функции int count_bigger_abs(int n, int a[]); */

#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#define SIZE 10

 //функция ввода массива
int Input(int n,int arr[])
{
	
int i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    return i;
}
// Функция вывода массива
void Print(int n,int arr[])
{
    for(int i=0;i<n;i++)
        printf("%5d",arr[i]);
    printf("\n");
}

/*функция которая определяет в массиве, состоящем из положительных и отрицательных чисел, 
сколько элементов превосходят по модулю максимальный элемент*/
int count_bigger_abs(int n, int a[])
{
	int count = 0;
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i]> max)
		{
			max = a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (abs(a[i]) > max)
		{
			count++;
		}
	}
	return count;
}



int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    printf("%d ", count_bigger_abs(SIZE, arr));
	return 0;
}

