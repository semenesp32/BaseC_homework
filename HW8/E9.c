/*Циклический сдвиг массива вправо
Считать массив из 10 элементов и выполнить циклический сдвиг ВПРАВО на 1.*/

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
//функция циклического сдвига массива вправо на 1
void ShiftRight(int len, int arr[])
{
	int t = arr[len - 1]; //сохраняем послед. элемент массива в переменную, чтобы его не потерять после сдвига
	// осуществляем сдвиг начиная с предпоследнего элемента (9-го в данном случае) до нулевого
	for (int i = len - 2; i >= 0; i--)
	{
		arr[i+1] = arr[i]; //следующий элемент равен предыдущему
	}
	arr[0] = t; // присваиваем значение последнего элемента первому
}

int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    ShiftRight(SIZE, arr);
    Print(SIZE,arr);
	return 0;
}

