/*Максимум в массиве
Написать только одну функцию, которая находит максимальный элемент в массиве. 
Всю программу загружать не надо.
Прототип функции: int find_max_array(int size, int a[])*/

#include <stdio.h>
#include <inttypes.h>
#define SIZE 100

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
//функция поиска максимального элемента в массиве
int find_max_array(int size, int a[])
{
	int max=a[0];
    for (int i = 1; i < size; i++)
    {
        if(a[i]>max)
            max = a[i];
    }
    return max;
}


/*int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    printf("%d ", find_max_array(SIZE, arr));
	return 0;
}*/

