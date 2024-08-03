//Ввести целое число и найти сумму его цифр.
#include <stdio.h>
int n, sum;
int main(void)
{
	scanf("%d",&n);
	while(n != 0)
	{    
		sum = sum +n%10;
        n= n / 10;
	}
	printf("%d\n", sum);
}
