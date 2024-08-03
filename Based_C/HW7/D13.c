//Составить рекурсивную функцию, печать всех простых множителей числа.
#include <stdio.h>
void recursion_print_simple(int n, int k)
{
	if (n==1)
	{
		return;
	}
	
	if(k > n / 2)
    {
        printf("%d ", n);
        return;
    }

    if(n % k == 0)
    {
        printf("%d ", k);
        recursion_print_simple(n / k, k);
    }
    else
    {
        recursion_print_simple(n, ++k);
    }
}

int main(void)

{
	int n;
	scanf("%d", &n);
	recursion_print_simple(n, 2);
	return 0;
}
