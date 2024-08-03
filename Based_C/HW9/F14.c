/*Сумма в интервале
Составить функцию которая возвращает сумму элементов в заданном отрезке [from, to] для массива. 
Прототип функции int sum_between_ab(int from, int to, int size, int a[])*/

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

//функция которая возвращает сумму элементов в заданном отрезке [from, to] для массива
int sum_between_ab(int from, int to, int size, int a[])
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (((a[i] >= from)&&(a[i]<=to))||((a[i] >= to)&&(a[i]<=from)))
		{
			sum = sum + a[i];
		}
		//~ for (int j = from; j <= to; i++)
		//~ {
			//~ count++;
		//~ }
	}
	
	return sum;
}



int main()
{
	int arr[SIZE]={0};
	int a, b;
	scanf("%d %d", &a, &b);
    Input(SIZE,arr);
    //sum_between_ab(a, b, SIZE, arr);
    printf("%d ", sum_between_ab(a, b, SIZE, arr));
    //Print(SIZE, arr);
	return 0;
}

