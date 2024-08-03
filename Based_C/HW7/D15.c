/*Дана последовательность ненулевых целых чисел, завершающаяся числом 0. 
Ноль в последовательность не входит. 
Определите наибольшее значение числа в этой последовательности. 
Для решения задачи необходимо написать рекурсивную функцию вида:int max_find(int max)*/
#include <stdio.h>
#include <limits.h>


int max_find(int max);


int main(void)
{

    printf("%d\n", max_find(INT_MIN));

    return 0;
}


int max_find(int max)
{
    int num;
    scanf("%d", &num);

    if (num == 0)
    {
        return max;
    }
    else if (num > max)
    {
        return max_find(num);
    }
    else
    {
        return max_find(max);
    }
}
