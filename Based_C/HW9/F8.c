/*Пропущенное число
В последовательности записаны целые числа от M до N ( M меньше N, M больше или равно 1)
в произвольном порядке, но одно из чисел пропущено (остальные встречаются ровно по одному разу). 
N не превосходит 1000. Последовательность заканчивается числом 0. Определить пропущенное число.*/

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
        for (int j = i+1; j < size; j++)
        {
            if(a[i] > a[j])
            {
                SwapArr(a,i,j);
                noSwap = 0;
            }
		}
		if(noSwap)
            break;
	}
}
// функция поиска пропущенного числа
int find_number(int size, int a[])
{
	for (int i = 0; i < size-1; i++)
	{
		if ((a[i]+1)!= a[i+1])
		{
			return a[i]+1;
			break;
		}
	}
	return 0;
}

int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    sort_array(SIZE, arr);
    printf("%d",find_number(SIZE, arr));
	return 0;
}

