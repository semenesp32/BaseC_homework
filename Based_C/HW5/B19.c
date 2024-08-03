//Ввести натуральное число и определить, верно ли, что сумма его цифр равна 10.
#include <stdio.h>


int main()
{
	int n, sum = 0;
	scanf("%d",&n);
	while(n != 0)
	{    
		sum = sum +n%10;
        n= n / 10;
	}
	if (sum == 10)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
}
