/*Описать функцию вычисления f(x) по формуле:
f(x)= x*x при -2 ≤ x < 2;
x*x+4x+5 при x ≥ 2;
4 при x < -2.
Используя эту функцию для n заданных чисел, вычислить f(x). Среди вычисленных значений найти наибольшее.*/
/*
 * task_6_4.c
 * The program implements the function of calculating f(x) according to the formula:
 *        x*x for -2 ≤ x < 2;
 * f(x) = x*x+4x+5 for x ≥ 2;
 *        4 for x < -2.
 * For n given numbers, calculate f(x). Find the largest among the calculated values.
 * Input format: integers
 * Output format: one integer
 *
 */


#include <stdio.h>
#include <limits.h>
#include <iso646.h>


int function(int x);


int main(void)
{
    //char ch;
    int x;
    int max = - INT_MAX;

    do
    {
        scanf("%d", &x);
        if (function(x) >= max)
        {
            max = function(x);
        }
    }
    while (x!= 0);

    printf("%d ", max);

    return 0;
}


int function(int x)
{
	int result;
    if (x < -2)
    {
        result = 4;
    }
    if ((x >= -2) && (x < 2))
    {
        result = x * x;
    }

    if (x >= 2)
    {
        result = x * x + 4 * x + 5;
    }
    return result;
}
