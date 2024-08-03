/*Чаще других
Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего. Гарантируется, что такое число ровно 1.*/

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



//функция поиска чаще всего встречающегося числа
void FindMaxCount (int len, int arr[])
{
	int max_count = 1;
    int num = arr[0];
    for(int i = 0; i < len; i++) // перебираем все элементы массива
    {
        int count = 0; // устанавливаем счетчик в 0
        for(int j = i; j < len; j++) // перебираем все элементы от i до конца
        {
            if(arr[i] == arr[j])// Если элемент [i] совпадает с одним из последующих [j]
            {
                count++; // то увеличиваем значение счетчика
            }
            if(count > max_count)// Если число больше максимального
            {
                max_count = count; // тогда оно максимальное
                num = arr[i]; // присваиваем нулевому элементу массива i-тый
            }
        }
    }
    printf("%d\n", num); // выводим наиболее часто встречающийся элемент
}

int main()
{
	int arr[SIZE]={0};
    Input(SIZE,arr);
    FindMaxCount(SIZE, arr);
    //printf("%d ",FindMaxCount(SIZE, arr));
	return 0;
}

