//Составить функцию, которая вычисляет косинус как сумму ряда (с точностью 0.001)
//cos(x) = 1 - x2/2! + x4/4! - x6/6! + ... (x в радианах) float cosinus(float x)
#include <stdio.h>
#include <math.h>

#define T 0.0001
#define PI 3.14159265


float cosinus(float x);


int main(void)
{
    float x;
    scanf("%f", &x);
    x = x*(PI/180); // переводим в радианы
    printf("%0.3f\n", cosinus(x));

    return 0;
}

float cosinus(float x)
{
    float x_n = 1;
    int n = 1;
    float result = 0.0;

    do
    {
        result += x_n;
        x_n *= -1.0 * x * x / ((2 * n)*(2 * n - 1));
        n++;
    }
    while((x_n >= 0 ? x_n : - x_n) > T);

    return result;
}
