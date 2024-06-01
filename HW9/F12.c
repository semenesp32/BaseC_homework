/*Поменять местами
Составить функцию которая меняет в массиве минимальный и максимальный элемент местами. 
* Прототип функции void change_max_min(int size, int a[])*/

#include <stdio.h>
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
//функция перестановки одного элемента с другим
void SwapArr(int arr[],int i,int j)
{
		int temp = arr[i];
		arr[i]   = arr[j];
		arr[j]   = temp;
}
//функция которая меняет в массиве минимальный и максимальный элемент местами
void change_max_min(int size, int a[])
{
	//int flag;
	//int i, j;
	int min = a[0], pos_min = 0;
    for (int i = 1; i < size; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
			pos_min = i;
		}
	}
	int max = a[0], pos_max = 0;
	for (int i = 1; i < size; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			pos_max = i;
		}
	}
    SwapArr(a, pos_min, pos_max);
}



int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    change_max_min(SIZE, arr);
    Print(SIZE, arr);
	return 0;
}

