/*Два одинаковых
Написать только одну логическую функцию, которая определяет, 
верно ли, что среди элементов массива есть два одинаковых. 
Если ответ «да», функция возвращает 1; если ответ «нет», то 0. 
Строго согласно прототипу:int is_two_same(int size, int a[]);*/

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
// Функция вывода массива
void Print(int n,int arr[])
{
    for(int i=0;i<n;i++)
        printf("%5d",arr[i]);
    printf("\n");
}
//функция поиска 2х одинаковых элементов в массиве
int is_two_same(int size, int a[])
{
	//int flag;
	//int i, j;
    for (int i = 0; i < size-1; i++)
    {
		//flag = a[i]=a[i-1]?1:0;
			for (int j = i+1; j < size; j++)
			{
				if (a[i]==a[j])
				{
					return 1;
				}
			}
		}
    return 0;
}



int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    printf("%d ", is_two_same(SIZE, arr));
	return 0;
}

