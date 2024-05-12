/*Сумма положительных элементов
Считать массив из 10 элементов и посчитать сумму положительных элементов массива.*/

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

//функция поиска минимума
void Sum_p (int len, int arr[])
{
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > 0)
		{
			sum = sum + arr[i];
		}
	}
	printf("%d", sum);
}


int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    Sum_p(SIZE, arr);
	return 0;
}

