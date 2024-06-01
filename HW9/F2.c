/*Четные в начало
Написать только одну функцию, которая ставит в начало массива все четные элементы, а в конец – все нечетные. 
Не нарушайте порядок следования чисел между собой. Строго согласно прототипу:.void sort_even_odd(int n, int a[])*/

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
//функция сортирующая массив по четным элементам
void sort_even_odd(int n, int a[])
{
	int noSwap;
	for (int i = 0; i < n; i++)
	{
		noSwap = 1;
        for (int j = n-1; j > i; j--)
        {
            if((a[j]%2==0)&& (a[j-1]%2 !=0))
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
    sort_even_odd(SIZE, arr);
    Print(SIZE,arr);
	return 0;
}

