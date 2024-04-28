//Посчитать количество четных и нечетных цифр числа.
#include <stdio.h>


int main()
{
	
int a, n, chet = 0, nechet = 0;
scanf("%d", &a);

	while (a!=0)
	{
		n = a%10;
		if (n%2 == 1)
		{
			nechet++;
		}
		else
		{
			chet++;
		}
		a/=10;
		
	}
	printf("%d %d", chet, nechet);
	return 0;
}
