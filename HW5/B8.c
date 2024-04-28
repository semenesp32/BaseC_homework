//Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9».
#include <stdio.h>


int main()
{
	
int a, n, flag = 0;
scanf("%d", &a);

	while (a!=0)
	{
		n = a%10;
		if (n == 9)
		{
			flag++;
		}
		a/=10;
	}
	
	if (flag == 1)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}
