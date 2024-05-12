//Дано натуральное число N. Посчитать количество «1» в двоичной записи числа. Составить рекурсивную функцию.
#include <stdio.h>
int recursion_convert_to_bin(int n)
{   
	if (n > 0)
    {
        return n % 2 + recursion_convert_to_bin(n / 2);
    }

    return 0;
	
}


int main(void)

{
	int n;
	scanf("%d", &n);
	printf("%d", recursion_convert_to_bin(n));
	return 0;
}
