//Перевести натуральное число в двоичную систему счисления. Необходимо реализовать рекурсивную функцию.
#include <stdio.h>
int recursion_convert_to_bin(int n)
{
	int digit;
	int place_number = 1;
    int result = 0;
    
	while (n > 0)
	{
		digit  = n % 2;
		result += digit * place_number;
        place_number *= 10;
		n = n/2;
		recursion_convert_to_bin(n);
	}
	return result;
	
}


int main(void)

{
	int n;
	scanf("%d", &n);
	printf("%d", recursion_convert_to_bin(n));
	return 0;
}
