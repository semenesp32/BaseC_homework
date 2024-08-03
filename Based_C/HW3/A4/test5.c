#include <stdio.h>
#include <locale.h>
int a, b, c;
int main(void)

{
	//setlocale(LC_ALL, "Rus");
	//printf("Введите три целых числа:\n");
	scanf("%d%d%d",&a, &b, &c);
	
	int sum = a+b+c;
	int p = a*b*c;
	printf ("%d+%d+%d=%d\r\n", a, b, c, sum);
	printf ("%d*%d*%d=%d\r\n", a, b, c, p);
	
	return 0;
}

