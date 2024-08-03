//Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)
//sin(x) = x - x3/3! + x5/5! - x7/7! + ...(x в радианах) float sinus(float x)
#include <stdio.h>
#include <math.h>

#define T 0.0001
#define PI 3.14159265


float sinus(float x);


int main(void)
{
    float x;
    scanf("%f", &x);
    x = x*(PI/180); // переводим в радианы
    printf("%0.3f\n", sinus(x));

    return 0;
}

float sinus(float x)
{
    float x_n = x;
    int n = 1;
    float result = 0.0;

    do
    {
        result += x_n;
        x_n *= -1.0 * x * x / ((2 * n) * (2 * n + 1));
        n++;
    }
    while((x_n >= 0 ? x_n : - x_n) > T);

    return result;
}
