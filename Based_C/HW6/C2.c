//Составить функцию, возведение числа N в степень P. int power(n, p) и привести пример ее использования.
#include <stdio.h>
int power(int n, int p)
{
	int result = 1;
	int i;
	if (p == 0)
	{
		result = 1;
	}
	for (i = 1; i <= p; i++)
	{
		result = result*n;
	}
	return result;
}

int main(void)

{
	int n, p;
	scanf("%d%d", &n, &p);
	printf("%d", power(n, p));
	return 0;
}
