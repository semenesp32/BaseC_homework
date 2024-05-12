//Составить рекурсивную функцию, Выведите все числа от A до B включительно, 
//в порядке возрастания, если A < B, или в порядке убывания в противном случае.

#include <stdio.h>
void recursion_print_to_screen(int a, int b)
{
	printf("%d ", a);
	if (a>b)
	{
		recursion_print_to_screen(a-1, b);
	}
	
	if (a<b)
	{
		recursion_print_to_screen(a+1, b);
	}
}

int main(void)

{
	int a, b;
	scanf("%d%d", &a, &b);
	recursion_print_to_screen(a, b);
/*for (int i = a; i <= b; i++)
{
	printf("%d ", i);
}*/
	return 0;
}
