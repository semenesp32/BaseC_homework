/*
 * task_8_18.c
 * Кратность прежде всего
 * В диапазоне натуральных чисел от 2 до N определить,
 * сколько из них кратны любому из чисел в диапазоне от 2 до 9.
 * Input format: Одно целое число N большее 2 и не превосходящее 10000
 * Output format: Все числа от 2 до 9 в формате: 2 количество чисел кратных 2
 * 3 количество чисел кратных 3 и т.д.
 *
 */

#include <stdio.h>


void arr_search_all_divisors(void);                                     //function for task_8_18.c


int main(void)
{
    arr_search_all_divisors();                                          //function for task_8_18.c
}


/*********************task_8_18.c********************************/
/*The function prints an array of natural numbers from 2 to N,
 * and calculates how many of them are multiples
 * of any number in the range from 2 to 9*/
void arr_search_all_divisors(void)
{
    int num;

    scanf("%d", &num);

    int count[8] = {0};
    for(int i = 2; i <= num; i++)
    {
        for(int j = 2; j <= 9; j++)
        {
            if(i % j == 0)
            {
                count[j - 2]++;
            }

        }
    }

    for(int i = 0; i < 8; i++)
    {
        printf("%d %d\n", i + 2, count[i]);
    }
}





