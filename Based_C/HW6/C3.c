//Написать функцию, которая возвращает среднее арифметическое двух переданных ей аргументов (параметров).
#include <stdio.h>
int middle(int a, int b)
{
	int result;
	result = (a+b)/2;
	return result;
}

int main(void)

{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", middle(a, b));
	return 0;
}
