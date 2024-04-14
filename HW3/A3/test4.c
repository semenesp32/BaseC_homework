#include <stdio.h>
#include <locale.h>
int a, b, c;
int main(void)

{
	//setlocale(LC_ALL, "Rus");
	//printf("Введите три целых числа:\n");
	scanf("%d%d%d",&a, &b, &c);
	//scanf("%d",&b);
	//scanf("%d",&c);
	
	int sum = a+b+c;
	printf ("%d+%d+%d=%d\n", a, b, c, sum);
	
	return 0;
}

