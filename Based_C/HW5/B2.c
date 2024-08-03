//Ввести два целых числа a и b (a ≤ b) и вывести квадраты всех чисел от a до b.
#include <stdio.h>
int a, b;

int main(void)

{
	scanf("%d%d",&a, &b);
	for (int i = a; i <= b; i++)
	{
		int p = i*i;
		printf("%d ", p);
	}
}
