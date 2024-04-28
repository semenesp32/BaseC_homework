//Ввести целое число и «перевернуть» его, так чтобы первая цифра стала последней и т.д.
#include <stdio.h>


int main()
{
	
int a, n, rev_a=0;
scanf("%d", &a);

	while (a!=0)
	{
		n = a%10;
		a/=10;
		rev_a = rev_a *10 + n;
		
	}
	printf("%d\n", rev_a);
}
