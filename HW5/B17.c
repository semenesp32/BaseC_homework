//Ввести натурально число и напечатать все числа от 10 до введенного числа - у которых сумма цифр равна произведению цифр
#include <stdio.h>


int main()
{
	
	int a, sum, p;
	scanf("%d", &a);

	for (int i = 10; i <= a; i++)
	{
		int count = i;
		sum = 0;
		p = 1;
		
		while (count >  0)
		{
			sum += count % 10;
			p *= count % 10;
			count /= 10;
		
		}
		if (sum == p)
		{
			printf("%d ", i);
		}
	}
	return 0;
}
