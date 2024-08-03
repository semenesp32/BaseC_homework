//Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N
#include <stdio.h>
int sum = 0;
int recursion_sum(int n)
{
	if (n < 0)
	{
		return 1;
	}
	sum = sum + n;
	recursion_sum(n-1);
	return  sum;
	
}


int main(void)

{
	int n;
	scanf("%d", &n);
	recursion_sum(n);
	printf("%d", sum);
	return 0;
}
