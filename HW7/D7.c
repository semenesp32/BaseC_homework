//Составить рекурсивную функцию, печать всех чисел от N до 1.
#include <stdio.h>
void recursion_print_to_screen(int n)
{
	if (n == 0)
	{
		return;
	}
		printf("%d ", n);
		recursion_print_to_screen(n-1);
}

int main(void)

{
	int a;
	scanf("%d", &a);
	recursion_print_to_screen(a);
	return 0;
}
