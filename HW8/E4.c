/*Два максимума
Считать массив из 10 элементов и найти в нем два максимальных элемента и напечатать их сумму.*/

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

//функция поиска максимума
int Max (int len, int arr[])
{
	int max=arr[0]; //предположим что макс. это нулевой элемент массива
	//пробегаем весь массив
	for (int i = 0; i < len; i++)
	{
		// если какой-то элемент больше максимума, то он становится максимумом
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	//создаем еще один массив, без максимального элемента из изначального массива,
	// чтобы найти второй максимум в нем
	int arr_new[len]; //новый массив пока той же длины что и старый
	int index_new = 0; // индекс для нового массива
	for (int index = 0; index < len; index++)
	{
		//если элемент из изначального массива не равен максимуму,то добавляем его в новый массив
		// увеличивая идекс нового массива
		if (arr[index] != max) 
		{
			arr_new[index_new++] = arr[index];
		}
	}
	len = index_new; //присваиваем новому массиву новый индекс
	// Аналогично ищем максимальный элемент уже в новом массиве
	int max_new = arr_new[0];
	for (int i = 0; i < len; i++)
	{
		if (arr_new[i] > max_new)
		{
			max_new = arr_new[i];
		}
	}
	// складываем максимумы в обоих массивах
	int sum = max + max_new;
	return sum;
}


int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    //Max (SIZE,arr);
    printf("%d", Max(SIZE,arr));
	return 0;
}

