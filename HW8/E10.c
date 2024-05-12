/*Циклический сдвиг массива вправо на 4
Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента.*/

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
	int a = arr[len - 4]; //сохраняем послед. элемент массива в переменную, чтобы его не потерять после сдвига
	int b = arr[len - 3]; 
	int c = arr[len - 2]; 
	int d = arr[len - 1]; 
	// осуществляем сдвиг начиная с последнего элемента до нулевого
	for (int i = len - 1; i > 0; i--)
	{
		arr[i] = arr[i-4]; 
	}
	arr[0] = a; // присваиваем значение последнего элемента первому
	arr[1] = b;
	arr[2] = c;
	arr[3] = d;
}

int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    ShiftRight(SIZE, arr);
    Print(SIZE,arr);
	return 0;
}

