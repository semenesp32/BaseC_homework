//Найти наибольшее из двух чисел и вывести их в порядке возрастания
#include <stdio.h>
int a, b, max, min;

int main(void)

{
	scanf("%d%d",&a, &b);
	if(a>b)
	{
		max = a;
		min = b;
	}
	else
	{
		min = a;
		max = b;
	}

	printf("%d %d", min, max);
	
	return 0;
}
