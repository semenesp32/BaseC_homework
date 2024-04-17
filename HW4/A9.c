//Найти наибольшее из пяти чисел
#include <stdio.h>
int a, b, c, d, f, max;

int main(void)

{
	scanf("%d%d%d%d%d",&a, &b, &c, &d, &f);
	max = a > b ? a:b;
	max = max > c ? max:c;
	max = max > d ? max:d;
	max = max > f ? max:f;
	printf("%d", max);
	
	return 0;
}
