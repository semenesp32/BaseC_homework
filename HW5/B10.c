//Ввести целое число и определить, верно ли, что все его цифры расположены в порядке возрастания.
#include <stdio.h>


int main()
{
	
int a, n, n2, flag =0;
scanf("%d", &a);

	while (a!=0)
	{
		n = a%10;
		n2 = (a/10)%10;
		if (n <= n2)
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
}
