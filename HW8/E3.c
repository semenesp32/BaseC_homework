/*Максимум и минимум
Считать массив из 10 элементов и найти в нем максимальный и минимальный элементы и их номера.*/

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

int Min(int len,int arr[])
{
    int min=arr[0];
    for (int i = 1; i < len; i++)
    {
        if(arr[i]<min)
            min = arr[i];
    }
    return min;
}

int Max(int len,int arr[])
{
    int max=arr[0];
    for (int i = 1; i < len; i++)
    {
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}

int PosMin(int len,int arr[])
{
    int min=arr[0],pos=0;
    for (int i = 1; i < len; i++)
    {
        if(arr[i]<min)
        {
            min = arr[i];
            pos = i;
        }
    }
    return pos;
}

int PosMax(int len,int arr[])
{
    int max=arr[0],pos=0;
    for (int i = 1; i < len; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
            pos = i;
        }
    }
    return pos;
}


int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    printf("%d ", PosMax(SIZE,arr));
    printf("%d ", Max(SIZE,arr));
    printf("%d ", PosMin(SIZE,arr));
    printf("%d ", Min(SIZE,arr));
    
    //Max(SIZE,arr);
	return 0;
}

