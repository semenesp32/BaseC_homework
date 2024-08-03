//Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования.
#include <stdio.h>
int f_sum(int n)
{
	int sum;
	for (int i = 1; i <= n; i++)
	{
		sum = sum + i;
	}
	return sum;
}

int main(void)

{
	int n;
	scanf("%d", &n);
	printf("%d", f_sum(n));
	return 0;
}
