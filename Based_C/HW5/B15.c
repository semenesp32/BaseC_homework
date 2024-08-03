//Дана последовательность ненулевых целых чисел, в конце последовательности число 0. Посчитать количество четных чисел.
#include <stdio.h>

int main(void)
{

    int numbers, count = 0;

    do
    {
        scanf("%d", &numbers);
        if(numbers % 2 == 0)
        {
            count++;
        }
    }
    while (numbers != 0);

    printf("%d", count - 1);
    return 0;
}
