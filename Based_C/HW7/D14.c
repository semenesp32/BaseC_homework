//Дана последовательность целых чисел через пробел, завершающаяся числом 0. 
//Выведите все нечетные числа из этой последовательности, сохраняя их порядок. Составить рекурсивную функцию.
#include <stdio.h>
void recursion_print_nechet(void)
{
	int n;
	scanf("%d", &n);
	if (n!=0)
	{
		if (n%2 != 0)
		{
			printf("%d ", n);
			recursion_print_nechet();
			
		}
		else
		{
			recursion_print_nechet();
		}
	}
}

int main(void)

{
	recursion_print_nechet();
	return 0;
}
