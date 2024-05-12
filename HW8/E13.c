/*Вторая с конца ноль
Считать массив из 10 элементов и отобрать в другой массив все числа, у которых вторая с конца цифра (число десятков) – ноль.*/

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
		int num = arr[i] / 10 % 10;
		if (num == 0)
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

