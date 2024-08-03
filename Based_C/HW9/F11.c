/*Сумма минимальна
Дан целочисленный массив из 30 элементов. Элементы массива могут принимать произвольные целые значения помещающиеся в int. 
Необходимо создать функцию, которая находит и выводит в порядке возрастания номера двух элементов массива,
сумма которых минимальна.*/

#include <stdio.h>
#include <inttypes.h>
#define SIZE 30

 //функция ввода массива
int Input(int n,int arr[])
{
int i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    return i;
}
void PosMin2(int len,int arr[])
{
    int min1 = 0;
	for (int i = 1; i < len; i++) 
	{
		if (arr[i] < arr[min1]) 
		{//первый минимальный элемент
				min1 = i;
		}
	}

int min2 = min1 == 0? 1: 0;
	for (int i = 0; i < len; i++) 
	{
		if (i != min1 && arr[i] < arr[min2]) 
		{// второй минимальный элемент
			min2 = i;
		}
	}
printf ("%d %d", min1, min2);
}

int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    PosMin2(SIZE, arr);
	return 0;
}
