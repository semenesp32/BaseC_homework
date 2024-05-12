/*Положительные и отрицательные
Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам: в одни помещать только положительные, 
во второй - только отрицательные. Числа, равные нулю, игнорировать. 
Вывести на экран все элементы обоих массивов.*/

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
void Sort (int len, int arr[])
{
	for (int i = 0; i < len; i++)
	{
		int num = arr[i];
		if (num > 0)
		{
			printf("%d ", arr[i]);
		}
		
	}
	for (int i = 0; i < len; i++)
	{
		int num = arr[i];
		
		if (num < 0)
		{
			printf("%d ", arr[i]);
		}
	}
}

int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    Sort(SIZE,arr);
    //printf("%d ",Sort(SIZE,arr));
	return 0;
}

