//Даны стороны треугольника a, b, c. Определить существует ли такой треугольник.
#include <stdio.h>
int a, b, c;

int main(void)

{
	scanf("%d%d%d",&a, &b, &c);
	if(((a+b)<=c)||((a+c)<=b)||((b+c)<=a))
	{
		printf("NO");
	}
	else
	{
		printf("YES");
	}
}
