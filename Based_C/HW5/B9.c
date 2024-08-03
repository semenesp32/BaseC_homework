//Ввести целое число и определить, верно ли, что все его цифры четные.
#include <stdio.h>


int main()
{
	
int a, n, flag = 0;
scanf("%d", &a);

	while (a!=0)
	{
		n = a%10;
		if (n%2 == 1)
		{
			flag = 1;
		}
		a/=10;
	}
	
	if (flag == 1)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
	return 0;
}
