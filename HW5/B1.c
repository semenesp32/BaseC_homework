//Ввести натуральное число вывести квадраты и кубы всех чисел от 1 до этого числа. Число не превосходит 100.
#include <stdio.h>
int a;

int main(void)

{
	scanf("%d",&a);
	if(a<=100)
	{
		for (int i = 1; i <= a; i++)
		{
			int p = i*i;
			int k = p*i;
			printf("%d %d %d\n", i, p, k);
		}
	}
}
