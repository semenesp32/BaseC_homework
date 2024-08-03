/*Найти минимум
Ввести c клавиатуры массив из 5 элементов, найти минимальный из них.*/

#include <stdio.h>
#include <inttypes.h>
#define SIZE 5

 //функция ввода массива
int Input(int n,int arr[])
{
int i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    return i;
}

//функция поиска минимума
int Min (int len, int arr[])
{
	int min=arr[0];
	for (int i = 0; i < len; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
	//printf("%d", min);
}


int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    printf("%d", Min(SIZE,arr));
	return 0;
}

