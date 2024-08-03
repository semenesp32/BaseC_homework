/*В заданном интервале
Составить функцию которая возвращает количество элементов на заданном отрезке [from, to] для массива. 
Прототип функции int count_between(int from, int to, int size, int a[]) 
Например, на отрезке [4, 6] в массиве 1 2 3 4 5 6 7 8 9 10 функция вернет 3 значения*/

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
//функция которая возвращает количество элементов на заданном отрезке [from, to] для массива
int count_between(int from, int to, int size, int a[])
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if ((a[i] >= from)&&(a[i]<=to))
		{
			//printf("yes");
			count++;
		}
		//~ for (int j = from; j <= to; i++)
		//~ {
			//~ count++;
		//~ }
	}
	
	return count;
}



int main()
{
	int arr[SIZE]={0};
	int a, b;
	scanf("%d %d", &a, &b);
    Input(SIZE,arr);
    //count_between(a, b, SIZE, arr);
    printf("%d ", count_between(a, b, SIZE, arr));
    //Print(SIZE, arr);
	return 0;
}

