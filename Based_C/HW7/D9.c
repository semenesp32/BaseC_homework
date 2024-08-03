//Дано натуральное число N. Вычислите сумму его цифр. Необходимо составить рекурсивную функцию.int sum_digits(int n)
#include <stdio.h>
int sum_digits(int n)
{
	int sum = 0;
	if (n > 0)
    {
        sum = n % 10 + sum_digits(n / 10);
        return sum;
    }
    else
    {
        return 0;
    }
}

int main(void)

{
	int n;
	scanf("%d", &n);
	printf("%d", sum_digits(n));
	return 0;
}
