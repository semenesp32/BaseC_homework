#include <stdio.h>
#include <locale.h>
int a, b;
int main(void)

{
	//setlocale(LC_ALL, "Rus");
	//printf("Введите два целых числа:\n");
	scanf("%d%d",&a, &b);
	
	int r = a-b;
	printf("%d\n",r);
	//printf ("%d-%d=%d\r\n", a, b, r);
	
	return 0;
}

