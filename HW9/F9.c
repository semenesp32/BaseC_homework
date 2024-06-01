/*Поменять местами
Составить только функцию которая в массиве находит максимальный из отрицательных элементов и меняет его местами 
с последним элементом массива. Гарантируется, что в массиве только один такой элемент или же такой элемент отсутствует. 
Если отрицательных элементов нет - массив не менять.
Прототип функции: void swap_negmax_last(int size, int a[])*/

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
void SwapArr(int arr[],int i,int j)
{
		int temp = arr[i];
		arr[i]   = arr[j];
		arr[j]   = temp;
}
//функция поиска максимального элемента в массиве
void swap_negmax_last(int size, int a[])
{
	int pos = 0;
	int negmax = a[0];
	int i;
	for (i=0;i<size;i++)
	{
		if ((negmax > -1) && (a[i] < 0))
		{
			negmax = a[i];
			pos = i;//запоминание позиции первого отрицательного числа
		}
		else if ((negmax < a[i]) && (a[i]< 0))
		{
			negmax = a[i];
			pos = i;
		}
	}
	
	if (negmax < 0)
	{
		SwapArr(a, size-1, pos);
	}
}


/*int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    swap_negmax_last(SIZE,arr);
    Print(SIZE, arr);
	return 0;
}*/
