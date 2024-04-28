//Составить функцию, печать всех простых множителей числа. Использовать ее для печати всех простых множителей числа. void print_simple(int n)
#include <stdio.h>
void print_simple(int n)
{
	int d=2;
	while (n!=1)
	{
		if (n%d == 0)
		{
			printf("%d ", d);
			n = n/d;
		}
		else
		{
			d += 1;
		}
	}
}

int main(void)

{
	int n;
	scanf("%d", &n);
	print_simple(n);
	return 0;
}
