//Ввести два целых числа a и b (a ≤ b) и вывести сумму квадратов всех чисел от a до b.
#include <stdio.h>
int a,b,sum;
int main(void)
{
	scanf("%d%d",&a,&b);
	do
	{
		sum+=a*a;
		a++;
	}
	while(a<=b);
	printf("%d ",sum);
		return 0;
}
