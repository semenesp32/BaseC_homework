//Составить рекурсивную функцию, печать всех чисел от 1 до N
#include <stdio.h>
void print_to_screen(int a)
{
	if (a>0)
	{
		print_to_screen(a-1);
		printf("%d ", a);
	}
}

int main(void)

{
	int a;
	scanf("%d", &a);
	print_to_screen(a);
	return 0;
}
