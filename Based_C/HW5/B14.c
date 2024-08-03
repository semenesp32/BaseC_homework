//Дана последовательность ненулевых целых чисел, в конце последовательности число 0. Посчитать количество чисел.
#include <stdio.h>


int main()
{
	
	int a, count = 0;

	do
	{
		scanf("%d", &a);
		count++;
	} while (a!=0);
		printf("%d", count - 1);
}
