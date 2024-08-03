/*Четные и нечетные
Дан целочисленный массив из 10 элементов. Необходимо определить количество четных и нечетных чисел. 
Если количество чётных чисел больше, чем количество нечётных, 
заменить каждое нечетное число на произведение нечетных цифр в его десятичной записи. 
Если количество нечётных чисел больше или равно количеству чётных, заменить каждое чётное число 
на произведение чётных цифр в его десятичной записи.*/

#include <stdio.h>
#include <inttypes.h>
#define SIZE 10
int Input(int n,int arr[]);
void Print(int n,int arr[]);
int replace_nechet_to_mult(int size, int a[]);
int replace_chet_to_mult(int size, int a[]);
void find_chet_nechet(int size, int a[]);

int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    //replace_nechet_to_mult(SIZE, arr);
    find_chet_nechet(SIZE,arr);
    Print(SIZE,arr);
	return 0;
}

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
//функция поиска количества четных и нечетных чисел в массиве
void find_chet_nechet(int size, int a[])
{
	int count_chet = 0;
	int count_nechet = 0;
    for (int i = 0; i < size-1; i++)
    {
        if (a[i]%2 == 0)
		{
			count_chet++;
			
		}
		else
		{
			count_nechet++;
		}
    }
    printf("%d ", count_chet);
    printf("%d ", count_nechet);
    if (count_chet > count_nechet)
	{
		replace_nechet_to_mult(size, a);
		//Print(size, a);
		
	}
	else
	{
		replace_chet_to_mult(size, a);
		//Print(size, a);
	}
}
int replace_nechet_to_mult(int size, int a[])
{
	int p, i;
	for (i = 0; i < size; i++)
	{
		if (a[i]%2 !=0)
	{
		while (a[i]!= 0)
		{
			p *= a[i]%10;
			a[i] /=10;
		}
	}
	a[i] = p;
	}
	return a[i];	
}
int replace_chet_to_mult(int size, int a[])
{
	int p, i;
	for (i = 0; i < size; i++)
	{
		if (a[i]%2 ==0)
	{
		while (a[i]!= 0)
		{
			p *= a[i]%10;
			a[i] /=10;
		}
	}
	a[i] = p;
	}
	return a[i];	
}
