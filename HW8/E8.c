/*Инверсия каждой трети
Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.*/

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
// функция сортировки массива
void BubbleSort(int len,int arr[])
{
    for (int i = 0; i < len; i++)
    {
		for (int j = 3; j > i; j--)
        {
			SwapArr(arr,j-1,j);
        }
        for (int j = 7; j > 4 && j <= 7 && j > i; j--)
        {
			SwapArr(arr,j-1,j);
        }
        for (int j = len - 1; j > 8 && j > i; j--)
        {
			SwapArr(arr,j-1,j);
        }
    }
}

int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    BubbleSort(SIZE,arr);
    Print(SIZE,arr);
    /*SwapArr(SIZE,arr, 0, 4);
    SwapArr(SIZE,arr, 1, 3);
    SwapArr(SIZE,arr, 5, 9);
    SwapArr(SIZE,arr, 6, 8);
    Print(SIZE,arr);*/
	return 0;
}

