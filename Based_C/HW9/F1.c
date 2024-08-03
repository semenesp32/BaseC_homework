/*Сортировка по взрастанию
Написать только одну функцию, которая сортирует массив по возрастанию. Необходимо реализовать только одну функцию, всю программу составлять не надо.
Строго согласно прототипу. Имя функции и все аргументы должны быть: void sort_array(int size, int a[]).*/

#include <stdio.h>
#include <inttypes.h>
#define SIZE 20

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
//функция сортирующая массив по возрастанию
void sort_array (int size, int a[])
{
	int noSwap;
	for (int i = 0; i < size; i++)
	{
		noSwap = 1;
        for (int j = size-1; j > i; j--)
        {
            if(a[j] < a[j-1])
            {
                SwapArr(a,j-1,j);
                noSwap = 0;
            }
		}
		if(noSwap)
            break;
	}
}


int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    sort_array(SIZE, arr);
    Print(SIZE,arr);
	return 0;
}

