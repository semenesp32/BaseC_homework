//Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.
#include <stdio.h>
int n, m;
int main(void)
{
	scanf("%d",&n);
	while(n != 0)       //цикл чтобы найти количество цифр в числе
    {
        n = n / 10;
        m++;
    }
    if (m == 3)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
}
