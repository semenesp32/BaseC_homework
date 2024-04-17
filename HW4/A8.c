//Найти наибольшее из трех чисел
#include <stdio.h>
int a, b, c, max;

int main(void)

{
	scanf("%d%d%d",&a, &b, &c);
	max = a > b ? a:b;
	max = max > c ? max:c;
	printf("%d", max);
	
	return 0;
}
