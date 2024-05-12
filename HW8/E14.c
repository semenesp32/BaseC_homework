/*Более одного раза
Считать массив из 10 элементов и выделить в другой массив все числа, которые встречаются более одного раза. 
В результирующем массиве эти числа не должны повторяться.*/

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

//функция поиска максимума
void Sort (int len, int arr[])
{
	for (int i = len - 1; i >= 0; i--)
	{
		//int num = arr[i];
		if (arr[i] == arr[i-1]|| arr[i] == arr[i-2] || arr[i] == arr[i-3] || arr[i] == arr[i-4]|| 
		arr[i] == arr[i-5] || arr[i] == arr[i-6] || arr[i] == arr[i-7] || arr[i] == arr[i-8] || arr[i] == arr[i-9])
		{
			printf("%d ", arr[i]);
		}
	}
}

int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    Sort(SIZE,arr);
    //printf("%d ",Sort(SIZE,arr));
	return 0;
}

