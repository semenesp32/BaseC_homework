/*Среднее арифметическое массива
Считать массив из 12 элементов и посчитать среднее арифметическое элементов массива.*/

#include <stdio.h>
#include <inttypes.h>
#define SIZE 12

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
//функция вычисления среднего арифмтического
void Middle (int len, int arr[])
{
	float sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum = sum + arr[i];
	}
	float middle = (sum/len);
	printf("%.2f", middle);
}


int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    //Print(SIZE,arr);
    Middle(SIZE, arr);
	return 0;
}

