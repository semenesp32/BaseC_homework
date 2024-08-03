//Составить функцию вычисления N!. Использовать ее при вычислении факториала int factorial(int n)
#include <stdio.h>
long factorial(int n)
{
	long i;
	for (i = 1; n > 1; n--)
	{
		i = i*n;
	}
	return i;
}

int main(void)

{
	int n;
	scanf("%d", &n);
	printf("%ld", factorial(n));
	return 0;
}
