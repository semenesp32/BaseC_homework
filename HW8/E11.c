/*Отсортировать по последней цифре
Считать массив из 10 элементов и отсортировать его по последней цифре.*/

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
//функция вывода массива
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
//функция сортировки массива по последней цифре
void BubbleSort(int len,int arr[])
{
    int noSwap;
    for (int i = 0; i < len; i++)
    {
        noSwap = 1;
        for (int j = len-1; j > i; j--)
        {
            if(arr[j] % 10 < arr[j-1] % 10)
            {
                SwapArr(arr,j-1,j);
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
    BubbleSort(SIZE,arr);
    Print(SIZE,arr);
	return 0;
}

