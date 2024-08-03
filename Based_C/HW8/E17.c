/*Только один раз
Дан массив из 10 элементов. В массиве найти элементы, которые в нем встречаются только один раз, и вывести их на экран.*/

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

//функция поиска чисел, встречающихся только 1 раз
int FindCountOne(int len, int arr[], int new_arr[])
{
    int count = 0;

    for(int i = 0; i < len; i++)
    {
        int flag = 1;
        for(int j = 0; j < len; j++)
        {
            if(arr[i] == arr[j] && i != j)
            {
                flag = 0;
            }
        }
        if(flag == 1)
        {
        new_arr[count++] = arr[i];
        }
    }

    return count;
}

int main(void)
{
    int arr[SIZE];
    int new_arr[SIZE];

    Input(SIZE, arr);
    Print(FindCountOne(SIZE, arr, new_arr), new_arr); 

}




